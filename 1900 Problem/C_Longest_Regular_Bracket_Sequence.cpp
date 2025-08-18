// Problem Link - https://codeforces.com/problemset/problem/5/C

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
    string s;
    cin >> s;
    int n = (int)s.length();
    stack<pair<char,int>>st;
    map<int,int>mp; // ind len

    int maxi {}, cnt {1};
    bool flag = false;
    int lastLen = 0;
    for(int i = 0; i < n; i++)
    {
        if(st.size() && st.top().first == '(' && s[i] == ')')
        {
            auto it = st.top(); st.pop();
            int len = (i - it.second + 1); 
            if(mp.find(it.second) != mp.end())
                len += mp[it.second];
            if(len > maxi)
            {
                maxi = len;
                cnt = 1;
            }
            else if(len == maxi)
                cnt++;
            lastLen = len;
            flag = true;
        }
        else
        {
            if(flag)
            {
                flag = false;
                if(s[i] == '(')
                    mp[i] = lastLen;
            }
            st.push({s[i], i});
        }
    }
    cout  << maxi << " " << cnt << '\n';

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




