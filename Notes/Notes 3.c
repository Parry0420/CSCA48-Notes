#include <stdio.h>
void foo1(int *x){
    (*x)++;  // error: *x++
}
void foo2(char *x){
    (*x)++;
}
int main(){
    int n = 5;
    char c = 'A';
    int* p = &n;
    foo1(p);
    foo2(&c);
    printf("n = %d\n",n); //'n=6'
    printf("c = %c\n",c); //'c=B'
    return 0;
}
