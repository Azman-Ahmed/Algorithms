#include <bits/stdc++.h>
#define lli long long int

using namespace std;

const int N = 1e7;
vector<int> phi(N+10);


///Find Totient value of Numbers from 1 To N. (NlogN)
void phi_1_to_n()
{
    std::iota(phi.begin(), phi.end(), 0);
    for(int i=2; i<=N; i++)
    {
        if(phi[i]==i)
        {
            for(int j = i; j<=N; j+=i)
            {
                phi[j] -= phi[j]/i;
            }
        }
    }
}

///Find Totient value of n. (Sqrt(n))
lli phi_of_n(lli n)
{
    lli result = n;

    for(lli i=2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                n /= i;
            }
            result -= result / i;
        }
    }
    if(n > 1)
    {
        result -= result / n;
    }
    return result;
}

///Find Totient value of Numbers from 1 To N by using Divisor Sum Property. (nlogn)
void phi_1_to_n_div_sum()
{
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= N; i++) phi[i] = i - 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 2 * i; j <= N; j += i)
        {
            phi[j] -= phi[i];
        }
    }
}




int main()
{
    phi_1_to_n();
    long long int n;
    cin>>n;
    cout<<phi_of_n(n)<<endl;
}
