#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    queue<string> q;
    q.push("Tanveer");
    q.push("Naz");
    q.push("Rehaan");
    q.push("Armaan");
    q.push("Fiza");

    while (!q.empty())
    {
        cout << q.front() << endl; //q.front just lets you see what is at front of queue it never removes the element at front.
        q.pop();                   //it removes at front of queue.
    }
    return 0;
}