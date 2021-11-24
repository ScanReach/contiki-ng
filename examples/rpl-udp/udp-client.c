#include "contiki.h"
#include "net/routing/routing.h"
#include "random.h"
#include "net/netstack.h"
#include "net/ipv6/simple-udp.h"

#include "sys/log.h"


#include "leds.h"
#include "delay.h"
#include "scanreach-globals.h"
#include "dev/button-hal.h"
#include "dev/uart-arch.h"
#include "srt_serial.h"

#define LOG_MODULE "App"
#define LOG_LEVEL LOG_LEVEL_INFO

#define WITH_SERVER_REPLY  1
#define UDP_CLIENT_PORT	8765
#define UDP_SERVER_PORT	5678

#define SEND_INTERVAL		  (10 * CLOCK_SECOND)

static struct simple_udp_connection udp_conn;


static struct ctimer blink_timer;
#define LEDS_ACTIVE_DURATION_SEC    60
static uint32_t      latest_button_press = 0;

void blink_callback(void *ptr)
{
  if (clock_seconds() - latest_button_press < LEDS_ACTIVE_DURATION_SEC)
  {
    if (NETSTACK_ROUTING.node_is_reachable())
    {
      leds_single_toggle(LEDS_GREEN);
      leds_single_off(LEDS_RED);
    }
    else
    {
      leds_single_toggle(LEDS_RED);
      leds_single_off(LEDS_GREEN);
    }
  }
  else
  {
    leds_off(LEDS_ALL);
  }

  ctimer_reset(&blink_timer);
}


/*---------------------------------------------------------------------------*/
PROCESS(udp_client_process, "UDP client");
AUTOSTART_PROCESSES(&udp_client_process);
/*---------------------------------------------------------------------------*/
static void
udp_rx_callback(struct simple_udp_connection *c,
         const uip_ipaddr_t *sender_addr,
         uint16_t sender_port,
         const uip_ipaddr_t *receiver_addr,
         uint16_t receiver_port,
         const uint8_t *data,
         uint16_t datalen)
{

  LOG_INFO("Received response '%.*s' from ", datalen, (char *) data);
  LOG_INFO_6ADDR(sender_addr);
#if LLSEC802154_CONF_ENABLED
  LOG_INFO_(" LLSEC LV:%d", uipbuf_get_attr(UIPBUF_ATTR_LLSEC_LEVEL));
#endif
  LOG_INFO_("\n");

}

static SRTSER_Instance_t mNordicUartInstance;
static int nordic_callback(uint8_t inputChar)
{
  SRTSER_ProcessIncomingByte(&mNordicUartInstance, inputChar);
  return 0;
}


static void processNordicMessage(uint8_t *pData, uint8_t length)
{
  uip_ipaddr_t dest_ipaddr;
  if(NETSTACK_ROUTING.node_is_reachable() && NETSTACK_ROUTING.get_root_ipaddr(&dest_ipaddr)) {
        /* Send to DAG root */
        simple_udp_sendto(&udp_conn, pData, length, &dest_ipaddr);
  }
}

static void init_uart_to_nrf52(void)
{
  SRTSER_Init(&mNordicUartInstance, &processNordicMessage, NULL, NULL);
  uart1_init();
  uart1_set_callback(&nordic_callback);
}

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(udp_client_process, ev, data)
{
  PROCESS_BEGIN();
  scanreach_antenna_init();
#ifdef Board_CC1352P_MESHNODE
  system_monitor_init();
#endif
  leds_init();
  init_uart_to_nrf52();
  ctimer_set(&blink_timer, CLOCK_SECOND >> 4, &blink_callback, NULL);
  /* Initialize UDP connection */
  simple_udp_register(&udp_conn, UDP_CLIENT_PORT, NULL,
                      UDP_SERVER_PORT, udp_rx_callback);

  while(1) {
    PROCESS_YIELD();
    if (ev == button_hal_release_event)
    {
      latest_button_press = clock_seconds();
    }
  }

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/


