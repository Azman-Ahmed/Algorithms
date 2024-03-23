#include <bits/stdc++.h>

#define lli long long int

using namespace std;

lli dp[101][100005];

///Recursive DP
lli knapSack_recursive(int w, int wt[], int val[], int n)
{

    if (n == 0 || w <= 0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];

    if (wt[n - 1] > w) return dp[n][w] =  knapSack_recursive(w, wt, val, n - 1);
    else return dp[n][w] =  max(val[n - 1] + knapSack_recursive(w - wt[n - 1], wt, val, n - 1),knapSack_recursive(w, wt, val, n - 1));
}

///Iterative DP
void knapSack_itr()
{
    lli ans = 0;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=w; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j - weight[i-1]>=0) dp[i][j] = max(dp[i][j], profit[i-1] + dp[i-1][j - weight[i-1]]);
        }
    }
    cout<<dp[n][w]<<endl;
}
                                    -----------------------------------------
Sack Size ->                        0 | 1 | 2 | 3  | 4  | 5  | 6  | 7  | 8  |
Item ↓ 
weight |   profit |   Item count    -----------------------------------------
                          0         0 | 0 | 0 | 0  | 0  | 0  | 0  | 0  | 0  |
                                    -----------------------------------------
   3        30            1         0 | 0 | 0 | 30 | 30 | 30 | 30 | 30 | 30 |
                                    -----------------------------------------
   4        50            2         0 | 0 | 0 | 30 | 50 | 50 | 50 | 80 | 80 |
                                    -----------------------------------------
   5        60            3         0 | 0 | 0 | 30 | 50 | 60 | 60 | 80 | 90 |
                                    -----------------------------------------
-> Here Each Dp[i][j] means that some items are taken from i items which gives the maximum profit and accomodate at most j sack size.
-> The formula is DP[i][j] = max( dp[i-1][j] , profit[i-1] + dp[i - 1][ j - weight[i - 1] ] )
-> DP[i-1][j] denotes that ith item is not taken, so there will be no change in item count and remaining sack size.
-> profit[i-1] + dp[i - 1][ j - weight[i - 1] ] denotes that ith item is taken, so the profit from ith item will be added and after adding the ith item
in the remaining sack space what is maximum profit using i-1 items.

    

int main()
{
    int n, w;
    cin>>n>>w;
    int weight[n+1], profit[n+1];

    for(int i=0; i<n; i++) cin>>weight[i]>>profit[i];
    memset(dp,-1,sizeof(dp));
    cout << knapSack_recursive(w, weight, profit, n)<<endl;
}


