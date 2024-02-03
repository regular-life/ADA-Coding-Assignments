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

void solve()
{
    int num_h, num_v, def, wiz ;
    cin >> num_h >> num_v ;
    vector < int > h_power(num_h) ;
    in(h_power, num_h) ;
    vector < pair < int, int > > bases(num_v) ;
    fr(0, num_v)
    {
        cin >> def >> wiz ;
        bases[i] = {def, wiz} ;
    }
    srt(bases) ;
    vector < ll > v_power(num_v) ;
    v_power[0] = bases[0].second ;
    fr(1, num_v)
    {
        v_power[i] = v_power[i-1] + (ll)bases[i].second ;
    }
    fr(0, num_h)
    {
        int target = h_power[i] ;
        // upper_bound for target in bases
        int indx = upper_bound(bases.begin(), bases.end(), make_pair(target, INT_MAX)) - bases.begin() ;
        if (indx == 0)
        {
            cout << "0 " ;
        }
        else
        {
            cout << v_power[indx - 1] << " " ;
        }
    }
}

signed main()
{
    hehe ;
    solve() ;
    return 0 ;
}