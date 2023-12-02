#include <bits/stdc++.h>
#define lli long long int

using namespace std;

const int N = 1e7;
vector<int> phi(N);



void phi_1_to_n(int n)
{
    std::iota(phi.begin(), phi.end(), 0);
    for(int i=2; i<N; i++)
    {
        if(phi[i]==i)
        {
            for(int j = i; j<N; j+=i)
            {
                phi[j] -= phi[j]/i;
            }
        }
    }
}

int main()
{
    phi_1_to_n(N);
    long long int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<phi[n]<<endl;
    }

}

