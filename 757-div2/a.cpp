#include<bits/stdc++.h>
using namespace std;

long long a[105], t, n, l, r, k;

int main() {
    ios::sync_with_stdio(false);    cin.tie(nullptr);
    cin >> t;
    //int p = INT_MAX;
    while (t--) {
        cin >> n >> l >> r >> k;
        int cnt = 0, res = 0, sum = 0;;
        for (int i = 1; i <= n; ++i) {
            int now; cin >> now;
            if (now >= l && now <= r) {
                cnt++;  a[cnt] = now;
            }
        }
        sort(a + 1, a + cnt + 1);
        for (int i = 1; i <= cnt; ++i) {
            if (sum + a[i] <= k) {
                sum += a[i], res++;
            }
            else break;
        }
        printf("%d\n", res);
    }
    return 0;
}