#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//its just the practice
int main()
{
    // map<pair<string, string>, vector<int>> m;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     string fn, ln; //firstName lastName
    //     int ct;
    //     cin >> fn >> ln >> ct;
    //     for (int j = 0; j < ct; j++)
    //     {
    //         int x;
    //         cin >> x;
    //         m[{fn, ln}].push_back(x); //think of student having different marks stored
    //     }
    // }
    // for (auto &pr : m)
    // {
    //     auto &fullname = pr.first;
    //     auto &marks_list = pr.second;
    //     vector<int>::iterator it;
    //     cout << fullname.first << " " << fullname.second << " :";
    //     for (it = marks_list.begin(); it != marks_list.end(); ++it)
    //     {
    //         cout << (*it) << " ";
    //     }
    //     //it actually returns pair<pair<string,string>,vector<int>>
    //     //the other way
    //     for (auto &pr : m)
    //     {
    //         cout << pr.first.first << " " << pr.first.second << " :";
    //         for (auto &marks : pr.second)
    //         {
    //             cout << marks << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    /*let do question
Monk is a multi-talented person, and prepares results for his college in his free time. (Yes, he is still in love with his old college!) He gets a list of students with their marks. The maximum marks which can be obtained in the exam is 100.

The Monk is supposed to arrange the list in such a manner that the list is sorted in decreasing order of marks. And if two students have the same marks, they should be arranged in lexicographical manner.

Help Monk prepare the same!

Input format:
On the first line of the standard input, there is an integer N, denoting the number of students. N lines follow, which contain a string and an integer, denoting the name of the student and his marks.

Output format:
You must print the required list.

Constraints:
1 <= N <= 105
1 <= | Length of the name | <= 100
1 <= Marks <= 100
*/
    map<int, multiset<string>> marks_map; // multiset allows to enter duplicates too 1,2,2,3,4
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int marks;
        string name;
        cin >> name >> marks;
        marks_map[marks].insert(name);
    }
    auto cur_it = --marks_map.end();
    while (true)
    {
        auto &students = (*cur_it).second;
        int marks = (*cur_it).first;
        for (auto &student : students)
        {
            cout << student << " " << marks << endl;
        }
        if (cur_it == marks_map.begin())
            break;
        cur_it--;
    }
    return 0;
}