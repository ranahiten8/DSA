#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    char ch;
    int freq;
    unordered_map<char, node *> m;
    node(char c)
    {
        ch = c;
        freq = 1;
    }
};

class trie
{
    node *root;

public:
    trie()
    {
        root = new node('\0');
        root->freq = 0;
    }
    void insert(string s)
    {
        node *temp = root;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (temp->m.count(ch))
            {
                temp = temp->m[ch];
                (temp->freq)++;
            }
            else
            {
                node *n = new node(ch);
                temp->m[ch] = n;
                temp = n;
            }
        }
    }
    vector<string> prefixes(vector<string> words)
    {
        vector<string> ans;
        for (int i = 0; i < words.size(); ++i)
        {
            string p;
            node *temp = root;
            int j = 0;
            while (j < words[i].size())
            {
                if (temp->freq == 1)
                {
                    ans.push_back(p);
                    break;
                }
                char c = words[i][j];
                p += c;
                temp = temp->m[c];
                j++;
            }
            if (j == words[i].size())
            {
                ans.push_back(p);
            }
        }
        return ans;
    }
};

int main()
{
    vector<string> words = {"cobra", "dog", "dove", "duck","cow"};
    // output[]={c,dog,dov,du}

    trie t;
    for (int i = 0; i < words.size(); ++i)
    {
        t.insert(words[i]);
    }

    vector<string> output = t.prefixes(words);

    for (auto x : output)
    {
        cout << x << " ";
    }
    return 0;
}