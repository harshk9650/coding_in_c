#include<stdio.h>
int main(){
    char ch;
    printf("Enter a charachter: ");
    scanf("%c",&ch);
    if(ch>='A' && ch<='Z'){
        printf("This is big alpha ...");
    }
    else if(ch>='a' && ch<='z'){
        printf("This is small alpha ...");
    }
    else if(ch>='0' && ch<='9'){
        printf("This is big alpha ...");
    }
    else{
        printf("SPecial ch: ");
    }
    
}