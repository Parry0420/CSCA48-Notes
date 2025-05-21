#include <stdio.h>

//Logical operation
// &&(and); ||(or); !(not)
// %% - prints "%"(note: % is part of the format specifier in C, so we need %)


int main(){
    int x=8;
    if(x%2 == 0 && x>20){
        printf("%d is acceptable\n",x);
        //action(s) to perform if the expression is true
    }
    else{
        //action(s) to perform if the expression is false
        printf("%d is not acceptable", x);
    }
}

int while_loop(){
    int x, count, d;
    x = 7319;
    count = 0;
    d = 2;
    //action(s) to do if the condition is true
    while(d < x){
        //check if d is a divisor of x and print it if so
        if(x%d == 0){
            count++;
            break;
        }
        d++;
        //increment the dvisor
    }
    if(count > 0){
        printf("%d is not prime\n",x);
    }
    else{
        printf("%d is prime\n",x);
    }
    return 0;
}


//undefined behavior
void print(){
    int x=0;
    printf("the number x is %f",x);  //format‐specifier mismatch
}


//assume that num>=2
//return 1 if num is prime and 0 otherwise
int is_prime(int num){
    int d = 2;
    while(d < num){
        if(num%d==0){
            return 0;
        }
        d++;
    }
    return 1;
}

int main(){
    int n =2;
    while(n<=1000){
        if(is_prime(n)==1){
            print("%d\n",n);
        }
        n++;
    }
}


int main(){
    char c;
    for(int n=2;n<=1000;n++){
        if(is_prime(n)==1){
            printf("%d\n",n);
        }
    }
}

i++ and ++i
void increment(){
    int i, a, b;
    // 情况 1：后置递增
    i = 5;
    a = i++;    //先取值后自增
    // 执行顺序：a = 5;  i = 6;

    // 情况 2：前置递增
    i = 5;
    b = ++i;    //先自增后取值
    // 执行顺序：i = 6;  b = 6;
    printf("a = %d, b=%d", a,b); // result: a=5, b=6
}

void increment(int x){
    x++;
}

int main(void){
    int x=3;
    increment(x);
    printf("%d\n",x); // print 3;
    return 0;
}
