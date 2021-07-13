#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char version[] = "v0.0.1";

struct argument {
        char group[3];
        char short_flag[2];
        char full_flag[16];
        unsigned int values;
};

const struct argument general[] = {
          /* group */   /* short */     /* long */      /* trailing term count */
        { "",           "",             "version",      0 },
        { "",           "v",            "verbose",      0 },
        { "",           "h",            "help",         0 },
};

const struct argument backlight[] = {
        { "bl",         "b",            "brightness",   1 },
};

const struct argument config[] = {
        { "cf",         "a",            "alacritty",    0 },
        { "cf",         "e",            "environment",  0 },    /* /etc/environment */
        { "cf",         "m",            "mutt",         0 },
        { "cf",         "n",            "npm",          0 },
        { "cf",         "s",            "ssh",          0 },
        { "cf",         "S",            "sway",         0 },
        { "cf",         "V",            "vim",          0 },
        { "cf",         "z",            "zsh",          0 },
};

const struct argument energy[] = {
        { "eg",         "a",            "alsa",         1 },
        { "eg",         "b",            "bluetooth",    1 },
        { "eg",         "i",            "iwd",          1 },
        { "eg",         "w",            "wireguard",    1 },
        { "eg",         "M",            "min-all",      0 },
        { "eg",         "R",            "restore",      0 },
        { "eg",         "S",            "status",       0 },
};

const char* usage = "My name is Wentworth but you can call me W.\n\n"
        "GENERAL\n"
        "wwctl   , --version        : display version\n"
        "      -v, --verbose        : print all messages\n"
        "\n"
        "BACKLIGHT\n"
        "wwctl bl -b <brightness>   : percent (%), adjustment (+/-), percise (of 255)\n"
        "\n"
        "CONFIG FILES\n"
        "wwctl cf --alacritty       : check if symlinked, if not, symlink\n"
        "         --sway            : check if symlinked, if not, symlink\n"
        "         --vim             : check if symlinked, if not, symlink\n"
        "\n"
        "ENERGY MANAGEMENT\n"
        "wwctl eg -a, --alsa [on|off|status]\n"
        "         -b, --bluetooth [on|off|status]\n"
        "         -i, --iwd [on|off|status]\n"
        "         -w, --wireguard [on|off|status]\n"
        "         -M, --min-all     : reduce all services for energy savings\n"
        "         -R, --restore     : restore all stopped services\n"
        "         -S, --status      : list status of affected services\n";

bool is_short_flag(char* term) {
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

bool is_long_flag(char* term) {
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
        if (argc == 1) {
                printf("Hi, my name is wentworth, but you can call me W.\n%s\n", version);
                return EXIT_SUCCESS;
        }

        switch (argc) {
                case 0:
                        printf("Hmmm. not sure how you accomplished that.\n");
                        return EXIT_FAILURE;
                case 1:
                        printf("Hi, my name is Wentworth, but you can call me W.\n%s\n", version);
                        break;
                case 2:
                        break;
        }

        return EXIT_SUCCESS;
}
