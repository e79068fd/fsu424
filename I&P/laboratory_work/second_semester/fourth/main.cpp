#include <iostream>
#include <cstdlib>
#include <cstdio>
//#include <algorithm>
//#include <cmath>
#include <cstring>
#include <vector>
//#include <stack>
//#include <queue>

using namespace std;

char central[32];
char red[] = "\033[31m";
char green[] = "\033[32m";
char normal[] = "\033[0m";

void funcRand(vector <vector <pair<int, char *> > > &x, int n)
{
    x.resize(n);
    int num;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            num = rand() % 10 - rand() % 10;
            pair<int, char *> tmp;
            tmp.first = num;
            if(num >= 0)
                tmp.second = red;
            else
                tmp.second = normal;
            x[i].push_back(tmp);
        }
    return;
}

void show(vector <vector <pair<int, char *> > > &x, int n)
{
    printf("%s", central);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%s%2d ", x[i][j].second, x[i][j].first);
        printf("\n%s", central);
    }
    printf("%s\n", normal);
    return;
}

void mySwap(vector <vector <pair<int, char *> > > &x, int n)
{
    vector <vector <pair<int, char *> > > x2;
    x2 = x;
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n; j++) 
            if(x[i][j].first >= 0)
            {
                x[i][j].second = green;
                x[i][j].first = x[i + 1][j].first;
            }
    for(int j = 0; j < n; j++)
        if(x[n - 1][j].first >= 0)
        {
            x[n - 1][j].second = green;
            x[n - 1][j].first = x[0][j].first;
        }
    return;
}

int main()
{
    srand(time(NULL));
    system("clear");
    int n;
    scanf("%d", &n);
    sprintf(central, "\033[%dC", 58 - n);
    vector <vector <pair<int, char *> > > x;

    funcRand(x, n);
    show(x, n);
    mySwap(x, n);
    show(x, n);
    return 0;
}
