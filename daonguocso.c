#include <stdio.h>

int Reverse(int n){
    
    int reNum = n % 10; // B1: L?y ch? s? cu?i c�ng
    n /= 10; // B? ch? s? cu?i c�ng
    int last;
    while(n > 0){
        last = n % 10; // L?y ch? s? cu?i c�ng
        n /= 10; // B? ch? s? cu?i c�ng
        reNum = reNum * 10 + last; // Ch�nh l� c�c bu?c 2 3 4
    }
    return reNum;
}
 
int main(){
    int num;
    printf("Nhap num = ");
    scanf("%d", &num);
    printf("\nReNum = %d", Reverse(num));
}
