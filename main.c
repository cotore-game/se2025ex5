#include <stdio.h>

int main(){
    int input;
    scanf("%d", &input);

    int devide = 2;
    while(1){
        if(input == 1 || input < 1) break;

        while(input % devide == 0){
            input /= devide;
            printf("%d", devide);

            if(input == 1){
                printf("\n");
                break;
            }else{
                printf(" * ");
            }
        }

        devide++;
    }

    return 0;
}
