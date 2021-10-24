#include <iostream>
#include <vector>
using namespace std;
// Brute Force
void findPrimeFactor(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            // Keep dividing by i till it is divisible
            cout << i << " ";
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }
}

// Optimized
// if we are not able to find a prime factor that is less than root n
// Then whatever number is left , will be prime number in itself;
// Complexity : O(root n)
void findPrimeFactorOptimized(int n)
{
    vector<pair<int, int>> factors;
    int cnt;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }
            factors.push_back(make_pair(i, cnt));
        }
    }

    if (n != 1)
    {
        factors.push_back(make_pair(n, 1));
    }

    for (auto p : factors)
    {
        cout << p.first << "^" << p.second << endl;
    }
}


int main()
{

    int n;
    cin >> n;
    findPrimeFactorOptimized(n);
    return 0;
}