// Problem Link - https://codeforces.com/problemset/problem/1849/C

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
    string s;
    cin >> s;
    vector<int>lz(n),fo(n);
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            lz[i] = (s[i] == '0')?0:-1;
        else
            lz[i] = (s[i] == '0')?i:lz[i-1];

        if(n - i - 1 == n-1)
            fo[n-i-1] = (s[n-i-1] == '1')?(n-i-1):n;
        else
            fo[n-i-1] = (s[n-i-1] == '1')?(n-i-1):fo[n-i];  
    }

    set<pair<int,int>>st;
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a>>b;
        a--;
        b--;
        int last_zero = lz[b];
        int first_one = fo[a];
        if(last_zero < first_one)
            st.insert({-1,-1});
        else
            st.insert({first_one,last_zero});
    }
    cout << (int)st.size() << '\n';

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




