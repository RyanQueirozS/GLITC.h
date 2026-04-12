#ifndef GLITCH_COMPLEX_H
#define GLITCH_COMPLEX_H

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

#include <stdbool.h>

#ifndef GLITCH_CMPX_VEC
 #define GLITCH_CMPX_VEC

typedef struct {
    float x, y;
} GlitchCmpxVec2;

typedef struct {
    float x, y, z;
} GlitchCmpxVec3;

typedef struct {
    float x, y, z, w;
} GlitchCmpxVec4;
#endif //

GLITCH_DEF bool glitch_cmpx_vec2_is_equal(GlitchCmpxVec2 v1, GlitchCmpxVec2 v2);
GLITCH_DEF bool glitch_cmpx_vec3_is_equal(GlitchCmpxVec3 v1, GlitchCmpxVec3 v2);
GLITCH_DEF bool glitch_cmpx_vec4_is_equal(GlitchCmpxVec4 v1, GlitchCmpxVec4 v2);

#endif // GLITCH_COMPLEX_H
