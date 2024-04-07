#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;
using ld = long double;

#define hehe ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define print(arr,n) for(int i = 0 ; i < n ; i++){cout << arr[i] << " " ;} cout <<"\n" ;
#define in(arr, n) fr(0,n) {cin >> arr[i] ;} 
#define srt(arr) sort(arr.begin(), arr.end()) ;
#define fr(a,b) for (int i = a ; i < b ; i ++)
#define ttst int t; cin >> t; while (t--)
#define fileio freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

void dfs(vector < int > adj[], int node, vector < int > &vis, vector < int > &ans, int t)
{
    if (vis[node]) t = -1 ;
    vis[node] = 1 ;
    ans[node] = t ;
    for (int x: adj[node])
    {
        if (ans[x] != t)
        {
            if (ans[x] == 0 || t == -1) dfs(adj, x, vis, ans, t) ;
            else if (ans[x] == 1) dfs(adj, x, vis, ans, 2) ;
        }
        else if (ans[x] == 1)
        {
            dfs(adj, x, vis, ans, 2) ;
        }
    }
    vis[node] = 0 ;
}

void solve()
{
    int n, m, u, v ;
    cin >> n >> m ;
    vector < int > adj[n + 1] ;
    fr(0, m)
    {
        cin >> u >> v ;
        adj[u].push_back(v) ;
    }
    vector < int > vis(n + 1), ans(n + 1) ;
    dfs(adj, 1, vis, ans, 1) ;
    fr(1, n + 1)
    {
        cout << ans[i] << " " ;
    }
    cout << "\n" ;
}

signed main()
{
    hehe ;
    ttst
    {
        solve() ;
    }
    return 0 ;
}