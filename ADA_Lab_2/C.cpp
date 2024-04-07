#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;
using ld = long double;

#define hehe ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define print(arr,n) for(int i = 0 ; i < n ; i++){cout << arr[i] << " " ;} cout <<"\n" ;
#define in(arr, n) fr(0,n) {cin >> arr[i] ;} 
#define srt(arr) sorvt(arr.begin(), arr.end()) ;
#define fr(a,b) for (int i = a ; i < b ; i ++)
#define ttst int t; cin >> t; while (t--)
#define fileio freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

void dfs(vector < int > adj[], int n, int node, vector < int > &vis, int curr)
{
    vis[node] = curr ;
    for (int x: adj[node])
    {
        if (x > node && vis[x] < curr + 1)
        {
            dfs(adj, n, x, vis, curr + 1) ;
        }
    }
}

void solve()
{
    int n, m, x, y ;
    cin >> n >> m ;
    vector < int > adj[n + 1] ;
    while (m --)
    {
        cin >> x >> y ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }
    // determine max(length of stricly increasing path * size of adj[end chain of path])
    vector < int > vis(n + 1) ;
    fr(1, n + 1)
    {
        if (vis[i] == 0)
        {
            dfs(adj, n, i, vis, 1) ;
        }
    }
    ll mx = 0 ;
    fr(1, n + 1)
    {
        mx = max(mx, (ll) (1ll * vis[i] * adj[i].size()) );
    }
    cout << mx << "\n" ;
}

signed main()
{
    hehe ;
    solve() ;
    return 0 ;
}