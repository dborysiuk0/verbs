#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
    FILE *ptr;
    int number = 4;

    ptr = fopen("verbs.txt", "r");
    if(ptr == NULL){
        printf("can`t open file");
    }

    //get row with words
    int i = 0, row = 0; 
    char ch;
    char words[40];
    while(!feof(ptr)){
        ch = fgetc(ptr);
        if(ch == '\n'){
            row++; 
            i = 0;
        }
        if(row == number){
            words[i+1] = ' ';
            words[i+2] = ' ';
            break;
        }
        words[i] = ch;
        i++;
    }
    printf("%s\n", words);

    char words_separate[3][10];
    int j = 0, ctr = 0;

    for(int i = 0; i< (strlen(words)); ++i){
        if(ctr == 3){
            break;
        }
        //if space
        if(words[i] == ' '){
            words_separate[ctr][j] = '\0';
            ctr++;
            j=0;
        }
        else{
            words_separate[ctr][j] = words[i];
            j++;
        }
    }
    printf("\nPrint separate words: \n");

    for(int i =0; i < 3; i++){
        printf("%s\t", words_separate[i]);
    }

    fclose(ptr);
    return 0;
}
