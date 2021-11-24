CONTIKI_PROJECT = udp-client udp-server
TARGET = simplelink
BOARD = srt/cc1352p

REPO_ROOT = ../../..
SRT_COMMON_ROOT = $(REPO_ROOT)/srt_common
MESSAGE_TYPES_GEN_ROOT = $(SRT_COMMON_ROOT)/generated/inc
DATA_TYPES_GEN_ROOT = $(SRT_COMMON_ROOT)/generated/inc
CONTIKI=../..
CORE_SDK=$(CONTIKI)/arch/cpu/simplelink-cc13xx-cc26xx/lib/coresdk_cc13xx_cc26xx

#LDSCRIPT := $(REPO_ROOT)/mesh_node/rpl-srt/cc13x2-cc26x2_standalone.lds

all: $(CONTIKI_PROJECT)

.PHONY: GENERATE

# Generate message definitions
GENERATE:
	python -m srt_messages.generator.codegen --protocol serial_v1 c $(MESSAGE_TYPES_GEN_ROOT)
	python -m srt_messages.generator.codegen --protocol network_configuration_v1 --module-prefix SRTMSG_ c $(MESSAGE_TYPES_GEN_ROOT)
	python -m srt_messages.generator.codegen --protocol provision_data_v1 --module-prefix SRTPROV_ c $(DATA_TYPES_GEN_ROOT)


MAKE_MAC = MAKE_MAC_CSMA
MAKE_ROUTING = MAKE_ROUTING_RPL_LITE

MODULES += os/net/ipv6/multicast
MODULES_REL += $(MESSAGE_TYPES_GEN_ROOT)
MODULES_REL += $(REPO_ROOT)/mesh_node/rpl-srt/utils
MODULES_REL += $(REPO_ROOT)/mesh_node/rpl-srt/ota
MODULES_REL += $(REPO_ROOT)/mesh_node/rpl-srt/ota/smartrf_settings
MODULES_REL += $(SRT_COMMON_ROOT)/messagetypes/inc
MODULES_REL += $(SRT_COMMON_ROOT)/serial_messagetypes/inc
MODULES_REL += $(SRT_COMMON_ROOT)/srt_serial/src
MODULES_REL += $(SRT_COMMON_ROOT)/srt_serial/inc
MODULES_REL += $(SRT_COMMON_ROOT)/srt_queue/src
MODULES_REL += $(SRT_COMMON_ROOT)/srt_queue/inc
MODULES_REL += $(SRT_COMMON_ROOT)/srt_mem/src
MODULES_REL += $(SRT_COMMON_ROOT)/srt_mem/inc
MODULES_REL += $(SRT_COMMON_ROOT)/delay/src
MODULES_REL += $(SRT_COMMON_ROOT)/delay/inc
MODULES_REL += $(SRT_COMMON_ROOT)/ota_files/src
MODULES_REL += $(SRT_COMMON_ROOT)/ota_files/inc
MODULES_REL += $(SRT_COMMON_ROOT)/ota_plugin/src
MODULES_REL += $(SRT_COMMON_ROOT)/ota_plugin/inc
MODULES_REL += $(SRT_COMMON_ROOT)/srt_nv/inc
MODULES_REL += $(SRT_COMMON_ROOT)/srt_nv/srt_nv_ti/src
MODULES_REL += $(SRT_COMMON_ROOT)/srt_nv/srt_nv_ti/inc
MODULES_REL += $(SRT_COMMON_ROOT)/ota_frequency/src
MODULES_REL += $(SRT_COMMON_ROOT)/ota_frequency/inc
MODULES_REL += $(SRT_COMMON_ROOT)/crc/inc
MODULES_REL += $(SRT_COMMON_ROOT)/crc/src
MODULES_REL += $(SRT_COMMON_ROOT)/srt_crypto/inc
MODULES_REL += $(SRT_COMMON_ROOT)/srt_crypto/src
MODULES_REL += $(SRT_COMMON_ROOT)/ota_crypto/inc
MODULES_REL += $(SRT_COMMON_ROOT)/ota_crypto/src
MODULES_REL += $(REPO_ROOT)/tweetnacl/test/c/inc
MODULES_REL += $(REPO_ROOT)/tweetnacl/test/c/src
MODULES_REL += $(SRT_COMMON_ROOT)/inc
MODULES_REL += $(CORE_SDK)/source/ti/devices/cc13x2_cc26x2
MODULES_REL += dev/

include $(CONTIKI)/Makefile.include

-include GENERATE #This makes the target run before anything else
