// Function prototype for factorial
int factorial(int num);

int isPrime(int num){

for (int i = 2; i <= num/2; i++){
    if(num%i == 0){
        return 0; // not Prime
    }
}

 return 1;

}


int isStrong(int num){
   int original = num;
   int sum = 0;

   while (num > 0)
   {
   int digit = num%10;
    sum += factorial(digit);
    num /= 10;
   }
   
   return (sum == original);
}


int factorial(int num){
    if(num == 0  || num == 1 ){
      return 1;  
    }

    return num * factorial(num - 1);
}

