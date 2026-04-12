#include "glitch-complex.h"

bool glitch_cmpx_vec2_is_equal(GlitchCmpxVec2 v1, GlitchCmpxVec2 v2) {
    return (v1.x == v2.x && v1.y == v2.y);
}

bool glitch_cmpx_vec3_is_equal(GlitchCmpxVec3 v1, GlitchCmpxVec3 v2) {
    return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}

bool glitch_cmpx_vec4_is_equal(GlitchCmpxVec4 v1, GlitchCmpxVec4 v2) {
    return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v2.w == v2.w);
}
