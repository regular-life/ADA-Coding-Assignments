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

int rec(string &str, int l, int r, char ch)
{
    // cout << l << " " << r << "    " << ch  ;
    if (l == r)
    {
        // cout << "\n" ;
        if (str[l] == ch)return 0 ;
        else return 1 ;
    }
    if (l > r) return 0 ;
    int mid = l + (r - l) / 2 ;
    int left_c = 0, right_c = 0 ;
    fr(l, mid + 1)
    {
        if (str[i] == ch)
        {
            left_c ++ ;
        }
    }
    fr(mid + 1, r + 1)
    {
        if (str[i] == ch)
        {
            right_c ++ ;
        }
    }
    // cout << "   " << (r - l + 1) / 2 << " " << left_c << " " << right_c << "\n" ;
    return min( mid + 1 - l - left_c + rec(str, mid + 1, r, ch + 1),
                r - mid - right_c + rec(str, l, mid, ch + 1)) ;
}

void solve()
{
    int n ;
    cin >> n ;
    string str ;
    cin >> str ;
    cout << rec(str, 0, n - 1, 'a') << "\n" ;
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