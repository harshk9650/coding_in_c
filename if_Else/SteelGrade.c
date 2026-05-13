#include<stdio.h>
int main(){
    int h,t;
    float c;
    scanf("%d",&h);
    scanf("%f",&c);
    scanf("%d",&t);

    if(h>50 && c>0.7 && t>5600){
        printf("Grade 10");
    }
    else if(h>50 && c>0.7){
        printf("Grade b");
    }
    else if(c>0.7 && t>5600){
        printf("Grade c");
    }
    else if(h>50 && t>5600){
        printf("Grade d");
    }
    else if(h>50 ||c>0.7|| t>5600){
        printf("Grade e");
    }else{
        printf("Grade F");
    }
    
}