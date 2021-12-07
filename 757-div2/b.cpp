#include<bits/stdc++.h>
using namespace  std;
int t;

long long res[200005];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, less<pair<long long, long long>>> pq;
int main() {
    cin >> t;
    
    for (; t; t--) {
        
        memset(res, 0, sizeof(res));

        long long dist = 1, pos = 1;
        long long all = 0;
        int n; cin >> n;

        for (int i = 1; i <= n; ++i) {
            int now; cin >> now;
            pq.push(make_pair(now, i));
        }
        while (!pq.empty()) {
            auto cur = pq.top();    pq.pop();
            if (pos) {
                res[cur.second] = dist;
                pos ^= 1;
                all += cur.first * dist * 2;
                
            }else {
                res[cur.second] = 0 - dist;
                pos ^= 1;
                all += cur.first * dist * 2;
                dist++;        
            }
        }
        printf("%lld\n", all);
        for (int i = 0; i <= n; ++i) {
            printf("%d ", res[i]);
        }
        printf("\n");
    }
    return 0;
}