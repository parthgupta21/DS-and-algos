#include<bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n)-1, 0)
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define print_1D_arr(a, n) for (long long i = 0; i < n; i++) { cout << a[i] << ' '; } cout << endl;
#define in_1D_arr(a,n)                     f(i,0,n){cin>>a[i];}
#define all(v)  v.begin(),v.end() 
#define pb push_back
typedef long long ll; 
typedef long long int  lli; 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<lli> vli;
bool all_same_element_in_arr(ll *arr, ll n){for(ll i=0; i<n-1; i++){if(arr[i]!=arr[i+1]){return false;}}return true;}
void solve();
//--------------------------------------------------MAIN---------------------------------------------------------------------------------------------------------------------------------------------------
int main() {
    solve();
    return 0;
}
//--------------------------------------------------SOLVE---------------------------------------------------------------------------------------------------------------------------------------------------
void solve() {
    lli n;
    cin >> n;

    string s;
    cin >> s;

   // create a string which less lexcographical than s
    string s1 = s;
    sort(s1.begin(), s1.end());
    if(s1 == s)
    {
        cout << "NO" << endl;
        return;
    }

    f(i, 0, n-1)
    {
        if(s[i] > s[i+1])
        {
            cout << "YES" << endl;
            cout << i + 1 << " " << i + 2 << endl;
            return;
        }
    }

    cout << "NO" << endl;
}