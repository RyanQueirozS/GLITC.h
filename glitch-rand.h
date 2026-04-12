#ifndef GLITCH_DEF

 #ifdef _WIN32
  #ifdef BUILD_GLITCH_LIB
   #define GLITCH_DEF __declspec(dllexport) // Export symbols when building the library
  #else
   #define GLITCH_DEF __declspec(dllimport) // Import symbols when using the library
  #endif
 #else
  #define GLITCH_DEF // Non-Windows platforms don't need special decoration
 #endif // _WIN32

#endif // GLITCH_DEF

#include <math.h>
#include <stdlib.h>

typedef int (*GlitchRandFunc)(void);
typedef void (*GlitchRandSeedFunc)(unsigned int);

GLITCH_DEF void glitch_rand_set_rand_func(GlitchRandFunc rand_func);

GLITCH_DEF void glitch_rand_set_seed_func(GlitchRandSeedFunc seed_func);

GLITCH_DEF void glitch_rand_set_seed(unsigned int seed);

GLITCH_DEF int glitch_rand_range_int(int min, int max);

GLITCH_DEF float glitch_rand_range_float(float min, float max);

/* === GLITCH_RAND Implementation === */
