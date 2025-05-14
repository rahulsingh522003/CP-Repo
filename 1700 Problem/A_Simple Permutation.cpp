// Problem Link - https://codeforces.com/problemset/problem/2089/A

// Solution 



// rsingh2003

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb emplace_back
#define ins emplace
#define ld long double
#define vi vector<int>
#define pii pair<int, int>
#define si set<int>
#define usi unordered_set<int>
#define mii map<int, int>
#define umii unordered_map<int,int>
#define mci map<char,int>
#define umci unordered_map<char,int>
#define vpi vector<pair<int, int>>
#define read(v) for(auto &i : v) cin >> i;
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define endl (char)10
const int mod{1000000007};
const int MAX_CHAR{256};

// Rahul naam to suna hi hoga

/*********************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*********************************************************************************************************/

int binpow(int a,int b,int m)
{
    if(b == 0)
        return 1;
    int res = binpow(a,b/2,m);
    if(b%2 == 0)
    {
        return (res*res)%m;
    }
    else
        return (a*(res*res)%m)%m;
}
int inverse(int b,int m)
{
    return binpow(b,m-2,m);
}
int ceil_div(int x, int y)
{
    if (x % y)
        return x / y + 1;
    return x / y;
}
int lcm(int x, int y)
{
    return (x * y) / __gcd(x, y);
}
void seivePrime(int n)
{
    vector<int> prime(n + 1);
    prime[0] = prime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = 1;
        }
    }
}
bool is_prime(int n)
{
    if(n == 1)
        return false;
    if(n == 2 || n == 3)
        return true;
    if(n%2 == 0 || n%3 == 0)
        return false;
    for(int i = 5; i * i <= n; i += 6)
    {
        if(n%i == 0 || n%(i+2) == 0)
            return false;
    }
    return true;
}

/**********************************************************************/

void solve()
{
    int n;
    cin >> n;
    if(n == 2 || n == 3)
    {
        for(int i = 1; i <= n; i++)
            cout << i << " ";
        cout << '\n';
        return;
    }
    int ab = n/3, bc = (2*n)/3;
    int val = -1;
    for(int i = bc; i >= ab; i--)
    {
        if(is_prime(i))
        {
            val = i;
            break;
        }
    }
    cout << val << " ";
    vector<int>v(n+1);
    for(int i = 1; i <= n; i++)
    {
        if(val - i >= 1 && val + i <= n)
        {
            cout << val-i << " " << val + i << " ";
            v[val] = 1;
            v[val+i] = 1;
            v[val-i] = 1;
        }
        else
            break;
    }
    for(int i = 1; i <= n; i++)
        if(v[i] == 0)
            cout << i << " ";
    cout << '\n';
}

/**********************************************************************/

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

