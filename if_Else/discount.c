#include<stdio.h>
int main(){
    int price;
    float discount = 10.0;
    float discount_price,final_price;

    printf("Enter the actual price of the item: ");
    scanf("%d",&price);
    if( price>1000){
    discount_price = (price*discount)/100;

    final_price=price-discount_price;

    printf("THe final_amount of the Article is: %.1f",final_price);
    }

}