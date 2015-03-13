#include <iostream>
#include <cstdlib>
#include <cstdio>
//#include <algorithm>
//#include <cmath>
#include <cstring>
//#include <vector>
//#include <stack>
//#include <queue>

using namespace std;

typedef struct node {
    char a; 
    node *next;
} Node;

Node *Add(Node *Top, char d)
{
    Node *newel = new Node;
    newel->a = d;
    newel->next = Top;
    return newel;
}
char Delete(Node **Top)
{
    if((*Top) != NULL)
    {
        char d = (*Top)->a;
        Node *tmp = *Top;
        *Top = (*Top)->next;
        delete tmp;
        return d;
    }
    else
        return '(';
}
bool reserve(char t)
{
    char r[] = "()/*-+";
    for(int i = 0; r[i] != '\0'; i++)
        if(t == r[i]) return true;
    return false;
}
bool pr(char o, char t)
{
    if(o == '*' || o == '/') 
        return true;
    else 
        if(t == '+' || t == '-')
            return true;
        else
            return false;
    return false;
}
void Translate(char *infix, char *postfix)
{
    Node *top = NULL;
    top = Add(top, '(');
    char tmp;
    bool flag = false;
    for(int i = 0; i < strlen(infix); i++)
    {
        if(!reserve(infix[i]))
            sprintf(postfix, "%s%c", postfix, infix[i]);
        else
        {
            if(!flag)
            {
                if(infix[i] == '(')
                {
                    flag = true;
                    top = Add(top, infix[i]);
                    continue;
                }
                if(top->next == NULL)
                    top = Add(top, infix[i]);
                else
                {
                    while(pr(top->a, infix[i]) && top->next != NULL)
                    {
                        tmp = Delete(&top);
                        sprintf(postfix, "%s%c", postfix, tmp);
                    }
                    top = Add(top, infix[i]);
                }
            }
            else 
            {
                if(infix[i] != ')')
                    top = Add(top, infix[i]);
                else
                {
                    tmp = Delete(&top);
                    while(tmp != '(')
                    {
                        sprintf(postfix, "%s%c", postfix, tmp);
                        tmp = Delete(&top);
                    }
                    if(top->next == NULL)
                        flag = false;
                }
            }
        }
        if(i + 1 == strlen(infix))
        {
            tmp = Delete(&top);
            while(tmp != '(')
            {
                sprintf(postfix, "%s%c", postfix, tmp);
                tmp = Delete(&top);
            }
        }

    }
}
int main()
{
    FILE *in  = fopen("input", "r");
    FILE *out = fopen("output", "w");
    char infix[255];
    char postfix[255] = "";
    int a;
    while(!feof(in))
    {
        a = fscanf(in, "%s", infix);
        if(a != 1) break;
        for(int i = 0; i < 255; i++)
            postfix[i] = '\0';
        Translate(infix, postfix);
        fprintf(out, "%s -> %s\n", infix, postfix);
    }
    return 0;
}
