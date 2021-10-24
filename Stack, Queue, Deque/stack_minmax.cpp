#include <iostream>
#include <vector>
using namespace std;

class minmaxstack
{
private:
    vector<int> stack;
    vector<int> min_stack;
    vector<int> max_stack;

public:
    // want to insert a new element
    void push(int data)
    {
        int curr_min = data;
        int curr_max = data;
        if (min_stack.size())
        {
            curr_min = min(min_stack[min_stack.size() - 1], data);
            curr_max = max(max_stack[max_stack.size() - 1], data);
        }
        min_stack.push_back(curr_min);
        max_stack.push_back(curr_max);
        stack.push_back(data);
    }

    int top()
    {
        return stack[stack.size() - 1];
    }

    int getmin()
    {
        return min_stack[min_stack.size() - 1];
    }

    int getmax()
    {
        return max_stack[max_stack.size() - 1];
    }

    bool empty()
    {
        return stack.size() == 0;
    }

    void pop()
    {
        stack.pop_back();
        min_stack.pop_back();
        max_stack.pop_back();
    }
};

int main()
{
    minmaxstack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.getmin() << endl;
    s.pop();
    cout << s.getmin() << endl;
    cout << s.getmax() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;
    cout << s.getmax();

    return 0;
}
