#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int check_kth_bit(int x, int k)
{
    return ( x >> k ) & 1;
}

void find_set_bits(int x)
{
    for(int i=0; i<32; i++)
    {
        if(check_kth_bit(x,i))
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

void find_off_bits(int x)
{
    for(int i=0; i<32; i++)
    {
        if(!check_kth_bit(x,i))
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int count_set_bits(int x)
{
    int ans = 0;
    for(int i=0; i<32; i++)
    {
        if(check_kth_bit(x,i))
        {
            ans++;
        }
    }
    return ans;
}

bool even_or_odd_by_bit(int n)
{
    return n & 1; ///0th (2^0 = 1) bit is responsible for making a number odd
}

int on_kth_bit(int x, int k)
{
    return x | (1 << k);
}

int off_kth_bit(int x, int k)
{
    return x & ~(1<<k);
}

int toggle_kth_bit(int x, int k)
{
    return x^(1<<k);
}

int multiply_by_two(int x)
{
    return x<<1;
}

int multiply_by_power_of_two(int x, int k)
{
    return x<<k;
}

int check_power_of_two_or_not(int x)
{
    return count_set_bits(x);
}


void solve()
{
    int n, k;
    cin>>n>>k;
    cout<<toggle_kth_bit(n, k)<<endl;

}

int main()
{
    int t;
    cin>>t;
    while(t--) solve();
}
