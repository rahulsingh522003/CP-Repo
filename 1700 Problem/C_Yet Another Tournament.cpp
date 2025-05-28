// Problem Link - https://codeforces.com/problemset/problem/1783/C

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
    vector<int>v(n);
    for(auto &it : v)
        cin >> it;
    set<pair<int,int>>st;
    vector<int>vis(n);
    int ab = 0;
    vector<pair<int,int>>vp;
    for(int i = 0; i < n; i++)
    {
        vp.push_back({v[i],-i});
    }
    sort(vp.begin(),vp.end());
    for(int i = 0; i < n; i++)
    {
        if(ab + vp[i].first > m)
            break;
        else
        {
            ab += vp[i].first;
            st.insert({vp[i].first,-vp[i].second});
            vis[-vp[i].second] = 1;
        }
    }
    int x = (int)st.size();
    if(x == n)
    {
        cout << 1 << '\n';
        return;
    }
    else if(x == 0)
    {
        cout << n + 1<< '\n';
        return;
    }
    if(vis[x] == 0)
    {
        auto it = st.rbegin();
        int ind = (*it).second;
        int val = (*it).first;
        ab -= val;
        if(ab + v[x] <= m)
        {
            vis[ind] = 0;
            vis[x] = 1;
        }
    }
    // now calculate the wins

    vector<int>wins(n);
    int cnt = 1;
    for(int i = n-1; i >= 0; i--)
    {
        wins[i] = i;
        if(vis[i] ==0)
            wins[i]++;
        if(wins[i] > x)
            cnt++;
        else
        {
            cout<< cnt << '\n';
            return;
        }
    }

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




