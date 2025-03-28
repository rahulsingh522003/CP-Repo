// Problem Link - https://codeforces.com/problemset/problem/1922/C

 
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
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &it : v) cin >> it;

    vector<int>r(n), l (n);
    r[1] = 1;
    for(int i = 2; i < n; i++)
    {
        int d = (v[i] - v[i-1] > v[i-1]-v[i-2])? (v[i]-v[i-1]):1;
        r[i] = r[i-1] + d;
    }
    l[n-2] = 1;
    for(int i = n-3; i >= 0; i--)
    {
        int d = (v[i+1] - v[i] > v[i+2] - v[i+1]) ? (v[i+1]-v[i]):1;
        l[i] = l[i+1] + d;
    }
    debug(r)
    debug(l)

    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        if(x <= y)
            cout << r[y] - r[x] << '\n';
        else
            cout << l[y] - l[x] << '\n'; 
    }
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



 
