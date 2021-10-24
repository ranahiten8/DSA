#include <iostream>
using namespace std;
// Standard Kadane's algorithm to find maximum subarray sum
int kadane(int array[], int n)
{
    int max_so_far = 0, max_ending_here = 0;
    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + array[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

//function to find maximum circular subarray sum
int MaxSumCircular(int array[], int n)
{
    //Max subarray sum in the given array
    int kadane_sum = kadane(array, n);
    //wrap_sum is sum of all elements in the array
    int wrap_sum = 0;
    //find sum of all elements in the array
    //invert signs of all elements in the array
    for (int i = 0; i < n; i++)
    {
        wrap_sum += array[i];
        array[i] = -array[i];
    }
    //update wrap_sum by add to new Max subarray sum
    wrap_sum = wrap_sum + kadane(array, n);
    //Return the maximum of them
    if (wrap_sum > kadane_sum)
    {
        return wrap_sum;
    }
    else
    {
        return kadane_sum;
    }
}

//Main function
int main()
{
    int t, n, input_array[1000];
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> input_array[i];
        }
        cout << "Maximum circular subarray sum: " << MaxSumCircular(input_array, n) << endl;
    }
    return 0;
}