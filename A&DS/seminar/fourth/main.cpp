#include <iostream>
#include <cstdlib>
#include <cstdio>
//#include <algorithm>
//#include <cmath>
#include <string>
#include <vector>
//#include <stack>
//#include <queue>

using namespace std;
vector<string> mas;
string creatStr()
{
    string tmp;
    for(int i = 0; i < 7; i++)
        if(rand() % 2 == 0)
            tmp += rand() % 26 + 97;
        else
            tmp += rand() % 10 + 48;
    return tmp;
}

int main()
{
    srand(time(0));
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        mas.push_back(creatStr()); 
    for(int i = 0; i < n; i++)
        printf("%s ", mas[i].c_str());
    printf("\n");
    //---------------------------------
    n--;
    for(int i = 6; i >= 0; i--)
    {
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n - i; k++)
                if(mas[k][i] > mas[k + 1][i])
                    swap(mas[k], mas[k + 1]);
    }
    n++;
    //---------------------------------
    for(int i = 0; i < n; i++)
        printf("%s ", mas[i].c_str());
    return 0;
}
