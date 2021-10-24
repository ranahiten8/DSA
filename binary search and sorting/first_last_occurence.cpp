#include <iostream>
using namespace std;

//first and last occurence of a key in a sorted array
int first_occurence(int a[],int n,int key)
{
    int s = 0;
    int ans;
    int e = n - 1;
    int mid = (s + e) / 2;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (key == a[mid])
        {
            //for first occurence go left
            e = mid - 1;
            ans = mid;
        }
        else if (a[mid] > key)
        {
            e = mid - 1;
        }
        else if (a[mid] < key)
        {
            s = mid + 1;
            
        }
    }
    return ans;
}

int last_occurence(int a[],int n,int key)
{
    int s = 0;
    int ans;
    int e = n - 1;
    int mid = (s + e) / 2;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (key == a[mid])
        {
            //for last occurence go right
            s = mid + 1;
            ans = mid;
        }
        else if (a[mid] > key)
        {
            e = mid - 1;
        }
        else if (a[mid] < key)
        {
            s = mid + 1;
            
        }
    }
    return ans;
}
int main()
{
    int a[100], n, key;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> key;

    cout<<"first occurence is at:"<<first_occurence(a,n,key)<<endl;
    cout<<"last occurence is at:"<<last_occurence(a,n,key)<<endl;
}