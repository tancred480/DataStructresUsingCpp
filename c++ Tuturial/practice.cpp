#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
};
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency List of Vertex "
             << v << "\n head";
        for (auto x : adj[v])
        {
            cout << "-> " << x;
        }
        printf("\n");
    }
}
int formingMagicSquare(vector<vector<int>> s)
{
    int count = 0;
    vector<bool> v(10);
    if (s[1][1] != 5)
    {
        s[1][1] = 5;
        v[5] = true;
        count++;
    }
    if (s[0][0] + s[2][2] != 10)
    {
        s[0][0] = (10 - s[2][2]);
        count++;
    }
    if (s[0][1] + s[2][1] != 10)
    {
        s[0][1] = (10 - s[2][1]);
        count++;
    }
    if (s[0][2] + s[0][2] != 10)
    {
        s[0][2] = (10 - s[0][2]);
        count++;
    }
    if (s[1][0] + s[1][2] != 10)
    {
        s[1][0] = (10 - s[1][2]);
        count++;
    }

    return count;
}
// int main()
// {
//     // your code goes here
//     int n, m;
//     cin >> n >> m;
//     vector<int> arr(n);
//     for (auto &el : arr)
//         cin >> el;
//     sort(arr.begin(), arr.end());
//     int s = arr[0], e = arr[n - 1];
//     vector<int> v;
//     for (int i = s; i <= e; i++)
//     {
//         if (find(arr.begin(), arr.end(), i) == arr.end())
//         {
//             v.push_back(i);
//         }
//     }

//     int start = v[0], end = v[n - 1];
//     map<int, int> hm;
//     for (int i = 0; i <= v.size(); i++)
//     {
//         int wt = abs(v[i] - m);
//         if (hm.find(wt) != hm.end())
//         {
//             if (hm[wt] >= v[i])
//                 hm[wt] = v[i];
//         }
//         else
//         {
//             hm.insert({wt, v[i]});
//         }
//     }
//     cout << hm.begin()->second << endl;
//     return 0;
// }
int cnt = 0;
void subSeq(int i, vector<int> A, vector<int> ds, int x, int y, int n, int s)
{
    if (ds.size() == s)
    {
        int mx = *max_element(ds.begin(), ds.end());
        int mn = *min_element(ds.begin(), ds.end());
        if ((mx - mn) >= x && (mx - mn) <= y)
            cnt++;
    }
    for (int j = i; j < n; j++)
    {
        if (j != i && A[j] == A[j - 1])
            continue;
        ds.push_back(A[j]);
        subSeq(j + 1, A, ds, x, y, n, s);
        ds.pop_back();
    }
}
int solve(int N, int S, int X, int Y, vector<int> A)
{
    // Write your code here
    sort(A.begin(), A.end());
    vector<int> ds;
    subSeq(0, A, ds, X, Y, N, S);
    return cnt;
}
/*
X-MAS ARRAY

Problem Statement

An array is called “X-Mas”, if no two adjacent elements have sum strictly greater than X.

You are given an array A of N integers. In one operation you can select a K (1<=K<=N) such that A[K] > 0 and decrease A[K] by 1.

For the given value of X, find the minimum number of operations required to make A, a X-Mas array.

You are given T independent test cases.

*/
int main() {
	int n,q;cin>>n>>q;
	vector<int> arr(n+1),mxl(n+1,1),mxr(n+1,1);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(i==1){
			mxl[i] = arr[i];
		}else{
			mxl[i] = max(mxl[i-1],arr[i]);
		}
	}
	for(int i=n;i>=1;i--){
		if(i==n){
			mxr[i] = arr[i];	
		}else{
			mxr[i] = max(mxr[i+1],arr[i]);
		}
	}
	while(q--){
		int l,r,ans;cin>>l>>r;
		ans = max(mxl[l-1],mxr[r+1]);
		cout<<ans<<endl;
	}
}

/*
SIMPLY EQUAL

Problem Statement

Amy has an array A of N integers. In one operation she can select a non-empty sub-sequence of A, and decrease each element of the subsequence by 1.

Find the minimum number of operations required to make all the elements of the array A equal.

You are given T independent test cases.

Constraints

1 <= T <= 10
1 <= N <= 105
1 <= Ai <= 109
All input values are integers.
Input Format

First-line contains T.
First line of each test case consists of a single integer N.
Second line of each test case consists of N space separated integers denoting the array A.
Output Format

Print in a newline for each test case a single integer denoting the minimum number of operations required to make all the elements of the array A equal.
Sample Input 1

1

3

2 1 2

Sample Output 1

1

Explanation of Sample 1

She can select the subsequence S = {A1, A3} and decrease each by 1. So array becomes: A = [1, 1, 1]
*/