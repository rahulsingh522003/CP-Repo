// problem link - https://codeforces.com/problemset/problem/1991/E

// Solution

/* rsingh2003 */

// Don't look at my code Bitch !!!

#include <bits/stdc++.h>
using namespace std;


// pbds
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>using oset = tree<T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>; // order_of_key  find_by_order

#define int long long

/*********************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*********************************************************************************************************/

// I know it's hard, that's why I'm doing this. 

void rahul()
{
    int n,m;
    cin >> n >> m;
    vector<int>adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // check for bipartite
    bool bi = true;
    vector<int>vis(n+1,-1);
    queue<int>q;
    q.push(1);
    vis[1] = 0;
    int cnt = 1; 

    while(q.size())
    {
        int sz = q.size();
        for(int i = 0; i < sz; i++)
        {
            auto it = q.front(); q.pop();
            for(auto &j : adj[it])
            {
                if(vis[j] == -1)
                {
                    q.push(j);
                    vis[j] = cnt;
                }
                else if(vis[j] != cnt)
                {
                    bi = false;
                    break;
                }
            }
        }
        cnt = (cnt == 0)?1:0;
    }
    if(bi)
    {
        cout << "Bob" << endl;
        vector<int>ab, bc;
        for(int i = 1; i <= n; i++)
        {
            if(vis[i] == 1)
                ab.push_back(i);
            else
                bc.push_back(i);
        }
        if(ab.size() > bc.size())
        {
            vector<int>c = ab;
            ab = bc;
            bc = c;        
        }
        int i {}, j {};
        int abp = 0, bbp = 0;
        for(int x = 0; x < n; x++)
        {
            int r,s;
            cin >> r >> s;
            int a = min(r,s);
            int b = max(r,s);
            //a is for 1, b is for 2

            if((a == 1 && b == 2) || (a == 1 && b == 3))
            {
                if(i < (int)ab.size())
                {
                    cout << ab[i] << " " << a << endl;
                    i++;
                }
                else if(j < (int)bc.size())
                {
                    cout << bc[j] << " " << b << endl;
                    j++;
                } 
            }
            else
            {
                if(j < (int)bc.size())
                {
                    cout << bc[j] << " " << 2 << endl;
                    j++;
                }
                else
                {
                    cout << ab[i] << " " << 3 << endl;
                    i++;
                }
            }
        }
    }
    else
    {
        cout << "Alice" << endl;
        for(int i = 1; i <= n; i++)
        {
            cout << "1 2" << endl;
            int x, y;
            cin >> x >> y;
        }
    }
}


int32_t main()
{
    cout << fixed << setprecision(6);
    int t = 1;
    cin >> t;
    while (t--)
    {
        rahul();
    }
    return 0;
}




