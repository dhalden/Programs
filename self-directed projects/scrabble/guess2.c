
oooo






#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]){
    //insert code here...
    int random = rand() % 100;
    random++;
    char input[10];
    char anewline[5];
    int guess = -1;
    while(random != guess){
        printf("\n\nguess the number: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%[^\n]%[\n]", input, anewline);
        guess = atoi(input);
        if(guess >  random){
            printf("\nthat number was too high!");
        }
        else if(guess <  random){
            printf("\nthat number was too low!");
        }
    }
    printf("\nyou guessed it! congratulations!");
return 0;
}
