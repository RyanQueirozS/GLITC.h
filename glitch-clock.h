#ifndef GLITCH_CLOCH_H

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

 #include <time.h>

GLITCH_DEF void   glitch_clock_begin(void);
GLITCH_DEF void   glitch_clock_end(void);
GLITCH_DEF double glitch_clock_get_elapsed_ms(void);

#endif // GLITCH_CLOCH_H
