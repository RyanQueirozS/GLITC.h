# Saci Testing

 * NOTE!
 * If you are using WINDOWS and want to build the library you MUST SPECIFY "BUILD_GLITCH_LIB"
 *
 * GLITCH is divided into sub modules, if you need a new module, use the
 * #define MODULE_NAME
 * before the include. Here is a list of all modules and what they do:
 
Simply copy-paste/download the `saci-tessting.h` file to your project!

# Example

```c
#define GLITCH_IMPLEMENTATION 

#include "path-to/saci-testing.h" // define before including

static void MyTestFunction() {
    GLITCH_PrintPassed(true); // will print the passed tests. Default: false.
    { // Test some functionality
        GLITCH_ClockBegin(); // if you want to begin the clock!
        
        GLITCH_ASSERT(1 > 0, "One should be more than zero"); // SUCCESS
        GLITCH_ASSERT(0 > 1, "One should be less than zero"); // FAIL
    
        GLITCH_ClockEnd();
        GLITCH_ASSERT(GLITCH_GetElapsedTimeMS() < 5, "Should run in less then 5 ms");
    }
    {
        for(int i = 0; i < 10; ++i) {
            GLITCH_ASSERT(i < 5, "Number iteration should be less than 5"); 
            // Should fail 5 times, but because the file, line number and 
            // description is the same, it will only print once
        }
    }
    GLITCH_End(); // Ends the test and prints the results
}
```

You can change the macros:

```c

#define GLITCHEPSILON 1e-8 
// Default: 1e-6

#define GLITCH_VEC3_IS_EQUAL(v1x,v1y,v1z,v2x,v2y,v2z)... 
// Default is: GLITCH_VEC3_IS_EQUAL(v1,v2)

// you can also change GLITCH_VEC2_IS_EQUAL, GLITCH_COLOR_IS_EQUAL,
// GLITCHRAND_RANGE_INT, GLITCHRAND_RANGE_FLOAT

// The GLITCH_ASSERT can also be changed
#define GLITCH_ASSERT(condition)... 
// Default is: GLITCH_ASSERT(condition, description)

#define GLITCH_MAXIMUM 10 // Will only have 10 tests. Will crash if there are more!
// Default: 0x1000.

```
