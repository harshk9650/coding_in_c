#include<stdio.h>
int main(){
    char sex,ms;
    int age;
    printf("Enter the sex and Marital status: ");
    scanf("%d%c%c");
    if(ms=="M"){
        printf("Insecured\n");
    }
        else{
            if(sex=='M'){
                if(age>30){
                    printf("insecured");
                }else{
                    printf("Not secured");
                }
            }else{
                if(age>25){
                    printf("Driver is insecured");
                }
                else{
                    printf("Not secured");
                }
            }
        }
    
}