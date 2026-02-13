#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    // Input
    scanf("%s", str);

    int len = strlen(str);

    // Reverse string
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}
