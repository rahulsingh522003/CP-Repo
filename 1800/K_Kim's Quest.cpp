// Problem Link - https://codeforces.com/problemset/problem/1912/K

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


const int mod = 998244353;
int answer(vector<int>&v, int l, int sl, int i, int n, vector<vector<vector<int>>>&dp)
{
    if(i == n)
    {
        return 0;
    }
    if(dp[i][l+1][sl+1] != -1)
        return dp[i][l+1][sl+1];
    if(sl == -1)
    {
        int f = 0;
        if(v[i]&1)
            f = answer(v,l,1,i+1,n,dp)%mod;
        else
            f = answer(v,l,0,i+1,n,dp)%mod;
        int s = answer(v,l,sl,i+1,n,dp)%mod;
        return dp[i][l+1][sl+1] = (f + s)%mod;
    }
    if(l == -1)
    {
        // can take this number of not

        int f = 0;
        if(v[i]&1)
            f = answer(v,1,sl,i+1,n,dp)%mod;
        else
            f = answer(v,0,sl,i+1,n,dp)%mod;
        int s = answer(v,l,sl,i+1,n,dp)%mod;
        return dp[i][l+1][sl+1] = (f + s)%mod;
    }
    // now we have to check
    int f = 0;
    if(v[i]&1)
    {
        if(l == 0 && sl == 1)
        {
            f = 1 + answer(v,1,0,i+1,n,dp)%mod;
        }
        if(l == 1 && sl == 0)
        {
            f = 1 + answer(v,1,1,i+1,n,dp)%mod;
        }
    }
    else
    {
        if(l == 0 && sl == 0)
            f = 1 + answer(v,0,0,i+1,n,dp)%mod;
        if(l == 1 && sl == 1)
            f = 1 + answer(v,0,1,i+1,n,dp)%mod;
    }
    int s = answer(v,l,sl,i+1,n,dp)%mod;
    return dp[i][l+1][sl+1] = (f+s)%mod;
}

void rahul()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &it : v) cin >> it;

    for(int i = 0; i < n; i++)
    {
        if(v[i]&1)
            v[i] = 1;
        else
            v[i] = 0;
    }
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(3,-1)));
    int ans = answer(v,-1,-1,0,n,dp)%mod;
    cout << ans << '\n';
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(6);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        rahul();
    }
    return 0;
}




