#include <bits/stdc++.h>
#define lli long long int

using namespace std;

const int N = 1e6;
long long phi[N], pre_phi[N], res;

void phi_1_to_n()
{
    for(int i=0; i<N; i++) phi[i] = i;
    phi[0] = phi[1] = 1;

    for(int i = 2; i < N; i++)

    if(phi[i]==i)
    {
        for(int j = i; j < N; j += i)
        {
            phi[j] -= phi[j]/i;

        }
    }

    pre_phi[0] = 0; pre_phi[1] = 1;

    for(int i = 2; i < N; i++) pre_phi[i] = pre_phi[i-1] + phi[i];

}



int main(void)
{
    phi_1_to_n();

    lli t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<pre_phi[n] * pre_phi[n]<<endl;
    }


}
