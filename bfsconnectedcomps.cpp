#include <bits/stdc++.h>
using namespace std;
void bfs(int start, vector<bool> &visited, const vector<vector<int>> &graph)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int frontVal = q.front();
        q.pop();
        for (int neighbor : graph[frontVal])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
void input()
{
    int n, m;
    cin >> n >> m;
    vector<bool> visited(n + 1, false);
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bfs(i, visited, graph);
            ans++;
        }
    }
    cout << ans;
}
int main()
{
    input();
    return 0;
}