#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> graph;
vector<bool> visited;
vector<long long> min_dis;

void Dijkstra(int n, int c) { //컴퓨터 개수, 해킹당한 컴퓨터
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    min_dis = vector<long long>(n + 1, INT_MAX);
    visited = vector<bool>(n + 1, false);

    pq.push({0, c}); // 가중치, 노드
    min_dis[c] = 0;

    while (!pq.empty()) {
        edge current = pq.top(); pq.pop();
        int cost = current.first; // 비용
        int cur = current.second; // 노드

        if (visited[cur]) continue;
        visited[cur] = true;

        for (edge i : graph[cur]) { // i = {노드, 가중치}
            if (min_dis[cur] + i.second < min_dis[i.first]) { //현재 노드 최단거리 + 가중치 < 타깃 노드의 최단거리
                min_dis[i.first] = min_dis[cur] + i.second;
                pq.push({min_dis[i.first], i.first});
            }
        }
    }

    int cnt = 0, max_time = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            if (max_time < min_dis[i]) max_time = min_dis[i];
            cnt++;
        }
    }
    cout << cnt << ' ' << max_time << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int test; 
    cin >> test;
    while (test--) {
        int n, d, c;
        cin >> n >> d >> c;

        graph.resize(n + 1);
        for (int i = 0; i < d; i++) {
            int start, end, cost;
            cin >> start >> end >> cost; //end가 감염되면 cost 후에 start도 감염
            graph[end].push_back({start, cost});
        }
        Dijkstra(n, c);
        for (int i = 1; i <= n; i++) {
            graph[i].clear();
        }
    }
    return 0;
}
