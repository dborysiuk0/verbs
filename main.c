#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
    FILE *ptr;

    ptr = fopen("verbs.txt", "r");
    if(ptr == NULL){
        printf("can`t open file");
        return 1;
    }

    //change fgets 
    //use debage
    //use malloc, realloc, free
    //get row with words
    int i = 0, row = 0; 
    char ch;
    char ch_for_rows;
    char words[40];
    int var_i = 0;
    int number_row = 0;
    
    while(1){
        ch_for_rows = fgetc(ptr);
        if(ch_for_rows == '\n'){
            number_row++;
        }
        else if(ch_for_rows == EOF){
            number_row++;
            break;
        }
    }
    printf("Number of row:\t%d", number_row);

    int number = rand()%5;
    printf("Random number: %d",number );


    while(!feof(ptr)){
        ch = fgetc(ptr);
        if(ch == '\n'){
            row++; 
            var_i = i;
            i = 0;
        }
        if(row == number){
            words[var_i+1] = '\0';
            break;
        }
        words[i] = ch;
        i++;
    }
    printf("Sentens:\t%s\n", words);

    char words_separate[3][10];
    int j = 0, word_index = 0;
    /*
    for(int i = 0; i <= strlen(words); ++i){
        //if space
        if(words[i] == ' ' || words[i] == '\0'){
            words_separate[word_index][j] = '\0';
            word_index++;
            j=0;
        }
        else{
            words_separate[word_index][j] = words[i];
            j++;
        }
    } 
    */
    
    char *str = words;
    char * pch;
    pch = strtok (str," ");
    while (pch != NULL){
        strcpy(words_separate[word_index++], pch);
        pch = strtok (NULL, " ");
    }

    printf("\nPrint separate words: \n");

    for(int i =0; i < 3; i++){
        printf("%s\t", words_separate[i]);
    }

    fclose(ptr);
    return 0;
}
