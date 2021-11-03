#include <bits/stdc++.h>
using namespace std;

string find_window(string s, string pat)
{
    int SL = s.length();
    int PL = pat.length();
    if (PL > SL)
    {
        return "NONE";
    }

    int FS[256] = {0};
    int FP[256] = {0};

    for (int i = 0; i < PL; i++)
    {
        FP[pat[i]]++;
    }
    int cnt = 0;
    int start = 0;
    int min_len = INT_MAX;
    int start_idx = -1;
    for (int i = 0; i < SL; i++)
    {
        char ch = s[i];
        FS[ch]++;

        //maintain cnt of characters
        if (FP[ch] != 0 && FS[ch] <= FP[ch])
        {
            cnt++;
        }

        if (cnt == PL)
        {
            //shrink window
            char temp = s[start];
            //remove all unwanted character
            while (FP[temp] == 0 or FS[temp] > FP[temp])
            {
                FS[temp]--;
                start++;
                temp = s[start];
            }

            int windowlen = i - start + 1;
            if (windowlen < min_len)
            {
                min_len = windowlen;
                start_idx = start;
            }
        }
    }

    if (start_idx == -1)
    {
        return "None";
    }
    string ans = s.substr(start_idx, min_len);

    return ans;
}

int main()
{
    string s = "hllloeaeo world";
    string p = "eelo";

    cout << find_window(s, p);

    return 0;
}