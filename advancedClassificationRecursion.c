#include <math.h>

int countDigits(int num) {
    if (num == 0) {
        return 0;
    } else {
        return 1 + countDigits(num / 10);
    }
}

int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * power(base, exponent - 1);
    }
}

int isArmstrong(int num) {
    int numDigits = countDigits(num);
    int originalNum = num;
    int sum = 0;

    while (num != 0) {
        int digit = num % 10;
        sum += power(digit, numDigits);
        num /= 10;
    }

    return sum == originalNum;
}


int reverse(int num, int reversedNum) {
    if (num == 0) {
        return reversedNum;
    } else {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        return reverse(num / 10, reversedNum);
    }
}

int isPalindrome(int num) {
    return num == reverse(num, 0);
}
