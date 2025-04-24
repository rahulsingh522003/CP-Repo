// Problem Link - https://codeforces.com/problemset/problem/1702/E

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

bool dfs(vector<int>adj[], int sr, int p, vector<int>&vis, int cnt)
{
    vis[sr] = cnt;
    for(auto &it : adj[sr]) 
    {
        if(vis[it] == 0)
        {
            if(dfs(adj,it,sr,vis, cnt+1))
                return true;
        }
        else if(it != p)
        {
            if(abs(vis[it]-vis[sr])%2 ==0)
                return true;
        }
    }
    return false;
}

void rahul()
{
    int n;
    cin >> n;
    vector<int>adj[n+1];
    vector<int>freq(n+1);
    set<pair<int,int>>st;
    bool flag = true;
    for(int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        freq[x]++;
        freq[y]++;
        if(x == y || freq[x] > 2 || freq[y] > 2)
            flag = false; 
        if(st.find({x,y}) == st.end() && st.find({y,x}) == st.end())
        {
            adj[x].push_back(y);
            adj[y].push_back(x);
            st.insert({x,y});
        }
    }
    if(flag == false)
    {
        cout << "NO" << '\n';
        return;
    }
    fill(freq.begin(), freq.end(),0);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(freq[i] == 0)
        {
            if(dfs(adj,i,-1,freq,1))
            {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        rahul();
    }
    return 0;
}




