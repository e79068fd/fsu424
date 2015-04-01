#include <iostream>
#include <cstdlib>
#include <cstdio>
//#include <algorithm>
//#include <cmath>
#include <cstring>
#include <string>
//#include <vector>
//#include <stack>
//#include <queue>

using namespace std;


typedef struct node {
    int a; 
    node *next;
} Node;

Node *queue1 = NULL;
Node *q1 = NULL;
Node *queue2 = NULL;

Node *Add(Node *Top, int d)
{
    Node *newel = new Node;
    newel->a = d;
    newel->next = Top;
    if(!q1) q1 = newel;
    return newel;
}

Node *Prov(Node *q, Node *nEnd)
{
    while(q && q->next != nEnd)
        q = q->next;
    return q;
}

void move(int n)
{
    for(int i = 0; i < n; i++)
        if(queue1)
        {
            q1->next = queue2;
            queue2 = q1;
            q1 = Prov(queue1, q1);
            if(q1) q1->next = NULL;
            else queue1 = NULL;
        }
        else
            break;
}

void show(Node *q)
{
    while(q)
    {
        printf("%d ", q->a);
        q = q->next; 
    }
    printf("\n");
}

Node *parse(Node *q)
{
    int a;
    char *p;
    string str1;
    getline(cin, str1);
    char str[str1.length() + 1];
    strcpy(str, str1.c_str());
    p = strtok(str, " ");
    do {
        if(p) 
        {
            sscanf(p, "%d", &a);
            q = Add(q, a);
        }
        p = strtok('\0', " ");
    } while(p);
    return q;
}
int main()
{
    int n = 6;
    scanf("%d", &n);
    freopen("input", "r", stdin);
    queue1 = parse(queue1);
    queue2 = parse(queue2);
    move(n);
    show(queue1);
    show(queue2);
    return 0; 
}
