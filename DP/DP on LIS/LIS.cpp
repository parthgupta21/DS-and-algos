#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<long long>
#define lli long long int

int memo(vll arr, int n, int ind, int prev_ind, vector<vll> &m)
{
    if (ind == n)
    {
        return 0;
    }

    if (m[ind][prev_ind + 1] != -1)
    {
        return m[ind][prev_ind + 1];
    }

    int notTake = 0 + memo(arr, n, ind + 1, prev_ind, m);
    int take = 0;

    if (prev_ind == -1 or arr[ind] > arr[prev_ind])
    {
        take = 1 + memo(arr, n, ind + 1, ind, m);
    }

    return m[ind][prev_ind + 1] = max(take, notTake);
}
int LISByMemo(vll a, lli n)
{
    vector<vll> m(n, vll(n + 1, -1));

    return memo(a, n, 0, -1, m);
}




int tabu(vll arr, int n)
{
    vector<vector<int>> dp(n+1 , vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind --){
        for (int prev = ind - 1; prev >= -1; prev --){
            int notTake = dp[ind + 1][prev + 1];
            int take = 0;

            if(prev == -1 or arr[ind] > arr[prev]){
                take = 1 + dp[ind + 1][ind + 1];
            }

            dp[ind][prev + 1] = max(take, notTake);
        }
    }

        return dp[0][0];
}


int Space(vll arr, int n)
{
    vll curr(n + 1, 0);
    vll prev(n + 1, 0);

    for (int i = n - 1; i >= 0; i--){
        for (int prev_i = i - 1; prev_i >= -1; prev_i --){
            int notTake = curr[prev_i + 1];
            int take = 0;

            if(prev_i == -1 or arr[i] > arr[prev_i]){
                take = 1 + curr[i + 1];
            }

            curr[prev_i + 1] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[0];
}


int main()
{
    lli n;
    cin >> n;
    vll a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // cout << LISByMemo(a, n) << endl;
    // 8
    // 10 9 2 5 3 7 101 18

    // 4


    cout << tabu(a, n) << endl;

    cout << Space(a, n) << endl;
}