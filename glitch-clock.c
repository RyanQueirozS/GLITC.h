#include "glitch-clock.h"

GLITCH_DEF clock_t glitch_time_start = 0;
GLITCH_DEF clock_t glitch_time_end   = 0;

void glitch_clock_begin(void) {
    glitch_time_start = clock();
}

void glitch_clock_end(void) {
    glitch_time_end = clock();
}

double glitch_clock_get_elapsed_ms(void) {
    return (double)(1000.0f * (glitch_time_end - glitch_time_start) / CLOCKS_PER_SEC);
}
