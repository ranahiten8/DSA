// Best : Used when there are lot of values of n/queries to computer prime factors for
#include <iostream>
#include <vector>
using namespace std;

void PrimeSieve(int *p)
{

    // first mark all odd numbers as prime
    for (int i = 3; i < 100000; i += 2)
    {
        p[i] = 1;
    }
    for (long long int i = 3; i < 100000; i += 2)
    {
        if (p[i] == 1)
        {
            for (long long j = i * i; j <= 100000; j = j + i)
            {
                p[j] = 0;
            }
        }
    }
    // Special case
    p[2] = 1;
    p[0] = p[1] = 0;
}

vector<int> factorize(int no, int primes[])
{

    vector<int> factors;
    factors.clear();
    int i = 0;
    int prime = primes[0];

    while (prime * prime <= no)
    {
        if (no % prime == 0)
        {
            factors.push_back(prime);
            while (no % prime == 0)
            {
                no = no / prime;
            }
        }
        // Next iteration
        i++;
        prime = primes[i];
    }

    if (no != 1)
    {
        factors.push_back(no);
    }
    return factors;
}

int main()
{

    int p[100005] = {0};
    PrimeSieve(p);

    int j = 0;
    int primes[100];
    for (int i = 2; i <= 100; i++)
    {
        if (p[i] == 1)
        {
            primes[j++] = i;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int no;
        cin >> no;
        vector<int> factors = factorize(no, primes);
        for (auto p : factors)
        {
            cout << p << " ";
        }
    }

    return 0;
}