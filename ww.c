#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char version[] = "v0.0.1";

struct argument {
    char short_flag[2];
    char full_flag[16];
    unsigned int values;
};

const struct argument general[] = {
    { "",   "version",  0 },
    { "v",  "verbose",  0 },
    { "h",  "help",     0 },
};

const struct argument backlight[] = {
    { "b", "brightness", 1 },
};

const char* usage = "My name is Wentworth but you can call me W.\n\n"
    "GENERAL\n"
    "wwctl   , --version        : display version\n";
    "      -v, --verbose        : print all messages\n"
    "\n"
    "BACKLIGHT\n"
    "wwctl bl -b <brightness>   : percent (%), adjustment (+/-), percise (of 255)\n"
    "\n"
    "CONFIG FILES\n"
    "wwctl cf --alacritty       : check if symlinked, if not, symlink\n"
    "         --sway            : check if symlinked, if not, symlink\n"
    "         --vim             : check if symlinked, if not, symlink\n";

int is_short_flag(char* term) {
    const size_t l = strlen(term);
    if (l <= 1)
        return false;
    if (term[0] != '-')
        return false;
    for (int i = 1; i < l; i++) {
        if (!isalpha(term[i]))
            return false;
    }
    return true;
}

int is_long_flag(char* term) {
    const size_t l = strlen(term);
    if (l <= 3)
        return false;
    if (strncmp(term, "--", 2) != 0)
        return false;
    for (int i = 1; i < l; i++) {
        if (!isalpha(term[i]) && term[i] != '-')
            return false;
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc == 0) {
        printf("Hmmm. not sure how you accomplished that.\n");
        return EXIT_FAILURE;
    }

    if (argc == 1) {
        printf("Hi, my name is wentworth, but you can call me W.\n%s\n", version);
        return EXIT_SUCCESS;
    }

    /* backlight */
    if (strncmp(argv[1], "bl", 2) == 0) {
        const int argv_adj = 2;
        if (argc >= argv_adj + 1) {
            for (int i = 0; i < (sizeof(backlight) / sizeof(backlight[0])); i++) {
                
            }
        }
    }

    return EXIT_SUCCESS;
}
