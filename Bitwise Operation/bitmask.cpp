#include <bits/stdc++.h>

using namespace std;

int check_kth_bit(int x, int k)
{
    return ( x >> k ) & 1;
}

// O((2^n) * n)

void find_subset_by_using_bitmask()
{
    int n;
    cin>>n;

    vector<int> veca(n);

    for(int i=0; i<n; i++) cin>>veca[i];

    long long int ans = -1e18;
    for(int i = 0; i < (1<<n); i++)
    {
        long long int sum = 0;
        for(int j = 0; j < n; j++)
        {
            if(check_kth_bit(i,j))
            {
                //to print this subset
                cout<<veca[j]<<endl;

                //to find the sum of this subset
                sum+=veca[j];
            }
        }
        //to take the maximum sum of the from the subsets
        ans = max(ans, sum);
    }
    cout<<ans<<endl;

}

int main()
{
    find_subset_by_using_bitmask();
}
