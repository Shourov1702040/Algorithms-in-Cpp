/*
 * C++ Program for Topological Sorting in Graphs
 */
#include <iostream>
#include <conio.h>
using namespace std;
struct node_info
{
    int no;
    int lv_time, st_time;
}*q = NULL, *r = NULL;
struct node
{
    node_info *pt;
    node *next;
}*top = NULL, *p = NULL, *np = NULL;
int c = 0;
void push(node_info *ptr)
{
    np = new node;
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
node_info *pop()
{
    if (top == NULL)
    {
        cout<<"underflow\n";
    }
    else
    {
        p = top;
        top = top->next;
        return(p->pt);
        delete(p);
    }
}
void topo(int *v,int am[][7],int i)
{
    q = new node_info;
    q->no = i;
    q->st_time = c;
    cout<<"start time for node no "<<q->no<<":"<<c<<endl;
    push(q);
    v[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (am[i][j] == 0 || (am[i][j] == 1 && v[j] == 1))
            continue;
        else if(am[i][j] == 1 && v[j] == 0)
        {
            c++;
            topo(v,am,j);
        }
    }
    c++;
    r = pop();
    cout<<"leave time for "<<r->no<<":"<<c<<endl;
    return;
}
int main()
{
    int v[7],am[7][7];
    for (int i = 0; i < 7; i++)
    v[i] = 0;
    for (int i = 0; i < 7; i++)
    {
        cout<<"enter the values for adjacency matrix row:"<<i + 1<<endl;
        for(int j = 0; j < 7; j++)
        {
            cin>>am[i][j];
        }
    }
    topo(v,am,0);
    getch();
}
