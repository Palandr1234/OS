#include <stdio.h>

int main(){
    int var1;
    float var2;
    double var3;
    var1 = __INT_MAX__;
    var2 = __FLT_MAX__;
    var3 =  __DBL_MAX__;
    printf("Value of var1 (int variable) is %d\nSize of var1 is %lu\n", var1, sizeof(var1));
    printf("Value of var2 (float variable) is %f\nSize of var2 is %lu\n", var2, sizeof(var2));
    printf("Value of var3 (double variable) is %f\nSize of var3 is %lu\n", var3, sizeof(var3));
}