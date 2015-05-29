//Создание дерева методом вставки в лист
#include <iostream>

using namespace std;

typedef struct tree
{
    int data;
    tree* left;
    tree* right;
} Tree;

void addT(Tree* t, int data, bool h)
{
    Tree* newel = new Tree;
    (*newel).data = data;
    (*newel).right = NULL;
    (*newel).left = NULL;
    if(h)
        (*t).right = newel;
    else 
        (*t).left = newel;
}
void add(Tree* t, int data)
{
    if((*t).data < data)
    {
        if((*t).right)
            add((*t).right, data);
        else
            addT(t, data, true);
    }
    else
    {
        if((*t).left)
            add((*t).left, data);
        else
            addT(t, data, false);
    }
}

void show(Tree* t, int f, bool h)
{
    if(t == NULL) return;
    cout<<f;
    if(h) cout<<"r:";
    else cout<<"l:";
    cout<<(*t).data<<" ";
    //if(h)
    //    cout<<f<<"r:"<<((*t).(*right))->data<<" ";
    //else
    //    cout<<f<<"l:"<<*((*t)->left)->data<<" ";
    show((*t).right, f + 1, true);
    show((*t).left, f + 1, false);
}

int main()
{
    int tmp, n;
    Tree* t = new Tree;
    cin>>n;
    cin>>tmp;
    (*t).data = tmp;
    (*t).right = NULL;
    (*t).left = NULL;
    for(int i = 0; i < n - 1; i++)
    {
        cin>>tmp;
        add(t, tmp);
    }
    cout<<(*t).data<<" ";
    show((*t).left, 1, false);
    show((*t).right, 1, true);
    return 0;
}
