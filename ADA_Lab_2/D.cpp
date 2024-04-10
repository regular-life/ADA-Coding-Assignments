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

vector < ll > dijkstra(vector < pair < int, int > > adj[], int n)
{
    vector < ll > dist(2 * n + 1, INT64_MAX), vis(n + 1) ;
    dist[1] = 0 ;
    priority_queue < pair < ll, int >, vector < pair < ll, int > >, greater < pair < ll, int > > > pq ;
    pq.push({0, 1}) ;
    while (!pq.empty())
    {
        int u = pq.top().second ;
        pq.pop() ;
        if (vis[u]) continue ;
        vis[u] = 1 ;
        for (auto x : adj[u])
        {
            int v = x.first ;
            int w = x.second ;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w ;
                pq.push({dist[v], v}) ;
            }
        }
    }
    return dist ;
}

void solve()
{
    int n, m, a, b, w ;
    cin >> n >> m ;
    vector < pair < int, int > > adj[2 * n + 1] ;
    fr(0, m)
    {
        cin >> a >> b >> w ;
        adj[a].push_back({b, w}) ;
        adj[b + n].push_back({a + n, w}) ;
    }
    fr(1, n + 1)
    {
        adj[i].push_back({i + n, 0}) ;
    }
    vector < ll > dist = dijkstra(adj, n) ;
    fr(2, n + 1)
    {
        if (dist[i + n] == INT64_MAX) cout << "-1 " ;
        else cout << dist[i + n] << " " ;
    }
}

signed main()
{
    hehe ;
    solve() ;
    return 0 ;
}