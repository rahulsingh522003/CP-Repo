// Problem Link - https://codeforces.com/problemset/problem/2014/E

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

struct Node{
    int a,b,c;
    Node(int x, int y, int z)
    {
        a = x;
        b = y;  
        c = z;
    }
};

struct cmp{
    bool operator()(Node &x, Node &y)
    {
        return x.a < y.a;
    }
};


void answer(vector<pair<int,int>>adj[], vector<pair<int,int>>&dis, int sr, set<int>&st)
{
    set<vector<int>>pq;
    // pq.push(Node(0,sr,0));
    pq.insert({0,sr,0});
    dis[sr].first = 0;
    // first --> without horse
    // second --> with horse

    while(pq.size())
    {
        auto it = pq.begin(); 
        // pq.pop();
        int node = (*it).at(1), dist = (*it).at(0);
        bool horse = (*it).at(2);
        pq.erase(it);
        bool flag = false;
        if(st.find(node) != st.end() || horse == 1)
        {
            //ghoda mil gaya
            flag = true;
        }   
        for(auto &j : adj[node])
        {
            if(flag)
            {
                // check for distance with ghoda
                int newDis = dist + j.second/2;
                if(dis[j.first].second > newDis)
                {
                    pq.erase({dis[j.first].second,j.first,1});
                    dis[j.first].second = newDis;
                    pq.insert({newDis,j.first,1});
                }
            }
        
            int newDis = dist + j.second;
            if(dis[j.first].first > newDis)
            {
                pq.erase({dis[j.first].first,j.first,0});
                dis[j.first].first = newDis;
                pq.insert({newDis,j.first,0});
            }
        
        }
    }
}

void rahul()
{
    int n,m,h;
    cin >> n >> m >> h;
    set<int>st;
    for(int i = 0; i < h; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    vector<pair<int,int>>adj[n+1];
    for(int i = 0; i<m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    vector<pair<int,int>>dis1(n+1,{1e18,1e18});
    vector<pair<int,int>>dis2(n+1,{1e18,1e18});
    answer(adj,dis1,1,st);
    answer(adj,dis2,n,st);
     
    debug(dis1)
    debug(dis2)
   
 
    int ans = 1e18;
    for(int i = 1; i <= n; i++)
    {
        int maxi = max(min(dis1[i].first,dis1[i].second),min(dis2[i].first,dis2[i].second));
        ans = min(ans,maxi);
    }
    if(ans == 1e18)
        cout <<-1 << '\n';
    else
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




