#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

void set_raw_mode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
}

int main() {
    char c;
    set_raw_mode();

    while (read(STDIN_FILENO, &c, 1) == 1 && c != '\04') { // Ctrl-D to exit
        printf("%02x\n", c);
    }

    return 0;
}
