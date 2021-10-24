#include<iostream>
using namespace std;

// best case O(nlogn) worst O(n^2) avg O(nlogn)
int partition(int *a,int s,int e)
{
    //inplace(cant take extra array i.e. we dont need extra space or array)
    int i=s-1;
    int j=s;
    int pivot=a[e];

    /*this loop divides the array into 2 regions and places the pivot element at correct
     position*/
    while(j<=e-1)
    {
        if(a[j]<=pivot)
        {
            //merge the smaller element in the region 1
            i++;
            swap(a[i],a[j]);
        }
        //expand the larger region
        j++;
    }

    //place the pivot element in the correct index
    swap(a[i+1],a[e]);
    return i+1;//returns pivot element index so that we can divide again from that index
}

void quicksort(int*a,int s,int e)
{
    //base case
    if(s>=e)
    {
        return ;
    }

    //recursive case
    int p=partition(a,s,e);
    //for left part 
    quicksort(a,s,p-1);
    //for right part
    quicksort(a,p+1,e);

}

int main()
{
    int a[]={2,7,8,6,1,5,4};
    int n=sizeof(a)/sizeof(int);
    quicksort(a,0,n-1);
    //print array
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<",";
    }
    cout<<"END";
    return 0;
}