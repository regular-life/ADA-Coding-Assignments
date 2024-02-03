#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;
using ld = long double;
using lui = long unsigned int ;

#define hehe ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define print(arr,n) for(int i = 0 ; i < n ; i++){cout << arr[i] << " " ;} cout <<"\n" ;
#define in(arr, n) fr(0,n) {cin >> arr[i] ;} 
#define srt(arr) sort(arr.begin(), arr.end()) ;
#define fr(a,b) for (int i = a ; i < b ; i ++)
#define fr1(a,b) for (int j = a ; j < b ; j ++)
#define pb push_back
#define ttst int t; cin >> t; while (t--)
#define fileio freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

unordered_map < ll, int > mp ;

void rec(vector < int > &arr, vector < ll > &prefix, int n, int l, int r)
{
    if (l > r)
    {
        return ;
    }
    else if (l == r)
    {
        mp[arr[l]] ++ ;
        return ;
    }
    mp[prefix[r] - prefix[l] + arr[l]] ++ ;
    int mid = arr[l] + (arr[r] - arr[l]) / 2 ;
    int indx = upper_bound(arr.begin() + l, arr.begin() + r, mid) - arr.begin() ;
    // cout << l << " " << r << " " << indx << "\n" ;
    if (arr[indx] <= mid)
    {
        return ;
    }
    rec(arr, prefix, n, l, indx - 1) ;
    rec(arr, prefix, n, indx, r) ;
}

void solve()
{
    int n, q, s ;
    cin >> n >> q ;
    vector < int > arr(n) ;
    in(arr, n) ;
    srt(arr) ;
    vector < ll > prefix(n) ;
    prefix[0] = arr[0] ;
    fr(1, n)
    {
        prefix[i] = prefix[i-1] + (ll)arr[i] ;
    }
    rec(arr, prefix, n, 0, n - 1) ;
    while (q --)
    {
        cin >> s ;
        if (mp[s] > 0)
        {
            cout << "Yes\n" ;
        }
        else
        {
            cout << "No\n" ;
        }
    }
}

signed main()
{
    hehe ;
    ttst
    {
        solve() ;
        mp.clear() ;
    }
    return 0 ;
}