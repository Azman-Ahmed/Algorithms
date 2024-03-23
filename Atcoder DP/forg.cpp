#include <bits/stdc++.h>

using namespace std;

int dp[100005];

int main()
{
    int n;
    cin>>n;

    vector<int> veca(n);

    for(int i=0; i<n; i++)
    {
        cin>>veca[i];
    }

    dp[0] = 0;
    dp[1] = abs(veca[1] - veca[0]);

    for(int i=2; i<n; i++)
    {
        dp[i] = min(dp[i-1] + abs(veca[i-1] - veca[i]), dp[i-2] + abs(veca[i-2] - veca[i]));
    }

    cout<<dp[n-1]<<endl;
}
