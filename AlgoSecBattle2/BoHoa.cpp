#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>

int m, n, p, ans = 0;
vector<tuple<int, int, int, int>> conditions = {
    {1, 1, 3, 30000},
    {2, 2, 3, 50000},
    {3, 5, 5, 70000}
};

bool isPossible(vi &v, int a, int b, int c) { return v[0] >= a && v[1] >= b && v[2] >= c; }

int bfs() {
    queue<vi> q;
    map<vi, int> mp;
    q.push({m, n, p});
    mp[{m, n, p}] = 0;
    while (q.size()) {
        vi cur = q.front();
        q.pop();
        for(auto &condition : conditions) {
            auto [a, b, c, cost] = condition;
            if (isPossible(cur, a, b, c)) {
                vi next = {cur[0] - a, cur[1] - b, cur[2] - c};
                if (mp.count(next) == 0)
                {
                    q.push(next);
                    mp[next] = mp[cur] + cost   ;
                }
                ans = max(ans, mp[next]);
            }
        }
    }
    return ans;
}

void solve()
{   
    cin >> m >> n >> p;
    ans = 0;
    cout << bfs() << endl;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    solve();
    return 0;
}