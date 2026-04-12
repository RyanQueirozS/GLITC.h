/** Copyright 2022 Ryan Queiroz <ryanqueiroz@proton.me>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * How to use the library:
 *
 * #define GLITCH_STD
 * #include "path-to/glitc.h"
 */
#ifndef GLITCH_H
#define GLITCH_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef GLITCH_DEV
 #define GLITCH_STD
#endif // GLITCH_DEV

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

// The max value of successes and/or errors. Redefine if needed and include the
// header after.
#ifndef GLITCH_MAX_ERRORS
 #define GLITCH_MAX_ERRORS 0x1000
#endif // GLITCH_MAX_ERRORS

typedef struct GlitchTester GlitchTester; // Struct that shouldn't be created by the user

GLITCH_DEF GlitchTester* glitch_tester_new();

GLITCH_DEF void glitch_print_passed(GlitchTester* t, bool enable);

GLITCH_DEF void glitch_end(GlitchTester* t);

GLITCH_DEF void glitch_check_condition(bool condition, GlitchTester* t,
                                       char* func, char* file, int line,
                                       const char* description);

#ifndef GLITCH_ASSERT
 #define GLITCH_ASSERT(tester, condition, description)                                                \
     do {                                                                                             \
         glitch_check_condition(condition, tester, (char*)__func__, __FILE__, __LINE__, description); \
     } while (0);
#endif // GLITCH_ASSERT

#endif
