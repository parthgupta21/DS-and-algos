#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<long long>
#define lli long long int


int memo(vll arr, int n, int ind, int prev_ind, vector<vll> &m)
{
    if(ind == n){
        return 0;
    }

    if(m[ind][prev_ind+1] != -1){
        return m[ind][prev_ind + 1];
    }

    int notTake = 0 + memo(arr, n, ind + 1, prev_ind, m);
    int take = 0;

    if(prev_ind == -1 or arr[ind] > arr[prev_ind]){
        take = 1 + memo(arr, n, ind + 1, ind, m);
    }

    return m[ind][prev_ind + 1] = max(take, notTake);
}


int LISByMemo(vll a, lli n){
    vector < vll > m(n, vll(n + 1, -1));

    return memo(a, n, 0, -1, m);
}

int main(){
    lli n;
    cin >> n;
    vll a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << LISByMemo(a, n) << endl;
    // 8
    // 10 9 2 5 3 7 101 18

    //4
}