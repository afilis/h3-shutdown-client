/**
 * @file    arisc.h
 *
 * @brief   ARISC firmware API header
 *
 * This test program implements an API to ARISC firmware
 */

#ifndef _ARISC_H
#define _ARISC_H

#include <stdint.h>




// public method prototypes

int8_t msg_read(uint8_t type, uint8_t * msg, uint8_t bswap);
int8_t msg_send(uint8_t type, uint8_t * msg, uint8_t length, uint8_t bswap);

void mem_init(void);
void mem_deinit(void);




// public data

#define PHY_MEM_BLOCK_SIZE      4096

#define SRAM_A2_SIZE            (48*1024)
#define SRAM_A2_ADDR            0x00040000 ///< for ARM use 0x00040000
#define ARISC_CONF_SIZE         2048
#define ARISC_CONF_ADDR         (SRAM_A2_ADDR + SRAM_A2_SIZE - ARISC_CONF_SIZE)

#define MSG_BLOCK_SIZE          4096
#define MSG_BLOCK_ADDR          (ARISC_CONF_ADDR - MSG_BLOCK_SIZE)

#define MSG_CPU_BLOCK_SIZE      2048
#define MSG_ARISC_BLOCK_ADDR    (MSG_BLOCK_ADDR + 0)
#define MSG_ARM_BLOCK_ADDR      (MSG_BLOCK_ADDR + MSG_CPU_BLOCK_SIZE)

#define MSG_MAX_CNT             32
#define MSG_MAX_LEN             (MSG_CPU_BLOCK_SIZE / MSG_MAX_CNT)
#define MSG_LEN                 (MSG_MAX_LEN - 4)

#define MSG_RECV_CALLBACK_CNT   32

#pragma pack(push, 1)
struct msg_t
{
    uint8_t length;
    uint8_t type;
    uint8_t locked; // actually not used at this moment
    uint8_t unread;
    uint8_t msg[MSG_LEN];
};
#pragma pack(pop)

#endif
