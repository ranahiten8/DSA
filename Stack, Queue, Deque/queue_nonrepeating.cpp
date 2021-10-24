#include<iostream>
#include<queue>
using namespace std;
//print the non repeating characters in running stream of characters

int main()
{
    queue<char> q;
    char ch;
    cin>>ch;
    int freq[27]={0};
    while (ch!='.')
    {
        q.push(ch);
        freq[ch-'a']++;
        while (!q.empty())
        {
            int index=ch-'a';
            if(freq[index]>1)
            {
                q.pop();
            }
            else
            {
                cout<<q.front()<<endl;
                break;
            }
        }
        if(q.empty())
        {
            cout<<"-1"<<endl;
        }
        cin>>ch;
    }
    
    return 0;
}