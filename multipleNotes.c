#include<stdio.h>
int main(){
    int hundread,fifty,ten, a,b,amount;
    printf("Enter the amount in hundread's: ");
    scanf("%d",&amount);


    hundread=amount/100;
    a=amount%100;

    fifty=a/50;
    b=a%50;

    ten=b/10;

    printf("The notes in Hundread %d\n",hundread);
    printf("The notes in Hundread %d\n",fifty);
    printf("The notes in Hundread %d",ten);



}