#include<stdio.h>
int main(){
    int day;
    printf("ENter the no of days that you have extended: ");
    scanf("%d",&day);
    if(day >=1 && day<=5){
        printf("The fine you have charged 50 paisa");
    }
    else if(day >=6 && day<=10){
        printf("The fine you have charged 1rs.");
    }
    else if(day >=1 && day<30){
        printf("The fine you have charged 5 rs.");
    }
    else{
        printf("Membership will be cancelled");

    }
}


