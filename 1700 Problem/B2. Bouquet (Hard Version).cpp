// Problem Link - https://codeforces.com/problemset/problem/1995/B2

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
    vector<int>a(n),b(n);
    for(auto &it : a)cin >> it;
    for(auto &it : b)cin >> it;
    vector<pair<int,int>>v;
    for(int i = 0; i < n; i++)
        v.push_back({a[i],b[i]});
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < n-1; i++)
    {
        int mini = min(v[i].second, m/v[i].first);
        ans = max(mini*v[i].first, ans);
        if(v[i].first + 1 == v[i+1].first)
        {
            int k1 = min(m/v[i].first, v[i].second);
            int remC = m - k1*v[i].first;
            int k2 = min(remC/v[i+1].first,v[i+1].second);
            int remC2 = m - k1*v[i].first - k2*v[i+1].first;
            int r = min(k1,min(v[i+1].second - k2,remC2));
            ans = max(ans, (k1-r)*v[i].first + (k2+r)*v[i+1].first);
        }

    }
    int i = n-1;
    int mini = min(v[i].second, m/v[i].first);
    ans = max(mini*v[i].first, ans);
    cout << ans << '\n';
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




