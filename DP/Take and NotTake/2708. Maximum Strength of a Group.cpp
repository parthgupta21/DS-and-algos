#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<long long>
#define lli long long int

int recurssion(vll a, lli ind, bool taken, lli currentPr)
{
    if (ind == a.size())
    {
        return taken ? currentPr : LLONG_MIN;
    }

    lli notTake = recurssion(a, ind + 1, taken, currentPr);
    lli take = recurssion(a, ind + 1, true, currentPr * a[ind]);

    return max(notTake, take);
}


int main()
{

    int n;
    cin >> n;

    vll a(n);

    for (auto &i : a)
    {
        cin >> i;
    }

    // int result = recurssion(a, 0, false, 1) == INT_MIN ? 0 : recurssion(a, 0, false, 1);

    // cout << result<< endl;

    vector<vector<lli>> m(n + 1, vector<lli>(2, LLONG_MIN));

    int result = memo(a, 0, false, 1, m);

    if (result == LLONG_MIN)
    {
        result = 0;
    }
    cout << result << endl;
    return 0;
}