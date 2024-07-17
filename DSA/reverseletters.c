// WAP reverse the letters of each word without changing the position of word itself.
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void reverse(char *str, int First, int last){
    while(First < last){
        char temp = str[First];
        str[First] = str[last];
        str[last] = temp;
        First++;
        last--;
        }
    }
void lettersofwordsRev(char *str){
    int len = strlen(str);
    int First = 0 ;
    int last;
    for(last=0;last <= len; last++){
        if(str[last] == ' ' || str[last] =='\0'){
                reverse(str ,First, last-1);
                First=last+1;
        }
    }
}
int main(){
    char str[] ="My Name is Krishna Shukla";
    printf("Original string: \n%s", str);
    printf("\n");
    lettersofwordsRev(str);
    printf("Reversed String:\n%s", str);  

    return 0;
}
