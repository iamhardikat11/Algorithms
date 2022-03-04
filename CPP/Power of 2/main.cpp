#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> B;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        B[A[i]]++;
    }
    int x = 1;
    int ans = 0;
    for (int j = 0; j < 32; ++j)
    {
        for (int i = 0; i < N; ++i)
        {
            // WE'RE SUBTRACTING CONTRIBUTION OF a[i] from m
            // SO in future indices > i, the value of a[i] will not contribute.
            // It's same as deleting the past and only keeping future elements.
            // Here past means, < i values and future means > i values.
            B[A[i]]--;
            if (B.count(x - A[i]))
            {
                ans += B[x - A[i]];
            }
        }
        for (int i = 0; i < N; ++i)
        {
            B[A[i]]++;
        }
        x *= 2;
    }
    cout << ans << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}     
