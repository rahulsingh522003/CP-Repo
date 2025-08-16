// Problem Link - https://codeforces.com/problemset/problem/2018/B

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

class LazySegmentTree{
public:
    vector<int>seg;
    vector<int>lazy;
public:
    LazySegmentTree(int n)
    {
        seg.resize(4*n);
        lazy.resize(4*n);
    }
    void build(int low, int high, int ind, vector<int>&arr)
    {
        if(low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high)>>1ll;
        build(low,mid,2*ind+1,arr);
        build(mid+1,high,2*ind+2,arr);
        seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
    }

    void update(int low, int high, int ind, int l, int r, int val)
    {
        // update lazy tree
        if(lazy[ind] != 0)
        {
            seg[ind] += lazy[ind];
            if(low != high)
            {
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // no overlap low high l r low high
        if(l > high || r < low)
            return;

        // complete overlap l low high r
        if(low >= l && high <= r)
        {
            seg[ind] += val;
            if(low != high)
            {
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            return;
        }

        int mid = (low + high)>>1ll;
        update(low,mid,2*ind+1,l,r,val);
        update(mid+1,high,2*ind+2,l,r,val);
        seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
    }

    int query(int low, int high, int ind, int l, int r)
    {
        if(lazy[ind] != 0)
        {
            seg[ind] += lazy[ind];
            if(low != high)
            {
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // no overlap l r low high l r
        if(r < low || high < l)
            return -1e18;

        // complete overlap l low high r
        if(low >= l && high <= r)
            return seg[ind];

        int mid = (low + high) >> 1ll;
        int left = query(low,mid,2*ind+1,l,r);
        int right = query(mid+1,high,2*ind+2,l,r);
        return max(left,right);

    }

};

void rahul()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &it : v)
        cin>>it;

    vector<int>smin(n), pmin(n);
    int x = n;
    for(int i = 0; i < n; i++)
    {
        x = min(x, v[i]);
        pmin[i] = x;
        x = max(x-1,0ll);
    }
    x = n;
    for(int i = n-1; i >= 0; i--)
    {
        x = min(x, v[i]);
        smin[i] = x;
        x = max(x-1,0ll);
    }
    debug(pmin)
    debug(smin)
    int cnt[n+1] {};

    for(int i = 0; i < n; i++)
        cnt[smin[i]]++;
    cnt[1]++;
    vector<int>pre(n+1);
    pre[0]=cnt[0];
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i-1]+cnt[i];

    for(int i = 0; i <= n; i++)
        pre[i] -= i;

    LazySegmentTree obj(n+1);
    obj.build(0,n,0,pre);

    int ans {};
    
    for(int i = 0; i < n; i++)
    {
        // now increase the previous value
        if(i-1 >= 0)
        {
            obj.update(0,n,0,pmin[i-1],n,1);
        }
        obj.update(0,n,0,smin[i],n,-1);
        
        int abc = obj.query(0,n,0,0,n);
        if(abc <= 0)
            ans++;        
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




