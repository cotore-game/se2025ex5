#include <stdio.h>

int main() {
    int input;
    if (scanf("%d", &input) != 1) return 1;

    if (input < 2) return 0;

    // 2で割れるだけ割る
    while (input % 2 == 0) {
        printf("2");
        input /= 2;
        if (input > 1) printf(" * ");
    }

    // 3で割れるだけ割る
    while (input % 3 == 0) {
        printf("3");
        input /= 3;
        if (input > 1) printf(" * ");
    }

    for (int i = 5; i * i <= input; i += 6) {
        while (input % i == 0) {
            printf("%d", i);
            input /= i;
            if (input > 1) printf(" * ");
        }

        while (input % (i + 2) == 0) {
            printf("%d", i + 2);
            input /= (i + 2);
            if (input > 1) printf(" * ");
        }
    }

    if (input > 1) {
        printf("%d", input);
    }
    printf("\n");

    return 0;
}
