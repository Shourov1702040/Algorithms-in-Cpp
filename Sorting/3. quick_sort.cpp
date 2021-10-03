#include<iostream>
using namespace std;

int getPivot(int begin,int end)   //Takes length of array as input and returns the position of the pivot
{
    int len = end-begin;
    if(len < 3)
    {
        return end;
    }
    else
    {
        return 2;
    }
};

void quickSort(int begin, int end, int arr[])
{
    int pivot = arr[getPivot(begin,end)];//get Pivotal value - If I replace this with just 0 then there are no problems...
    int tempLeft = begin, tempRight = end;
    int temp;
    while(tempLeft <= tempRight)
    {
        while(arr[tempLeft] < pivot) //Find a point where there are 2 elements that need to be swapped
        {
            tempLeft++;
        }
        while(arr[tempRight] > pivot)
        {
            tempRight--;
        }
        if(tempLeft <= tempRight)
        {
            temp = arr[tempLeft];//Swap the elements
            arr[tempLeft] = arr[tempRight];
            arr[tempRight] = temp;
            tempLeft++;//Skip these swapped elements in the sort
            tempRight--;
        }
    }
    if (begin < tempRight) //Only recurse lower if the new sub array has a length greater than 1
    {
        quickSort(begin, tempRight, arr);
    }
    if (tempLeft < end)
    {
        quickSort(tempLeft, end, arr);
    }


}

main()
{
    int array[] = {0,4,7,3,1,2,6};
    int length = 7;
    quickSort(0,length-1,array);
}
