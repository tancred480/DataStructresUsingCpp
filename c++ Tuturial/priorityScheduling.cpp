#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void my_dep_sort(vector<int> &a, vector<int> &b, vector<int> &c, vector<int> &d, vector<int> &e)
{
    for (int i = 0; i < a.size(); i++)
    {
        int idx = i;
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[j] < a[idx])
                idx = j;
        }
        // swapping using XOR operator;
        if (idx != i)
        {
            swap(a[i], a[idx]);
            swap(b[i], b[idx]);
            swap(c[i], c[idx]);
            swap(e[i], e[idx]);
        }
    }
};

int main()
{
    int n;

    cout << "Enter no of process :";
    cin >> n;
    int remain = n;
    vector<int> at(n), bt(n), ct(n), tat(n), wt(n), rt(n), pid(n), priority(n);
    vector<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        pid[i] = i;
        cout << "Enter arrival and burst time of process " << i << " :";
        cin >> at[i] >> bt[i];
        cout << "Enter its priority :";
        cin >> priority[i];
        cout << endl;
    }
    vector<int> cp_bt(bt);
    my_dep_sort(at, bt, pid, priority, cp_bt);
    q.push_back({priority[0], pid[0]});
    int j = 1; //track for process
    int time = 0;
    while (!q.empty())
    {
        if (bt[q[0].second] >= 1)
        {
            cout << "p" << q[0].second + 1 << " " << bt[q[0].second] << endl;
            ct[q[0].second] = time + 1;
            bt[q[0].second] = bt[q[0].second] - 1;
            time++;
            if (bt[q[0].second] == 0) //checking if process execution burst time completed or not .
            {
                tat[q[0].second] = ct[q[0].second] - at[q[0].second];
                wt[q[0].second] = tat[q[0].second] - cp_bt[q[0].second];
                q.erase(q.begin()); //popping out front element when its finished its execution from queue.
            }
        }
        for (int i = j; i < at.size(); i++)
        {
            if (at[i] == time) //checking if at this instance of time any process has arrived or not if then push it into queue.
            {
                q.push_back({priority[i], pid[i]});
                j++;
            }
        }

        sort(q.begin(), q.end(), greater<pair<int, int>>()); //sorting all remaining(current) process in the queue according to 0 priority[since its pair of priority & pid] it will sort according to priority=>key.
    }
    cout << endl;
    printf("\nPid\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++)
        cout << (pid[i] + 1) << "\t" << at[i] << "\t" << cp_bt[i] << "\t" << ct[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
    return 0;
}