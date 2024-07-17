//WAP to reverse the words of given string .
#include<stdio.h>
#include<string.h>
void reverse(char *First, char *last){
    char temp;
    while(First < last){
        temp = *First;
        *First++ = *last ;
        *last-- = temp;
        }
    }
void wordsRev(char *str){
    char *first_word = NULL;
    char *temp = str;
    reverse(str, str + strlen(str) - 1);
    while(*temp){
        if(first_word == NULL && *temp !=' '){
            first_word= temp;
        }
        if(first_word && (*(temp + 1) == ' ' || *(temp + 1) == '\0')){
            reverse(first_word, temp);
            first_word = NULL;
        }
        temp++;
    }
}
int main(){
    char str[] ="My Name is Krishna Shukla";
    printf("Original words:%s\n", str);
    printf("\n");
    wordsRev(str);
    printf("Reversed words :%s\n", str);  
    return 0;
}
