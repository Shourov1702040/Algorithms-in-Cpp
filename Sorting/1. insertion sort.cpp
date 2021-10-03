//1. Insertion sort:

#include <iostream>
using namespace std;

//Insertion sort sort function
void insertionSort( int A[], int n)
{
    int i,value, index;
    for(i=1 ; i<n ; i++)
    {
        value = A[i];
        index = i;
        while ( index > 0 && A[index -1] > value)
        {
            A[index] = A[index -1];
            index = index -1;
        }
        A[index] = value;
    }
}

void displayArray(int A[],int n)
{
    int i;
    for(i=0; i<n; i++)
        cout<<A[i]<<" ";
    cout<<"\n";
}

int main()
{
    int n,i,e;
    cout<<"enter number of elements\n";
    cin>>n;
    int A[n];
    cout<<"enter elements\n";
    for(i=0; i<n; i++)
        cin>>A[i];

    cout<<"Array before sorting:\n";
    displayArray(A,n);

//calling insertion sort function
    insertionSort(A,n);
    cout<<"Array after sorting:\n";
    displayArray(A,n);

    return 0;
}
