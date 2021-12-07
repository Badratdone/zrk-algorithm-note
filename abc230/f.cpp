#include<bits/stdc++.h>
using namespace std;
const int p = 998244353;
int a[200005], n;
map<long long, int> b;
int main() {
    ios::sync_with_stdio(false);    cin.tie(NULL);
    b.clear();
    memset(a, 0, sizeof(a));
    cin >> n;
     
    for (int i = 1; i <= n; ++i)    cin >> a[i];
    b[0] = 1;

    long long pre = 0;
    int cur, sum = 1;

    for (int i = 1; i <= n; ++i) {
        cur = sum;
        pre += a[i];
        if (pre == 0)   cur++;

        sum -= b[pre];
        if (sum < 0)    sum += p;

        b[pre] = cur;
        
        sum += b[pre];
        if (sum >= p)    sum -= p;
    }
    if (pre == 0)   cur--;
    printf("%d\n", cur);
    return 0;
}