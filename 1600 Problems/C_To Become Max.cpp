// Problem Link - https://codeforces.com/problemset/problem/1856/C

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

bool check(vector<int>&v, int k, int mid)
{
    int n = (int)v.size();
    for(int i = 0; i < n;i++)
    {
        // kya iski aukat h
        int j = i;
        int bc = k;
        while(j < n-1)
        {
            int req = mid - (j-i) - v[j];
            if(req > bc)
                break;
            if(v[j+1] + 1>= v[j] + req)
            {
                return true;
            }
            else
            {
                bc -= req;
            }
            j++;
        }
    }
    return false;
}

void rahul()
{
    int n,k;
    cin >> n >> k;
    vector<int>v(n);
    int maxi = 1;
    for(auto &it : v)
    {
        cin >> it;
        maxi = max(maxi,it);
    }
    int low = maxi, high = 1e9;
    int ans = maxi;
    while(low <= high)
    {
        int mid = (low + high) >> 1;
        if(check(v,k,mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid -1 ;
    }
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




