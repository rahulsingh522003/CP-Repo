// Problem Link - https://codeforces.com/problemset/problem/2082/B

// Solution



/* rsingh2003 */

// Don't look at my code Bitch !!!

#include <bits/stdc++.h>
using namespace std;


// pbds
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template<class T>using oset = tree<T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>; // order_of_key  find_by_order

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
    int x,n,m;
    cin >> x >> n >> m;
    if(n == 0 || m == 0)
    {
        while(n != 0 && x != 0)
        {
            x = x>>1ll;
            n--;
        }
        while(m != 0 && x > 1)
        {
            if(x&1ll)
            {
                x = x>>1ll;
                x++;
            }
            else
                x = x>>1ll;
            m--;
        }
        cout << x << " " << x << '\n';
        return;
    }
    int ab = n, bc = m, cd = x;
    while(n != 0 && x != 0)
    {
        x = x>>1;
        n--;
    }
    while(m != 0 && x > 1)
    {
        if(x&1ll)
        {
            x = x>>1;
            x++;
        }
        else
            x = x>>1;
        m--;
    }
    while(bc != 0 && cd > 1)
    {
        if(cd&1ll)
        {
            cd = cd>>1;
            cd++;
        }
        else
            cd = cd>>1;
        bc--;
    }
    while(ab != 0 && cd != 0)
    {
        cd = cd>>1;
        ab--;
    }
    cout << cd << " " << x << '\n';
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




