#include <bits/stdc++.h>

using namespace std;

vector<int> dp(100005 , 1e9);

int main()
{
    int n, k;
    cin>>n>>k;

    vector<int> veca(n);

    for(int i=0; i<n; i++)
    {
        cin>>veca[i];
    }


    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        if (i-j >= 0)
        {
            dp[i] = min(dp[i], dp[i-j] + abs(veca[i] - veca[i-j]));
        }
    }
    cout<<dp[n-1]<<endl;
}

