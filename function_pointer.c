#include <stdio.h>
 
#define MAX_NUMBER 999
 
typedef void (*IntToVoid)(int);
typedef int  (*IntToInt)(int);
 
/* arr의 각 원소를 f에 넣어 실행 (반환 없음) */
void forEach(const int *arr, int n, IntToVoid f)
{
    int index;
    for (index = 0; index < n; index++)
        f(arr[index]);
}
 
/* a의 각 원소를 f에 넣어 실행하고 결과를 out에 담음 */
void map(const int *a, int n, int *out, IntToInt f)
{
    int index;
    for (index = 0; index < n; index++)
        out[index] = f(a[index]);
}
 
void printItemPerLine(int value) { printf("%d\n", value); }
int  squareOf(int value)         { return value * value; }
 
int main()
{
    int naturalNumbers[MAX_NUMBER];
    int squaredNumbers[MAX_NUMBER];
    int index;
 
    /* 반복문은 이 부분에서만 사용 가능 */
    for (index = 0; index < MAX_NUMBER; index++)
        naturalNumbers[index] = index + 1;
 
    map(naturalNumbers, MAX_NUMBER, squaredNumbers, squareOf);   /* (1) 제곱한 새 배열 만들기 */
    forEach(squaredNumbers, MAX_NUMBER, printItemPerLine);       /* (2) 한 줄에 하나씩 출력 */
    return 0;
}
 
