#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
    int s = 0;
    while(n) {
        s += n % 10;
        n /= 10;
    }  
    return s;
}

void solve()
{
    int n;
    cin >> n;
    while (n >= 10) {
        n = sum(n);
    }
    cout << n;
}

signed main()
{
    solve();
    return 0;
}
