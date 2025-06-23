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

//practice1;
int main(){
    float e = 2.718;
    float x = 8/3; //2
    x+=e;
    char c='A'+x; //65+4.7 = 69
    printf("%c\n",c);//'E'
    return 0;
}

//practice2;
void foo(int *p){
    p = NULL;
}

int main(){
    int x=2;
    int *p=&x;
    foo(p); //Does not change p
    printf("%d\n",*p); //2
    return 0;
}
