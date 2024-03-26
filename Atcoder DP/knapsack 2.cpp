#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define endl '\n'

const lli INF = 1e18;

int main()
{
    lli n,w;
    cin>>n>>w;
    lli a[n], b[n];
    for (lli i = 0; i < n; i++) cin>>a[i]>>b[i];
    lli N = 1e5+5; //value[i] is max 10^3 and there can 100 items max, so if we take all of them, result will be 10^5
    vector<vector<lli>> dp(N, vector<lli>(n+1, INF));
    vector<vector<lli>> dp2(n+1, vector<lli>(N, INF));
    //dp[i][j] = min weight for value i considering upto j items

    dp[0][0] = 0;
    for (lli i = 0; i < N; i++)
    {
        for (lli j = 1; j <= n; j++)
        {
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
            if (i - b[j-1] >= 0) dp[i][j] = min(dp[i][j], dp[i - b[j-1]][j-1] + a[j-1]);
        }
    }

    dp2[0][0] = 0;
    for (lli i = 1; i <= n; i++)
    {
        for (lli j = 0; j < N; j++)
        {
            dp2[i][j] = min(dp2[i][j], dp2[i-1][j]);
            if (i - b[i-1] >= 0) dp2[i][j] = min(dp2[i][j], dp2[j - b[i-1]][i-1] + a[i-1]);
        }
    }

    for (lli i = N-1; i >= 1; i--)
    {
        if (dp2[n][i] <= w) {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
