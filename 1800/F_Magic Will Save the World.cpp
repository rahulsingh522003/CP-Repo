// Problem Link - https://codeforces.com/problemset/problem/1862/F

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

// #define int long long

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
    long long w,f;
    cin >> w >> f;
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &it : v) cin >> it;

    int sum = accumulate(v.begin(), v.end(),0);
    
    vector<int>dp(sum+1,0);
    dp[0] = 1;
    debug(sum)

    for(int i = 1; i <= n; i++)
    {
        for(int j = sum; j >= 1; j--)
        {
            if(j >= v[i-1])
                dp[j] = dp[j-v[i-1]] || dp[j];
        }
    }

    long long ans = 1e18;
    for(int i = 0; i <= sum; i++)
    {

        if(dp[i] == 1)
        {
            // debug(i)
            //this sum is possible
            long long ab = ceil(i*1.0/w);
            int rem = sum - i;
            if(ab*f >= rem)
                ans = min(ans,ab);

            // check for fire as well
            long long bc =  ceil(i*1.0/f);
            if(bc*w >= rem)
                ans = min(ans,bc);
        }
    }
    cout<< ans << '\n';
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




