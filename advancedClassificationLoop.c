#include <math.h>

int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

int isArmstrong(int num) {
    int numDigits = countDigits(num);
    int originalNum = num;
    int sum = 0;

    while (num != 0) {
        int digit = num % 10;
        sum += pow(digit, numDigits);
        num /= 10;
    }

    return sum == originalNum;
}


int reverse(int num) {
    int reversedNum = 0;
    while (num != 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }
    return reversedNum;
}

int isPalindrome(int num) {
    return num == reverse(num);
}
