// Problem link - https://codeforces.com/problemset/problem/2071/C

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

void answer(vector<int>adj[], int sr, int p, map<int,vector<int>>&mp, int l)
{
    mp[l].push_back(sr);
    for(auto &it : adj[sr])
    {
        if(it != p)
            answer(adj,it,sr,mp,l+1);
    }
}

void rahul()
{
    int n,st,e;
    cin >> n >> st >> e;
    vector<int>adj[n+1];
    for(int i = 0; i <n-1; i++)
    {
        int x,y;
        cin >>x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    map<int,vector<int>>mp;
    answer(adj,e,-1,mp,0);
    for(auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        for(auto &j :(*it).second)
            cout << j << " ";
    }
    cout << '\n';
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




