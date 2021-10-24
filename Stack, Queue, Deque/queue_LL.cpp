#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

class queue
{
private:
    node *head, *tail;
    int ms, cs;

public:
    queue()
    {
        head = tail = NULL;
    }
    void top()
    {
        cout << head->data;
        return;
    }
    bool full()
    {
        return cs == ms;
    }
    void push(int d)
    {
        if (!full())
        {
            if (head == NULL)
            {
                head = new node(d);
                tail = head;
                return;
            }

            node *temp = new node(d);
            tail->next = temp;
            tail = temp;
            cs++;
        }
    }
    bool empty()
    {
        return cs == 0;
    }
    void pop()
    {
        if (!empty())
        {
            head = head->next;
            cs--;
        }
    }
    void print()
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
};

int main()
{
    queue q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        q.push(num);
    }
    q.print();
    return 0;
}