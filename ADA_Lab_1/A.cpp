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

bool check(vector < int > arr, int m, int n, int exclude, int sum, int index, int size)
{
    // check whether there is a subsequence in the array whose sum is 0 or n or divisible by n
    if (index == m)
    {
        if ( sum == 0 && size > 0 )
        {
            return true ;
        }
        return false ;
    }
    if (index == exclude)
    {
        return check(arr, m, n, exclude, sum, index + 1, size) ;
    }
    return check(arr, m, n, exclude, (sum + arr[index] + n) % n, index + 1, size + 1) || check(arr, m, n, exclude, sum, index + 1, size) ;
}

void solve()
{
    int m, n ;
    cin >> m >> n ;
    vector < int > arr(m) ;
    fr(0, m)
    {
        cin >> arr[i] ;
        arr[i] %= n ;
    }
    fr(0, m)
    {
        if (!check(arr, m, n, i, 0, 0, 0))
        {
            cout << "NO\n" ;
            return ;
        }
    }
    cout << "YES\n" ;
    return ;
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