#include <iostream>
using namespace std;

int main(){
    int n,a[100];
    cout<<"Please enter the number of elements in the array ";
    cin>>n;
    cout<<"Please enter the elements in the array ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"The respective subarrays of the above array are: ";

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<a[k]<<",";
            }
            cout<<endl;
        }
    }
    return 0;

}