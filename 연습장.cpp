#include <stdio.h>
 
int main() {
    int age;
    double weight;
    char alpha;
    
    printf("나이를 입력해주세요.");
    scanf("%d", &age);
 
    printf("몸무게를 입력해주세요.");
    scanf("%lf", &weight);
 
    printf("좋아하는 알파벳 1글자를 입력해주세요.");
    scanf("%c", &alpha);
    
    printf("나이 = %d\n", age);
    printf("몸무게 = %lf\n", weight);
    printf("좋아하는 알파벳 = %c\n", alpha);
 
    return 0;
}