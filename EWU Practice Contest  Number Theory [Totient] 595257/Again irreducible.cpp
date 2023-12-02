#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int euler(int n)
{
    int i, result = n;
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
    while(scanf("%d",&n),n) printf("%d\n",euler(n));
}

