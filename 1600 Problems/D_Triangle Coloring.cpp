// Problem link - https://codeforces.com/problemset/problem/1795/D

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



class Factorial{
    vector<int>fac;
    int mod;
public:
    Factorial(int n, int m)
    {
        mod = m;
        fac.resize(n+1);
        fac[0] = 1;
        for(int i = 1; i <= n; i++)
            fac[i] = ((i%mod)*(fac[i-1]%mod))%mod;
    }

    int binpow(int a, int b)
    {
        if(b == 0)
            return 1;
        int res = binpow(a,b/2);
        if(b&1)
            return (((a*res)%mod)*(res))%mod;
        else
            return (res*res)%mod;
    }

    int inverse(int den)
    {
        return binpow(den,mod-2)%mod;
    }
    int ncr(int n, int r)
    {
        int nom = fac[n];
        int den = (fac[n-r]*fac[r])%mod;
        int denI = inverse(den);
        return (nom*denI)%mod;
    }
    int npr(int n, int r)
    {
        int nom = fac[n];
        int den = fac[n-r];
        int denI = inverse(den);
        return (nom*denI)%mod;
    }
};


void rahul()
{
    int n;
    cin >> n;
    int ans = 1;
    for(int i = 0; i < n/3; i++)
    {
        vector<int>v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(v.rbegin(), v.rend());
        if(v[0] == v[1] && v[1] == v[2])
            ans = (ans*3)%mod;
        else if(v[1] == v[2])
            ans = (ans*2)%mod;
        debug(ans)
    }
    Factorial obj(n,mod);
    cout << ((obj.ncr(n/3,n/6))*(ans))%mod << '\n';
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




