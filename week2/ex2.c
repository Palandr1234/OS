#include <stdio.h>
#include <string.h>

int main(){
    char s[2000], ans[2000];
    printf("Enter the string, please\n");
    gets(s);
    int size = strlen(s);
    for(int i = 0; i < size; i++){
        ans[i] = s[size - i -1];
    }
    ans[size] = '\0';
    printf("Reversed string: %s\n", ans);
    return 0;
}