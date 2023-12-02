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

    if(n > 1) result -= result / n;

    return result;
}




int main()
{
    long long int n;
    cin>>n;
    cout<<phi_of_n(n)<<endl;
}
