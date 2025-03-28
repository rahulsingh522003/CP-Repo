// Problem link - https://codeforces.com/problemset/problem/1937/B

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

int count(vector<string>&v, int i, int j, int n, string &s, int dp[][2])
{
    if(i == 1 && j == n-1)
        return 1;

    if(dp[j][i] != -1)
        return dp[j][i];
    if(i+1 < 2 && j + 1  < n)
    {
        int f = 0;
        if(v[i][j+1] == s[i+j+1])
            f = count(v,i,j+1,n,s,dp);
        int se = 0;
        if(v[i+1][j] == s[i+j+1])
            se = count(v,i+1,j,n,s,dp);
        return dp[j][i] = f + se;
    }
    else if(i + 1 < 2)
    {
        int f = 0;
        if(v[i+1][j] == s[i+1+j])
            f = count(v,i+1,j,n,s,dp);
        return dp[j][i] = f;
    }
    else
    {
        int f = 0;
        if(v[i][j+1] == s[i+j+1])
            f = count(v,i,j+1,n,s,dp);
        return dp[j][i] = f;
    }
    

}

void rahul()
{
    int n;
    cin >> n;
    vector<string>v(2);
    for(auto &it : v)
        cin >> it;
    int i {}, j {};
    string s = "";
    s += v[0][0];
    while(i < 2 && j < n)
    {
        // i+1,j
        // i,j+1;
        if(j+1 < n && v[i+1][j] == '0' && v[i][j+1] == '0')
        {
            s += '0';
            j++;
        }
        else if(j+1 < n && v[i+1][j] == '1' && v[i][j+1] == '1')
        {
            s += '1';
            j++;
        }
        else if(j + 1 < n && v[i][j+1] == '0')
        {
            s += '0';
            j++;
        }
        else if(i+1 < 2 && j + 1 < n  && v[i][j+1]=='1' && v[i+1][j] == '0')
        {
            // have to go down
            s += '0';
            i++;
            j++;
            while(j < n)
            {
                s += v[i][j];
                j++;
            }
            break;
        }
        else
            break;
    }
    if(i == 0)
    {
        s += v[1][n-1];
    }
    cout << s << '\n';
    int dp[n][2];
    memset(dp, -1, sizeof dp);
    cout << count(v,0,0,n,s,dp) << '\n';
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




