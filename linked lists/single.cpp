#include <iostream>
using namespace std;

class node
{
public:
    int data; //data member hota h ye
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

// head is passed by ref so that head changes always
void insertAtHead(node *&head, int data, node *&tail)
{
    if (head == NULL)
    {
        head = new node(data);
        tail = head;
        return;
    }

    //head insertion me last node is first node to get inserted
    node *temp = new node(data);
    temp->next = head; //or (*temp).next = head;
    head = temp;
}

void insertattail(node *head, int data, node *&tail)
{
    if (head == NULL)
    {
        head = new node(data);
        tail = head;
        return;
    }

    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

int length(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void insertATmiddle(node *head, int data, int p, node *tail)
{
    //corner case
    if (head == NULL or p == 0)
    {
        insertAtHead(head, data, tail);
    }
    else if (p > length(head))
    {
        insertattail(head, data, tail);
    }
    else
    {
        //take p-1 jumps
        int jump = 1;
        node *temp = head;
        while (jump <= p - 1)
        {
            temp = temp->next;
            jump++;
        }
        //create a new node
        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

void reverse(node *&head) //pass by reference time O(n) space O(1)
{
    node *c = head; //current node
    node *p = NULL; //previous node
    node *n = NULL; //next node

    while (c != NULL)
    {
        //save next node
        n = c->next;
        //make current node point to prev
        c->next = p;

        //update p and c and take them 1 step forward
        p = c;
        c = n;
    }
    head = p;
}

void recursiveReverse(node *&head, node *p, node *c, node *n) //time O(n) space O(n)
{
    if (c == NULL)
    {
        head = p;
        return;
    }

    //save next node
    n = c->next;
    //make current node point to prev
    c->next = p;

    //update p and c and take them 1 step forward
    p = c;
    c = n;

    recursiveReverse(head, p, c, n);
}

node *midpoint(node *head) //midpoint runner technique to find midpoint
{
    if (head == NULL or head->next == NULL) //fast=head->next so it cant be NULL
    {
        return head;
    }

    //2 pointers ek slow bhagega dusra double speed se bhagega
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL and fast->next != NULL) // because fast->next->next will
                                                // lead to segmentation fault if not checked for null
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow; //ye midpoint dega
}

void deleteAtHead(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head->next;
    delete head;
    head = temp;
}

node *merge(node *a, node *b) // sorted linked list honi chahiye
{
    //base case
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    //take a new head ptr
    node *temp; //new head ptr
    if (a->data < b->data)
    {
        temp = a;
        temp->next = merge(a->next, b);
    }
    else
    {
        temp = b;
        temp->next = merge(a, b->next);
    }
    return temp;
}

node *mergesort(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    //rec case
    //1. break
    node *mid = midpoint(head);
    node *a = head;
    node *b = mid->next;

    mid->next = NULL;

    //2. rec sort 2 parts
    a = mergesort(a);
    b = mergesort(b);

    //3. merge them
    node *c = merge(a, b);
    return c;
}

void detectandremovecycle(node *head) //floyd cycle technique
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            if (fast == head) //corner case when fast==slow==head meaning it is a circular LL
            {
                cout << "Yes there is a loop! " << endl;
                node *temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = NULL;
                cout << "Loop removed succesfuly! " << endl;
            }
            else
            {
                cout << "Yes there is a loop! " << endl;
                slow = head;
                while (slow->next != fast->next) //same speed se iterate kro
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                fast->next = NULL; //removed successfuly
                cout << "Loop removed succesfuly! " << endl;
            }
            return;
        }
    }
}

void print(node *head) // pass by value so that original head can be retained
{
    while (head != NULL)
    {
        cout << head->data << " => ";
        head = head->next;
    }
}

ostream &operator<<(ostream &os, node *head)
{
    print(head);
    return os;
}

istream &operator>>(istream &is, node *&head)
{
    head = NULL;
    int n, num;
    cout << "Enter total numbers:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        insertAtHead(head, num, head);
    }
    return is;
}

int main()
{
    // node *head = NULL; //pointer of type node
    // node *tail = NULL;
    // insertAtHead(head, 2, tail);
    // insertAtHead(head, 1, tail);
    // insertAtHead(head, 0, tail);
    // insertattail(head, 3, tail);
    // insertattail(head, 4, tail);
    // print(head);
    // cout << endl;

    // deleteAtHead(head);
    // print(head);
    // cout << endl;

    // reverse(head);
    // print(head);
    // cout << endl;

    // recursiveReverse(head, NULL, head, NULL);
    // print(head);
    // cout << endl;

    // node *mid = midpoint(head);
    // cout << "midpoint is " << mid->data;
    // cout << endl;

    // node *head1; //sorted linked list lena for merge to work
    // node *head2; //sorted linked list lena for merge to work
    // cin >> head1;
    // cin >> head2;
    // node *newhead = merge(head1, head2);
    // cout << newhead << endl;

    // node *head3;
    // cin >> head3;
    // head3 = mergesort(head3);
    // cout << head3;

    // node *floydhead;
    // cin >> floydhead;
    // floydhead->next->next->next->next = floydhead->next->next; //loop banadia
    // detectandremovecycle(floydhead);
    // cout<<endl;
    // cout<<floydhead;

    return 0;
}