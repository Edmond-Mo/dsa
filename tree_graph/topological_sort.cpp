#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define UNVISITED 0
#define VISITED   1
vector<int> visited;

void buildAdjList(int g[][3], const int E, vector<vector<int>>& al)
{
    for (int i = 0; i < E; i++) {
        al[g[i][0]].push_back(g[i][1]);
        //al[g[i][1]].push_back(g[i][0]); // undirected graph
    }
}

void topologicalSort(int u, vector<vector<int>>& al, vector<int>& tp)
{
    visited[u] = VISITED;
    for (auto v : al[u]) {
        if (visited[v] == UNVISITED)
            topologicalSort(v, al, tp);
    }
    tp.push_back(u); // only change from basic DFS
}

void KahnAlgorithm(vector<vector<int>>& al, vector<int>& tp, int V)
{
    vector<int> inDegree(V, 0);
    for (int u = 0; u < al.size(); u++) {
        for (auto& v : al[u]) {
            inDegree[v]++;
        }
    }

    // min heap using greater<int>
    // queue only ever stores vertex with 0 indegree
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int u = 0; u < V; u++) {
        if (inDegree[u] == 0) {
            pq.push(u);
        }
    }

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        tp.push_back(u);
        for (auto &v : al[u]) {
            // v's indegree is at least one (an edge from u)
            // therefore after decrement it will be >= 0
            // if it becomes 0, we can push into queue
            inDegree[v]--;
            if (inDegree[v] > 0)
                continue;
            pq.push(v);
        }
    }
}

int main() {
    // Input data for graph.
    // Vertices are labeled from 0 to V - 1.
    //                u   v   w
    int g[][3] = { {  0,  1,  1},
                   {  2,  1,  1}, 
                   {  3,  2,  1}, 
                   {  4,  3,  1}, 
                   {  1,  5,  1}, 
                   {  4,  2,  1}, 
                   {  2,  6,  1} };
    const int V = 7;
    const int E = sizeof(g) / sizeof(g[0]);
    vector<vector<int>> adjList;
    adjList.assign(V, vector<int>());
    buildAdjList(g, E, adjList);

    // topological sorted list
    vector<int> tsorted;

    visited.assign(V, UNVISITED);
    for (int u = 0; u < V; u++) {
        if (visited[u] == UNVISITED)
            topologicalSort(u, adjList, tsorted);
    }

    reverse(tsorted.begin(), tsorted.end());
    for (int i = 0; i < tsorted.size(); i++) {
        printf("%d ", tsorted[i]);
    }
    printf("\n");

    tsorted.clear();
    KahnAlgorithm(adjList, tsorted, V);
    for (int i = 0; i < tsorted.size(); i++) {
        printf("%d ", tsorted[i]);
    }
    printf("\n");
    return 0;
}

