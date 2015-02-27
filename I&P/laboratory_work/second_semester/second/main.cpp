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

void showFile(char *name)
{
    FILE *f = fopen(name, "rb"); 
    double a;

    printf("\n%s\n", name);

    for(int i = 1; !feof(f); i++)
    {
        if(fread(&a,sizeof(double),1,f) != 1) break;
        printf("%8.3lf ", a);
        if(i % 15 == 0)
            printf("\n"); 
    }

    fclose(f);
}

void createFile(char *name)
{
    
    FILE *f = fopen(name, "wb"); 
    int n = rand() % 100 + 1;
    double a;

    for(int i = 0; i < n; i++)
    {
        a = (rand() % 100 - rand() % 100) / (rand() % 19 + 1.);
        fwrite(&a,sizeof(double),1,f);
    }

    fclose(f);
    showFile(name);
}

bool odd(int n)
{
    return n % 2 == 0;
}

void myFilter(FILE *f, FILE *tmp, bool ch, bool od)
{
    int chI, odI;
    if(ch)
        chI = 1;
    else
        chI = -1;

    double a;
    int aa;

    while(!feof(f))
    {
        if(fread(&a,sizeof(double),1,f) != 1) break;
        aa = a;
        if(a * chI >= 0 && odd(aa) == od)
            fwrite(&a,sizeof(double),1,tmp);
    }

    fseek(f,0,SEEK_SET);
}

void workFunc(char *name)
{
    char tmpName[32] = "tmpFile";
    FILE *f = fopen(name, "rb"); 
    FILE *tmp = fopen(tmpName, "wb");

    myFilter(f, tmp, true, true);
    myFilter(f, tmp, true, false);
    myFilter(f, tmp, false, true);
    myFilter(f, tmp, false, false);
    
    fclose(f);
    fclose(tmp);

    //showFile(tmpName);

    remove(name);
    rename(tmpName, name);

    showFile(name);
}

int main()
{
    srand(time(NULL));
    char fileName[32] = "doubleNumbers";
    createFile(fileName);
    workFunc(fileName);
    return 0;
}
