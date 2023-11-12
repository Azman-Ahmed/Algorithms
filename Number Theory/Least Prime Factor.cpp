#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 7;
int lpf[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=2; i<N; i++)
    {
        if(lpf[i]==0)
        {
            lpf[i] = i;
            for(int j= 2*i; j<N; j+=i)
            {
                lpf[j] = i;
            }
        }
    }

    for(int i=2; i<N; i++) cout<<lpf[i]<<endl;

}
