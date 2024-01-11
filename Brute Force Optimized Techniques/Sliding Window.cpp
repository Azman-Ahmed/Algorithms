#include <bits/stdc++.h>

using namespace std;

void maximum_sub_array_by_using_sliding_window()
{
    int n;
    cin>>n;

    vector<int> veca(n);

    for(int i=0; i<n; i++) cin>>veca[i];

    long long int curr_max = -1e18, ans = -1e18;

    for(int i = 0; i < n; i++)
    {
        curr_max = max((long long int)veca[i], veca[i] + curr_max);
        ans = max(ans, curr_max);
    }
    cout<<ans<<endl;
}
int main()
{
    maximum_sub_array_by_using_sliding_window();
}
