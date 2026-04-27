/*
 * C++ Program to Traverse a Graph using DFS
 */
#include <iostream>
#include <conio.h>
using namespace std;
int c = 0;
struct node
{
    char data;
    int st_time, lv_time;
}*p = NULL, *r = NULL;
struct stack
{
    node *pt;
    stack *next;
}*top = NULL, *q = NULL, *np= NULL;
void push(node *ptr)
{
    np = new stack;
    np->pt = ptr;
    np->next = NULL;
    if (top == NULL)
    {
        top = np;
    }
    else
    {
        np->next = top;
        top = np;
    }
}
node *pop()
{
    if (top == NULL)
    {
        cout<<"underflow\n";
    }
    else
    {
        q = top;
        top = top->next;
        return(q->pt);
        delete(q);
    }
}
void create(int a[], int b[][7], int i, int j)
{
    c++;
    p = new node;
    cout<<"enter data for new node\n";
    cin>>p->data;
    p->st_time = c;
    cout<<"start time for "<<p->data<<" is "<<c<<endl;
    a[i] = 1;
    push(p);
    while (j < 7)
    {
        if ((b[i][j] == 0) || (b[i][j] == 1 && a[j] == 1))
        {
            j++;
        }
        else if (b[i][j] == 1 && a[j] == 0)
        {
            create(a,b,j,0);
        }
    }
    r = pop();
    cout<<"node popped\n";
    c++;
    cout<<"leave time for "<<r->data<<" is "<<c<<endl;
    return;
}
int main()
{
    int a[7];
    for (int i = 0; i < 7; i++)
    {
        a[i] = 0;
    }
    int b[7][7];
    cout<<"enter values for adjacency matrix"<<endl;
    for (int i = 0 ; i < 7 ; i++ )
    {
        cout<<"enter values for "<<(i+1)<<" row"<<endl;
        for (int j = 0; j < 7; j++)
        {
            cin>>b[i][j];
        }
    }
    create(a,b,0,0);
    getch();
}
