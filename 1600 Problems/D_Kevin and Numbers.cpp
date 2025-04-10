// Problem Link - https://codeforces.com/contest/2061/problem/D

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
    vector<int>a(n),b(m);
    for(auto &it : a)
        cin >> it;
    for(auto &it : b)
        cin >> it;
    map<int,int>mp;
    for(int i = 0; i < n ; i++)
        mp[a[i]]++;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i = 0; i < m; i++)
        pq.push(b[i]);
    
    int i = 0;
    while(i < (n-m) && pq.size())
    {
        auto it = pq.top(); pq.pop();
        if(mp.find(it) != mp.end())
        {
            mp[it]--;
            if(mp[it] == 0)
                mp.erase(it);
            continue;
        }
        int x = it/2;
        int y = it/2;
        if(it&1)
            y++;
        auto it2 = mp.begin();
        if(x < (*it2).first)
        {
            cout << "NO" << '\n';
            return;
        }
        pq.push(x);
        pq.push(y);
        i++;
    }
    while(pq.size())
    {
        auto it = pq.top(); pq.pop();
        if(mp.find(it) == mp.end())
        {
            cout << "NO" << '\n';
            return;
        }
        mp[it]--;
        if(mp[it] == 0)
            mp.erase(it);
    }
    if(mp.size() == 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
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




