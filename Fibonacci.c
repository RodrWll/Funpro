#include <stdio.h>
int readRange(int *start, int *end);
int isFibonacci(int n);
int positionInFibonacci(int n);
int totalFibonacciInRange(int start, int end);
int numberIsSquare(int n);
void printGraph(int start, int end);

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
            printGraph(start, end);
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
    return numberIsSquare(5 * n * n + 4) || numberIsSquare(5 * n * n - 4) || n == 0 || n == 1;
}
int positionInFibonacci(int n)
{
    //returns the position of the number in the Fibonacci sequence
    int a = 0, b = 1, c = 0;
    int position = 0;
    for (int i = 0; i < n; i++)
    {
        //case pos 0 fib number is 0
        //case pos 1 fib number is 1
        //case pos 2 fib number is 1
        if(c==1){
            position=2;
        }
        c = a + b;
        a = b;
        b = c;
        position++;
        
        if (c == n)
        {
            break;
        }
    }
    return position;
}
int totalFibonacciInRange(int start, int end)
{
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if(i==1){
            count+=2;
        }else if (isFibonacci(i))
        {
            count++;
        }
    }
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
void printGraph(int start, int end)
{
    //prints a graph of the position of the Fibonacci numbers and the Fibonacci numbers in the range
    //firt we need to know the total of Fibonacci numbers in the range
    int totalFibonacci = totalFibonacciInRange(start, end);
    //then we need to know the limit of the graph
    int maxLimit = 0;
    int posmaxLimit = 0;
    int minLimit = 0;
    int posminLimit = 0;
    for (int i = end; i >= start; i--)
    {
        if (isFibonacci(i))
        {
            maxLimit = i;
            posmaxLimit = positionInFibonacci(i);
            break;
        }
    }
    for (int i = start; i <= end; i++)
    {
        if (isFibonacci(i))
        {
            minLimit = i;
            posminLimit = positionInFibonacci(i);
            break;
        }
    }


    printf ("\t"); //"space to position (n):"
    for(int i = 0; i < totalFibonacci; i++){
        printf("\t");
    }
    printf("Fibonacci(n) \n");
    int o=0;
    int m=0;
    int l=totalFibonacci;
    for(int i = maxLimit; i >= 1; i--){
        printf("\t");
        if(isFibonacci(i)){
                o++;           
        }
        for(int j = 0; j < totalFibonacci; j++){   
            if(m!=l-o){
                printf("\t");
                m++;
            }else{
                printf("|\t");
                
            }
        }
        m=0;
            printf("%d\n", i);
    }
    printf("position(n)"); 
    int k= minLimit;
    for(int i = 0; i < totalFibonacci; i++){
        if(k==1 || k==2){
            printf("\t1 o 2");
            k+=2;
        }else{
            printf("\t%d", k);
            k++;
        }       
    }
}