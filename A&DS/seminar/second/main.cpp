//Сортировка Хоара  с выбором медианного элемента
#include <iostream>
#include <cstdlib>
#include <cstdio>
//#include <algorithm>
//#include <cmath>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>

using namespace std;

void funcRand(int *x, int n)
{
    for(int i = 0; i < n; i++)
        //x[i] = rand() % 10 - rand() % 10;
        x[i] = rand() % 10;
    return;
}

void show(int *x, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);
    printf("\n");
    return;
}
int sr, pr;
void quickSort(int *x, int low, int high)
{
    int i = low, j = high;
    int m = x[low + rand() % (high - low + 1)];
    while(i <= j)
    {
        while(x[i] < m) i++;
        while(x[j] > m) j--;
        sr++;
        if(i <= j) 
        {
            pr++;
            swap(x[i],x[j]);
            i++; j--;
        }
    } 
    if(low < j) quickSort(x, low, j);
    if(high > i) quickSort(x, i, high);
}

void test(FILE *f, int n)
{
    int x[n];
    funcRand(x, n);
    sr = 0; pr = 0;
    quickSort(x, 0, n - 1);
    fprintf(f, "%8d|%8d|%8d\n", n, sr, pr);
}

int main()
{
    srand(time(0));
    FILE *f = fopen("data", "w");
    fprintf(f, "n   sr  pr\n");
    test(f, 50);
    test(f, 1000);
    test(f, 10000);
    return 0;
}
