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
void merge(int *x, int first, int m, int last)
{
    int n = last - first + 1;
    int tmp[n];
    int i, j, t;
    for(i = 0; first + i <= m; i++)
        tmp[i] = x[first + i];
    for(j = n - 1; first + j > m; j--)
        tmp[i++] = x[first + j];
    i = 0; j = n - 1;
    for(t = first; t <= last; t++)
    {
        sr++;
        if(tmp[i] <= tmp[j])
        {
            x[t] = tmp[i]; 
            i++;
        }
        else
        {
            x[t] = tmp[j];
            j--;
        }
        pr++;
    }
}
void mergeSort(int *x, int first, int last)
{
    if(last <= first) return;
    int m = (first + last) / 2;
    mergeSort(x, first, m);
    mergeSort(x, m + 1, last);
    merge(x, first, m, last);
}
void test(FILE *f, int n)
{
    int x[n];
    funcRand(x, n);
    sr = 0; pr = 0;
    mergeSort(x, 0, n - 1);
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
    //----------------
    int n = 15;
    int x[n]; 
    funcRand(x, n);
    show(x, n);
    mergeSort(x, 0, n - 1);
    show(x, n);
    return 0;
}
