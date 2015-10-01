#include <stdio.h>
#include <stdlib.h





:wq

int main(int argc, const char * argv[]){
    int r = rand() % 100;
    char input[10];
    char anewline[5];
    int num = -1;
    while (num != r){
        printf("\n\nguess the number: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%[^\n]%[\n]", input, anewline);
        num = atoi(input);
        if(num > r){
            printf("\nthat number is too high!");
        }
        else if(num < r){
            printf("\nthat number is too low!");
        }
    }
    printf("\n congratulations, you guessed it!");
    return 0;
}
