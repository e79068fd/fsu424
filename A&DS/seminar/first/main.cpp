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
FILE *f;

void funcRand(int *x, int n)
{
    for(int i = 0; i < n; i++)
        x[i] = rand() % 10 - rand() % 10;
    return;
}

void show(int *x, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);
    printf("\n");
    return;
}
void mySort(int *x, int n)
{
    int tmp;
    int sr = 0, pr = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - i - 1; j++)
        {
            sr++;
            if(x[j] > x[j + 1])
            {
                pr++;
                tmp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = tmp;
            }
        }
//    fprintf(f,"%8d %8d %8d\n", n, sr, pr);
    return;
}
void test(int n)
{
    int z[n];
    funcRand(z, n);
    mySort(z, n);
    return;
}
int main()
{
   // srand(time(0));
   // f = fopen("data", "w");
   // fprintf(f, "n sr pr\n");
   // test(50);
   // test(1000);
   // test(10000);

    int n;
    scanf("%d", &n);
    int x[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    mySort(x, n);
    show(x, n);
    return 0;
}
