// Problem Link - https://codeforces.com/problemset/problem/2050/G

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

void answer(vector<int>adj[], int sr, int p, vector<int>&deg, vector<vector<int>>&dp)
{
    vector<int>child;
    for(auto &it : adj[sr])
    {
        if(it != p)
        {
            answer(adj, it, sr, deg, dp);
            child.push_back(dp[it][0]);
        }
    }
    if(child.size() == 0)
    {
        dp[sr][0] = dp[sr][1] = dp[sr][2] = 1;
        return;
    }
    // find maximum and secondmaximum
    int maxi = -1, smaxi = -1;
    for(int i = 0; i < (int)child.size(); i++)
    {
        if(maxi == -1)
        {
            maxi = child[i];
        }
        else
        {
            if(child[i] > maxi)
            {
                smaxi = maxi;
                maxi = child[i];
            }
            else if(child[i] > smaxi)
                smaxi = child[i];
        }
    }
    if(smaxi == -1)
    {
        // only 1 child
        dp[sr][0] = dp[sr][1] = maxi + deg[sr]-2;
        dp[sr][2] = deg[sr];
    }
    else
    {
        dp[sr][0] = maxi + deg[sr]-2;
        dp[sr][1] = maxi + smaxi + deg[sr]-2;
        dp[sr][2] = deg[sr];
    }
}


void rahul()
{
    int n;
    cin >> n;
    vector<int>adj[n+1];
    vector<int>deg(n+1);
    for(int i = 0; i < n-1; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    vector<vector<int>>dp(n+1,vector<int>(3,0));
    answer(adj,1,-1,deg,dp);
    int ans = 0;
    debug(dp)
    for(int i = 1 ;i <= n; i++)
        ans = max(ans, max(dp[i][0], max(dp[i][1],dp[i][2])));
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




