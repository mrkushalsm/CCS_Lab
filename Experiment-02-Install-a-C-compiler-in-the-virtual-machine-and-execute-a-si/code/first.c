#include<stdio.h>
#include<conio.h>
void main() {
    int a;
    clrscr();
    printf("Enter the number to find Even Or Not");
    scanf("%d",&a);
    if(a%2==0) {
        printf("The Entered number is Even");
    }
    else {
        printf("The Entered number is Odd");
    }
}