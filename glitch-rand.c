#include "glitch-rand.h"

static GlitchRandFunc     g_rand_func = rand;
static GlitchRandSeedFunc g_seed_func = srand;

void glitch_rand_set_rand_func(GlitchRandFunc rand_func) {
    g_rand_func = rand_func;
}

void glitch_rand_set_seed_func(GlitchRandSeedFunc seed_func) {
    g_seed_func = seed_func;
}

void glitch_rand_set_seed(unsigned int seed) {
    g_seed_func(seed);
}

int glitch_rand_range_int(int min, int max) {
    return ((g_rand_func() % ((max) - (min) + 1)) + (min));
}

float glitch_rand_range_float(float min, float max) {
    return ((min) + ((float)g_rand_func() / (float)RAND_MAX) * ((max) - (min)));
}
