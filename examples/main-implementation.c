#define GLITCH_STD
#define GLITCH_COMPLEX
#define GLITCH_CLOCK
#include "../glitc-clock.h"
#include "../glitc-complex.h"
#include "../glitc.h"

int main(void) {
    GlitchTester* t = glitch_Tester_New();

    // Initialize the clock
    glitch_Clock_Begin();

    // Can define a vec2 like this:
    GLITCH_CMPX_VEC2(a);
    a[0] = 0;
    a[1] = 0;
    // or like this:
    float b[2] = {0, 0};

    GLITCH_ASSERT(t, glitch_Cmpx_Vec2_Is_Equal(a, b), NULL); // No description
                                                             //
    // End the clock
    glitch_Clock_End();
    GLITCH_ASSERT(t, glitch_Clock_Get_Elapsed_MS() < 1, "My description");
    glitch_End(t);
}
