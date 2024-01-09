#include <bits/stdc++.h>
#define lli long long int

using namespace std;

///check if kth bit is 0 or 1
int check_kth_bit(int x, int k)
{
    return ( x >> k ) & 1;
}

///find which bits are 1
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
///find which bits are 0
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
///count the number of 1 bits
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
///find if a number is even or odd without using mod
bool even_or_odd_by_bit(int n)
{
    return n & 1; ///0th (2^0 = 1) bit is responsible for making a number odd
}
///turn kth bit into 1
int on_kth_bit(int x, int k)
{
    return x | (1 << k);
}
///turn kth bit into 0
int off_kth_bit(int x, int k)
{
    return x & ~(1<<k);
}
///turn kth bit 0 if it is 1 vice versa
int toggle_kth_bit(int x, int k)
{
    return x^(1<<k);
}
///multiply a decimal with 2 without using *
int multiply_by_two(int x)
{
    return x<<1;
}
///multiply a decimal with power of 2 without using *
int multiply_by_power_of_two(int x, int k)
{
    return x<<k;
}

///check the number is a power of 2
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
