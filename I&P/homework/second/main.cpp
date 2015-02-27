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

int main()
{
    struct actor {
        char name[32];
        int count;
    };
    vector <actor> l;
    actor tmp;

    char fileName[32] = "input";
    char fileNameOutput[32] = "output";
    FILE *f = fopen(fileName, "r");
    FILE *fo = fopen(fileNameOutput, "w");
    if(f == NULL)
        printf("Error");
    else
    {
        while(!feof(f))
        {
            if(fscanf(f, "%s%d", &tmp.name, &tmp.count) != 2) break;
            if(tmp.count >= 10000)
                l.push_back(tmp);
        }
        //-------------------
        fprintf(fo,"┌");
        for(int i = 0; i < 16; i++)
            fprintf(fo,"─");
        fprintf(fo,"┬");
        for(int i = 0; i < 28; i++)
            fprintf(fo,"─");
        fprintf(fo,"┐\n");
        //----------------------
        fprintf(fo,"│Имя исполнителя │ Количество проданных дисков│\n");
        //-------------------
        fprintf(fo,"├");
        for(int i = 0; i < 16; i++)
            fprintf(fo,"─");
        fprintf(fo,"┼");
        for(int i = 0; i < 28; i++)
            fprintf(fo,"─");
        fprintf(fo,"┤\n");
        //----------------------
        for(int i = 0; i < l.size(); i++)
            fprintf(fo,"│%15s │ %27d│\n", l[i].name, l[i].count);
        //-------------------
        fprintf(fo,"└");
        for(int i = 0; i < 16; i++)
            fprintf(fo,"─");
        fprintf(fo,"┴");
        for(int i = 0; i < 28; i++)
            fprintf(fo,"─");
        fprintf(fo,"┘\n");
        //----------------------
    }
    fclose(f);
    fclose(fo);
    return 0;
}
