#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

struct Edge {
	int to, weight;
	int next;
};

Edge edge[MAXN];
int cnt = 0, head[MAXN];

void add(int u, int v, int w) {
	cnt++;
	edge[cnt].to = v;
	edge[cnt].weight = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}



int main() {
	//for tesx
	
    return 0;
}
