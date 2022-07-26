#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//stack usage in c++
unordered_map<char, int> symbols = {
    {'[', -1},
    {'{', -2},
    {'(', -3},
    {']', 1},
    {'}', 2},
    {')', 3},
};

string isBalanced(string s)
{
    stack<char> st;
    for (char bracket : s)
    {
        if (symbols[bracket] < 0)
        {
            st.push(bracket);
        }
        else
        {
            if (st.empty())
                return "NO";
            char top = st.top();
            st.pop();
            if (symbols[top] + symbols[bracket] != 0)
            {
                return "NO";
            }
        }
    }
    //after traversing the whole string we have to check our stack is empty or not if empty then string is valid Balanced paranthesis string else no
    if (st.empty())
        return "YES";
    return "NO";
}

int main()
{
    // stack<int> st;
    // st.push(2);
    // st.push(3);
    // st.push(5);
    // st.push(6);
    // while (!st.empty())
    // {
    //     cout << st.top() << endl; //st.top() will just let you see what is on top of stack it never removes
    //     st.pop();                 //it removes top element of stack
    // }
    //lets do a question of stack famous one
    //Balanced paranthesis. eg :- (((()))),(()(),etc
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     string s;
    //     cin >> s;
    //     cout << isBalanced(s) << endl;
    // }
    //Another Question
    //Next greater Element

    return 0;
}