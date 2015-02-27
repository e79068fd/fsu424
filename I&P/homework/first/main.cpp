#include <iostream>
#include <cstdlib>
#include <cstdio>
//#include <algorithm>
//#include <cmath>
//#include <string>
#include <vector>
//#include <stack>
//#include <queue>

using namespace std;

int main()
{
    struct actor {
        char name[25];
        int count;
    };
    vector <actor> l;
    actor tmp;

    char fileName[32] = "input";
    FILE *f = fopen(fileName, "r");
    if(f == NULL)
        printf("Error");
    else
    {
        while(!feof(f))
        {
            fscanf(f, "%s%d", &tmp.name, &tmp.count);
            if(tmp.count >= 10000)
                l.push_back(tmp);
        }
        for(int i = 0; i < l.size(); i++)
            printf("%d) %s %d\n", i, l[i].name, l[i].count);
    }
    return 0;
}
