#include <bits/stdc++.h>

#define lli long long int

using namespace std;

lli dp[101][100005];

lli knapSack(int w, int wt[], int val[], int n)
{

    if (n == 0 || w <= 0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];

    if (wt[n - 1] > w) return dp[n][w] =  knapSack(w, wt, val, n - 1);
    else return dp[n][w] =  max(val[n - 1] + knapSack(w - wt[n - 1], wt, val, n - 1),knapSack(w, wt, val, n - 1));
}


int main()
{
    int n, w;
    cin>>n>>w;
    int weight[n+1], profit[n+1];

    for(int i=0; i<n; i++) cin>>weight[i]>>profit[i];
    memset(dp,-1,sizeof(dp));
    cout << knapSack(w, weight, profit, n)<<endl;
}


