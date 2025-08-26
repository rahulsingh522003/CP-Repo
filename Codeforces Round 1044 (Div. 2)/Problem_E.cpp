// Problem Link - https://codeforces.com/contest/2133/problem/E

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
set<int>st;
void dfs(vector<int>adj[], vector<pair<int,int>>&ans, int sr, int par, vector<int>&c)
{
    vector<int>child;
    for(auto &it : adj[sr])
    {
        if(it != par)
        {
            dfs(adj, ans, it, sr, c);
            child.push_back(it);
        }
    }
    int num {};
    bool flag = false;
    for(auto &it : child)
    {
        if(c[it] == 1)
            num++;
        else if(c[it] == 2)
            flag = true;
    }
    if(num > 2 || flag)
    {
        // this I will break
        st.insert(sr);
        ans.push_back({1,sr});
        ans.push_back({2,sr});
        c[sr] = 3;
    }
    else if(num == 2)
    {
        // this will be my intermediate node
        c[sr] = 2;
    }
    else
    {
        c[sr] = 1;
    }
}

void dfs2(vector<int>adj[], int sr, vector<int>&vis, vector<pair<int,int>>&ans)
{
    vis[sr] = 1;
    ans.push_back({1, sr});
    for(auto &it : adj[sr])
        if(vis[it] == 0)
            dfs2(adj, it, vis, ans);
}

void rahul()
{
    int n;
    cin >> n;
    vector<int>adj[n+1];
    vector<pair<int,int>>edg;
    for(int i = 0; i < n-1; i++)
    {
        int x,y;cin >> x >> y;
        edg.push_back({x,y});
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    st.clear();
    vector<int>c(n+1);
    vector<pair<int,int>>ans;
    dfs(adj, ans, 1, -1, c);
    debug(st)
    vector<int>adj2[n+1];
    for(int i = 0; i < n-1; i++)
    {
        int x = edg[i].first, y = edg[i].second;
        if(st.find(x) == st.end() && st.find(y) == st.end())
        {
            adj2[x].push_back(y);
            adj2[y].push_back(x);
        }
    }
    vector<int>vis(n+1);
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0 && st.find(i) == st.end() && adj2[i].size() <= 1)
        {
            dfs2(adj2, i, vis, ans);
        }
    }
    cout << (int)ans.size() << '\n';
    for(auto &it : ans)
        cout << it.first << " " << it.second << '\n';
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




