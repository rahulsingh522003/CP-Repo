// Problem Link - https://codeforces.com/problemset/problem/1878/D

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

void fun(string &s, int i, int j)
{
    while(i <= j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }
}

void rahul()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int>l(k),r(k);
    for(auto &it : l)
        cin >> it;
    for(auto &it : r)
        cin >> it;
    vector<int>freq(n);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        auto it = upper_bound(l.begin(),l.end(),x) - l.begin();
        it--;
        int mini = min(x, l[it] + r[it] - x);
        int maxi = max(x, l[it] + r[it] - x);
        freq[mini-1] += 1;
        if(maxi < r[it])
            freq[maxi-1] += (-1);
    }
    for(int i = 0; i < k; i++)
    {
        // l[i] & r[i];
        int st = l[i] - 1;
        int e = r[i] - 1;
        for(int j = st + 1; j <= e; j++)
            freq[j] = freq[j] + freq[j-1];
        for(int j = st; j <= (st+e)/2; j++)
        {
            if(freq[j]&1)
            {
                // have to swap
                int ind1 = j;
                int ind2 = e - (j-st);
                swap(s[ind1],s[ind2]);
            }
        }
    }
    cout << s << '\n';
    
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




