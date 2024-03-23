#include <bits/stdc++.h>

using namespace std;

int dp[100005][3];

int main()
{
    int n;
    cin>>n;

    vector<int> s(n), c(n), h(n);

    for(int i=0; i<n; i++) cin>>s[i]>>c[i]>>h[i];


    dp[0][0] = s[0];
    dp[0][1] = c[0];
    dp[0][2] = h[0];

    for(int i=1; i<n; i++)
    {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + s[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + c[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + h[i];
    }

    cout<<max({dp[n-1][0], dp[n-1][1], dp[n-1][2]})<<endl;
}


