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

int main()
{
    int k;
    scanf("%d", &k);
    char name[25] = "array";
    FILE *f = fopen(name, "r");
    if(f == NULL)
        printf("Error");
    else
    {
        int a, n, m, sm = 0;
        fscanf(f, "%d%d", &n, &m);
        for(int i = 0; i < n*m; i++)
        {
            fscanf(f, "%d", &a);
            if(a > k)
                sm += a;
        }
        freopen(name, "a", f);
        fprintf(f, "Сумма элементов, больших %d - %d\n", k, sm);
        fclose(f);
    }
    return 0;
}
