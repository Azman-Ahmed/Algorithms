#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    ///O(n)
    vector<int> prime_factors;
    for(int i=2; i<n; i++)
    {
        while(n%i==0)
        {
            prime_factors.push_back(i);
            n/=i;
        }
    }
    if(n>1) prime_factors.push_back(n);


    ///O(sqrt(n))
    for(int i=2; i*i<n; i++)
    {
        while(n%i==0)
        {
            prime_factors.push_back(i);
            n/=i;
        }
    }
    if(n>1) prime_factors.push_back(n);

    for(int i=0; i<prime_factors.size(); i++) cout<<prime_factors[i]<<endl;

    
    /// O(nlogn) using LPF
    for(int i=2; i<N; i++)
    {
        if(lpf[i]==0)
        {
            lpf[i] = i;
            for(int j = 2*i; j<N; j+=i)
            {
                if(lpf[j]==0) lpf[j] = i;
            }
        }
    }
    cin>>n;
    while(n > 1)
    {
        cout << lpf[n] << endl;
        n/=lpf[n];
    }
    

}
