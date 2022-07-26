#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    for (int i = 0; i < 10; i++)
    {
        int n;
        cout << "Enter n value : " << endl;
        cin >> n;
        dq.push_back(n);
    }
    dq.push_back(1);
    dq.push_front(2);

    for (auto i : dq)
    {
        cout << i << " \n";
    }
    cout << "Size :" << dq.size() << endl;
    return 0;
}