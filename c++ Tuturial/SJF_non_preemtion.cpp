#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cout << "Enter no of process :";
    cin >> n;
    vector<pair<int, int>> at_bt(n);
    vector<int> at(n), bt(n), ct(n), tat(n), wt(n), rt(n), pid(n);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        pid[i] = i;
        cout << "Enter arrival & burst time for process pid = " << i << ": ";
        cin >> at_bt[i].first >> at_bt[i].second;
        cout << endl;
    }
    sort(at_bt.begin(), at_bt.end()); //sorting according to arrival time.
    q.push(at_bt[0]);
    int i = 0;
    while (!q.empty())
    {
        if (i == 0)
        {
            //ct[i] = at[i]+ bt[i];
            ct[i] = q.front().first + q.front().second;
            at[i] = q.front().first;
            bt[i] = q.front().second;
            tat[i] = ct[i] - q.front().first;
            wt[i] = tat[i] - q.front().second;
            q.pop();
            vector<pair<int, int>> bt_at;
            int j = i + 1;
            while (ct[i] >= at_bt[j].first)
            {
                bt_at.push_back({at_bt[j].second, at_bt[j].first});
                j++;
            }
            sort(bt_at.begin(), bt_at.end()); //burst time sort
            for (auto &el : bt_at)
            {
                q.push({el.second, el.first});
            }
            i++;
        }
        else
        {
            if (ct[i - 1] <= q.front().first)
            {
                ct[i] = q.front().first + q.front().second;
            }
            else
            {
                ct[i] = ct[i - 1] + q.front().second;
            }
            at[i] = q.front().first;
            bt[i] = q.front().second;
            tat[i] = ct[i] - q.front().first;
            wt[i] = tat[i] - q.front().second;
            q.pop();
            vector<pair<int, int>> bt_at;
            for (auto &el : at_bt)
            {
                if (el.first <= ct[i] && el.first >= ct[i - 1]) //isko dhyan se dekh
                {
                    bt_at.push_back({el.second, el.first});
                }
            }
            sort(bt_at.begin(), bt_at.end()); //sorting according to burst time.
            for (auto &el : bt_at)
            {
                q.push({el.second, el.first});
            }
            i++;
        }
    }

    printf("\nPid\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++)
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
    return 0;
}