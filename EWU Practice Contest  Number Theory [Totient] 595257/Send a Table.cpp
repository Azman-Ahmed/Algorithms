#include <bits/stdc++.h>
#define lli long long int

using namespace std;

const int N = 1e6;
vector<lli> phi(N+20);

void phi_1_to_n()
{
    iota(phi.begin(), phi.end(), 0);
    for(lli i=2; i<=N; i++)
    {
        if(phi[i]==i)
        {
            for(lli j = i; j<N; j+=i)
            {
                phi[j] -= phi[j]/i;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    phi_1_to_n();

    lli n;

    while(1)
    {
        cin>>n;
        if(n==0) break;
        lli ans = 1;
        for(int i=2; i<=n; i++)
        {
            ans+=(2*phi[i]);
        }
        cout<<ans<<endl;
    }



}

