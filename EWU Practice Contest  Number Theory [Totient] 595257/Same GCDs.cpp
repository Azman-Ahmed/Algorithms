
#include <bits/stdc++.h>
#define lli long long int

using namespace std;

const int N = 1e7;
vector<int> phi(N);


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


void solve()
{
    lli a, m;
    cin>>a>>m;

    lli gcd1 = __gcd(a, m);
    m = m / gcd1;

    cout<<phi_of_n(m)<<endl;

}

int main()
{
//    phi_1_to_n(N);
    long long int t;
    cin>>t;
    while(t--) solve();

}
