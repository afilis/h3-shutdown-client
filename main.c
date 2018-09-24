/*

test

*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "arisc.h"


/// messages types
enum
{
    SHUTDOWN_WDT_TOUCH = 0x40,
};

#ifdef DEBUG
struct debug_data_t
{
    uint32_t counter;           // current ticks count
    uint32_t need_to_stop;      // is set when time limit exceeded
};
#endif



static void watchdog_touch(void)
{
    msg_send(SHUTDOWN_WDT_TOUCH, (uint8_t*) 0, 0, 0);

#ifdef DEBUG
    struct debug_data_t rx;

    // finite loop, only 999999 tries to read an answer
    uint32_t n = 0;
    for ( n = 999999; n--; )
    {
        if ( msg_read(SHUTDOWN_WDT_TOUCH, (uint8_t*)&rx, 0) < 0 ) continue;
        else
        {
            printf("counter = %u, need_to_stop = %s\n",
                rx.counter, rx.need_to_stop ? "true" : "false");
            break;
        }
    }
#endif
}


// main entry

int main(int argc, char *argv[])
{
    mem_init();

    for (;;)
    {
        watchdog_touch();
        sleep(1);
    }

    mem_deinit();

    return 0;
}
