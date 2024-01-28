#include <stdio.h>
#include "NumClass.h"

#define MAX(x,y)((x >= y) ? (x) : (y));
#define MIN(x,y)((x <= y) ? (x) : (y));

void printNumbersInRange(int start, int end) {
    
     printf("The Prime numbers are: ", start, end);
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    printf("The Armstrong numbers are: ", start, end);
    for (int i = start; i <= end; ++i) {
        if (isArmstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("The Strong numbers are: ", start, end);
    for (int i = start; i <= end; ++i) {
        if (isStrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("The Palindrome numbers are: ", start, end);
    for (int i = start; i <= end; ++i) {
        if (isPalindrome(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}


int main(){
    int num1, num2;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    int max = MAX(num1, num2);
    int min = MIN(num1, num2);
    
    printNumbersInRange(min, max);

    return 0;
}


