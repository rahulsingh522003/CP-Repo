// Problem Link - https://codeforces.com/problemset/problem/1881/F

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

int ceilDiv(int a, int b)
{
    if(a%b == 0)
        return a/b;
    return a/b+1;
}

void rahul()
{
    int n,k;
    cin >> n >> k;
    set<int>st;
    for(int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    vector<int>adj[n+1];
    for(int i = 0; i < n-1 ; i++)
    {
        int x,y;
        cin >> x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(st.size() == 1)
    {
        cout << 0 << '\n';
        return;
    }
    auto it = st.begin();
    int sr = (*it);
    vector<int>vis(n+1);
    int node = 0;
    queue<int>q;
    q.push(sr);
    vis[sr] = 1;
    while(q.size())
    {
        int sz  = q.size();
        for(int i = 0; i < sz; i++)
        {
            auto it = q.front(); q.pop();
            if(st.find(it) != st.end())
                node = it;
            for(auto &j : adj[it])
            {
                if(vis[j] == 0)
                {
                    q.push(j);
                    vis[j] = 1;
                }
            }
        }
    }
    int dis = 0;
    fill(vis.begin(), vis.end(),0);
    q.push(node);
    vis[node] = 1;
    int maxi = 0;
    while(q.size())
    {
        int sz  = q.size();
        for(int i = 0; i < sz; i++)
        {
            auto it = q.front(); q.pop();
            if(st.find(it) != st.end())
            {
                maxi = max(maxi,dis);
            }
            for(auto &j : adj[it])
            {
                if(vis[j] == 0)
                {
                    q.push(j);
                    vis[j] = 1;
                }
            }
        }
        dis++;
    }
    cout << ceilDiv(maxi,2) << '\n';
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(6);
    int t = 1;
    cin >> t;
    while (t--)
    {
        rahul();
    }
    return 0;
}




