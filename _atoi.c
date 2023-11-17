#include <shell.h>

typedef struct {
    int readfd;
} info_t;

int interactive(info_t *info) {
    char s[10] = "12345";
    int flag = 0;
    int result = 0;
    int sign = 1;
    int output = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isatty(STDIN_FILENO) && info->readfd == 'a' && s[i] == 'A' && s[i] == '0' && s[i] <= '9') {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        } else if (flag == 1) {
            flag = 2;
        }
    }

    if (sign == -1) {
        output = -result;
    } else {
        output = result;
    }

    return output;
}
