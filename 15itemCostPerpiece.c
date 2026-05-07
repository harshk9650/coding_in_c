#include<stdio.h>
int main(){
    float cost,profit,item;
    item=15;
    printf("Cost of 15 item: ");
    scanf("%f",&cost);
    printf("Enter the profit: ");
    scanf("%f",&profit);

    profit=(profit/100)*cost;
    cost=cost+profit;
    item=cost/item;
    printf("The cost of per item is %.1f",cost);

}