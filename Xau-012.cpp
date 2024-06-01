#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[100000][4];
const int mod = 1e9 + 7;

long long gen(int i, int j, int prev = -1) {
    if (i == n) {
        return 1;
    }
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = 0ll;
    for (int k = 0; k <= 2; k++) {
        if (prev == 1 && k == 1) continue;
        dp[i][j] = (dp[i][j] % mod + gen(i+1, k, k) % mod) % mod;
    }
    return dp[i][j];
}

int main()
{
    cin >> n; 
    memset(dp, -1, sizeof(dp));
    cout << gen(0, 0) << endl;
    return 0;
}
