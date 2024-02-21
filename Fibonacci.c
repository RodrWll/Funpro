#include <stdio.h>
int readRange(int *start, int *end);
int isFibonacci(int n);
int positionInFibonacci(int n);
int totalFibonacciInRange(int start, int end);
int numberIsSquare(int n);
//int printGraph(int start, int end);

int main()
{
    int start, end;
    int totalFibonacci;
    if(readRange(&start, &end)){
        totalFibonacci=totalFibonacciInRange(start, end);
        if(totalFibonacci == 0){
            printf("There are no Fibonacci numbers in the range entered\n");
        }else if(totalFibonacci > 15){
            printf("The limit of numbers in the range entered has been exceeded\n");
        }else{
            printf("The follow graph shows the number of Fibonacci numbers in the range entered\n");
            //printGraph(start, end);
        }
    }
    return 0;
}
int readRange(int *start, int *end)
{
    printf("Enter the start of the range: ");
    scanf("%d", start);
    printf("Enter the end of the range: ");
    scanf("%d", end);
    if (*start > *end)
    {
        printf("The start of the range must be less than the end of the range\n");
        return 0;
    }else if(*start < 0 || *end < 0){
        printf("The start and end of the range must be positive\n");
        return 0;
    }
    else{
        return 1;
    }
}
int isFibonacci(int n)
{
    //5 * n^2 + 4 or 5 * n^2 - 4 results in a perfect square, n is a Fibonacci number
    //but we'll not use sqrt() function to probe if n is a perfect square
    return numberIsSquare(5 * n * n + 4) || numberIsSquare(5 * n * n - 4);
}
int positionInFibonacci(int n)
{
    //returns the position of the number in the Fibonacci sequence
    int a = 0, b = 1, c = 0;
    int position = 0;
    for (int i = 0; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
        position++;
    }
    return position;
}
int totalFibonacciInRange(int start, int end)
{
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (isFibonacci(i))
        {
            count++;
        }
    }
    printf("%d\n",count);
    return count;
}
int numberIsSquare(int n)
{
    //returns 1 if n is a perfect square, 0 otherwise
    for (int i = 0; i <= n / 2; i++)
    {
        if (i * i == n)
        {
            return 1;
        }
    }
    return 0;
}