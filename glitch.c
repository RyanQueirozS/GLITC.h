#include "glitch.h"

/* === Base structures === */

struct Error {
    char* function;
    char* file;
    int   line;
    char* description;
};

struct Success {
    char* function;
    char* file;
    int   line;
    char* description;
};

typedef struct GlitchTester {
    bool           print_passed;
    size_t         success_index;
    struct Success successes[GLITCH_MAX_ERRORS];
    size_t         error_index;
    struct Error   errors[GLITCH_MAX_ERRORS];
} GlitchTester;

/* === Static funcs === */

static void glitch_passed(GlitchTester* t, char* func, char* file, int line, const char* description) {
    for (size_t i = 0; i < t->success_index; ++i) {
        struct Success success = t->successes[i];
        if (success.description == description && success.file == file && success.line == line &&
            success.function == func) {
            return;
        }
    }
    t->successes[t->success_index++] = (struct Success){
        .function    = func,
        .file        = file,
        .line        = line,
        .description = (!description ? "\0" : (char*)description),
    };
}

static void glitch_did_not_pass(GlitchTester* t, char* func, char* file,
                                int line, const char* description) {
    for (size_t i = 0; i < t->error_index; ++i) {
        struct Error error = t->errors[i];
        if (error.description == description && error.file == file && error.line == line &&
            error.function == func) {
            return;
        }
    }
    t->errors[t->error_index++] = (struct Error){
        .function    = func,
        .file        = file,
        .line        = line,
        .description = (!description ? "\0" : (char*)description),
    };
}

/* === Header implementation === */

GlitchTester* glitch_tester_new() {
    GlitchTester* t = (GlitchTester*)calloc(1, sizeof(GlitchTester));

    return t;
}

void glitch_end(GlitchTester* t) {
    if (t->print_passed) {
        for (size_t i = 0; i < t->success_index; ++i) {
            struct Success success = t->successes[i];
            printf("\033[1;32m%s:%d - %s\033[0m\n", success.file, success.line,
                   success.description);
        }
    }

    for (size_t i = 0; i < t->error_index; ++i) {
        struct Error error = t->errors[i];
        printf("\033[1;31m%s:%d - %s\033[0m\n", error.file, error.line, error.description);
    }
    printf("\033[0;32mPassed: %lu\033[0m\n", t->success_index);
    printf("\033[0;31mDid NOT pass: %lu\033[0m\n", t->error_index);
}

void glitch_print_passed(GlitchTester* t, bool enable) {
    t->print_passed = enable;
}

void glitch_check_condition(bool condition, GlitchTester* t,
                            char* func, char* file, int line,
                            const char* description) {

    if (condition) {
        glitch_passed(t, func, file, line, description);
    } else {
        glitch_did_not_pass(t, func, file, line, description);
    }
}
