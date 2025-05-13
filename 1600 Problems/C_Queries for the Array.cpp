// Problem Link - https://codeforces.com/problemset/problem/1861/C

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
    stack<int>st;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '+')
        {
            if(st.empty())
                st.push(1);
            else
            {
                if(st.top() == 0)
                    st.push(0);
                else
                    st.push(-1);
            }
        }
        else if(s[i] == '-')
        {
            if(st.top() == 1)
            {
                // array sort
                st.pop();
                if(st.size())
                    st.top() = 1;
            }
            else
                st.pop();
        }
        else if(s[i] == '1')
        {
            if(st.empty())
                continue;
            if(st.top() == 0)
            {
                cout << "NO" << '\n';
                return;
            }
            else
                st.top() = 1;
        }
        else
        {
            if(st.size() < 2 || st.top() == 1)
            {
                cout << "NO" << '\n';
                return;
            }
            else
                st.top() = 0;
        }
        debug(i)
    }
    cout << "YES" << '\n';
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




