#include <iostream>
#include <stack>
using namespace std;

//Stock span problem
void stockSpan(int prices[], int n, int span[])
{
    stack<int> s; //indices of the days
    s.push(0); //for day 0 
    span[0] = 1; //for day 0 span=1

    //loop for the rest of the days
    for (int i = 1; i <= n - 1; i++)
    {
        int currentPrice = prices[i];
        //1st step 
        //topmost element that is higher than current prices
        while (!s.empty() and currentPrice >= prices[s.top()])
        {
            s.pop();
        }

        //2nd step update span array
        if (!s.empty())
        {
            int prev_highest = s.top();
            span[i] = i - prev_highest;
        }
        //if stack gets empty
        else
        {
            span[i] = i + 1;
        }

        //3rd step push the ith(current) element into stack
        s.push(i);
    }
}
int main()
{
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(int);
    int span[100000] = {0}; 
    stockSpan(prices, n, span);
    //print the span
    for (int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
    }
    return 0;
}
