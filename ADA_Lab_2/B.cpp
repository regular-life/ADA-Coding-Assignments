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
    int n, op, x ;
    cin >> n ;
    vector < ll > dp(1024) ;
    dp[0] = 1 ;
    fr(0, n)
    {
        cin >> op >> x ;
        if (op == 1)
        {
            for (int j = 1023 ; j >= 0 ; j--)
            {
                if ((j | x) > 1023) continue ;
                dp[j | x] += dp[j] ;
                dp[j | x] %= 1000000007 ;
            }
        }
        else
        {
            cout << dp[x] << "\n" ;
        }
    }
}

signed main()
{
    hehe ;
    solve() ;
    return 0 ;
}