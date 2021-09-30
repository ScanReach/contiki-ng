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
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(udp_client_process, ev, data)
{
  static struct etimer periodic_timer;
  static unsigned count;
  static char str[32];
  uip_ipaddr_t dest_ipaddr;

  PROCESS_BEGIN();

  //SRTMEM_Init();
  scanreach_antenna_init();
#ifdef Board_CC1352P_MESHNODE
  system_monitor_init();
#endif
  leds_init();
  ctimer_set(&blink_timer, CLOCK_SECOND >> 4, &blink_callback, NULL);


  /* Initialize UDP connection */
  simple_udp_register(&udp_conn, UDP_CLIENT_PORT, NULL,
                      UDP_SERVER_PORT, udp_rx_callback);

  etimer_set(&periodic_timer, random_rand() % SEND_INTERVAL);
  while(1) {
    PROCESS_YIELD();
    if(etimer_expired(&periodic_timer))
    {
      if(NETSTACK_ROUTING.node_is_reachable() && NETSTACK_ROUTING.get_root_ipaddr(&dest_ipaddr)) {
        /* Send to DAG root */
        LOG_INFO("Sending request %u to ", count);
        LOG_INFO_6ADDR(&dest_ipaddr);
        LOG_INFO_("\n");
        snprintf(str, sizeof(str), "hello %d", count);
        simple_udp_sendto(&udp_conn, str, strlen(str), &dest_ipaddr);
        count++;
      } else {
        LOG_INFO("Not reachable yet\n");
      }
    }

    if (ev == button_hal_release_event)
    {
      latest_button_press = clock_seconds();
    }

    /* Add some jitter */
    etimer_set(&periodic_timer, SEND_INTERVAL - CLOCK_SECOND + (random_rand() % (2 * CLOCK_SECOND)));
  }

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/


