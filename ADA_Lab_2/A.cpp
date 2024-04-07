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

void solve()
{
    int n, diff ;
    cin >> n ;
    vector < int > xi(n), yi(n) ;
    in(xi, n) ; in(yi, n) ;
    int tot = 0 ;
    for (int x: xi) tot += x ;
    vector < vector < int > > dp(n + 1, vector < int > (100000, INT_MIN));
    dp[0][0] = 0 ;
    fr(0, n)
    {
        for (int j = n - 1 ; j >= 0 ; j --)
        {
            for (int k = 0 ; k <= 1e4 - xi[i] ; k ++)
            {
                dp[j + 1][k + yi[i]] = max(dp[j + 1][k + yi[i]], dp[j][k] + xi[i]) ;
            }
        }
    }
    srt(yi) ;
    int curr = 0, k = 0 ;
    for (int i = n - 1 ; i >= 0 ; i --)
    {
        curr += yi[i] ;
        k ++ ;
        if (curr >= tot) break ;
    }
    int mx = 0 ;
    fr(tot, 1e4 + 1)
    {
        mx = max(mx, dp[k][i]) ;
    }
    cout << k << " " << tot - mx << "\n" ;
}

signed main()
{
    hehe ;
    solve() ;
    return 0 ;
}