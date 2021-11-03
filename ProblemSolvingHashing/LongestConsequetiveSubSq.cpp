#include <bits/stdc++.h>
using namespace std;

int longest(int *arr, int n)
{
    unordered_set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    int max_streak = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i] - 1) == s.end())
        {
            int next_no = arr[i] + 1;
            int streak_len = 1;
            while (s.find(next_no) != s.end())
            {
                next_no += 1;
                streak_len += 1;
            }
            max_streak = max(streak_len, max_streak);
        }
    }

    return max_streak;
}

int main()
{
    int arr[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << longest(arr, n);

    return 0;
}