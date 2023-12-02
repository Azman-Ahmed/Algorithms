#include <bits/stdc++.h>
#define lli long long int

using namespace std;

lli euler(lli n)
{
    lli i, result = n;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0) result -= result / i;
        while (n % i == 0) n /= i;

    }

    if (n > 1) result -= result / n;
    return result;

}

int main()
{
    lli n;
    scanf("%lld",&n);
    if(n==1) printf("%d", 2);
    else printf("%lld\n",euler(n));
}

