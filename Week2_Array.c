#include <stdio.h>

// int x = 1;

int main(){
    // int x = 10;
    // int x = 100; (syntax error)
    // for(int i = 0;i<10;i++){
    //     int x = 100;
    //     printf("%d\n",x);
    // }
    // return 0;
    array1();
}

int error_exmp_1(){
    int x = 10;
    // int x = 100; (syntax error)
    for(int i = 0;i<10;i++){
        int x = 100;
        printf("%d\n",x);
    }

    return 0;
}

int error_exmp_2(){
    for(int i = 0;i<10;i++){
        int x = 100;
    }
    //printf("%d\n",x); (undeclear x)
}

int array(){
    int a[100];
    for(int i = 0; i<100; i++){
        a[i] = i*2;
    }
    a[100] = 1000; //not error; undefined behaviour
    return 0;
}

void array1(){
    char a[6];
    a[0] = 'H';
    a[1] = 'E';
    a[2] = 'L';
    a[3] = 'L';
    a[4] = 'O';
    a[5] = '\0';


    printf("%s\n",a);
}






