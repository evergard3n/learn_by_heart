#include <iostream>
#include <vector>

using namespace std;
// adj: lưu các đỉnh liên thông với từng node, mỗi vector<int> bên trong là các đỉnh liên thông với
// node thứ i của vector<vector>
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    // thăm node hiện tại
    visited[node] = true;
    // với từng đỉnh liên thông với node
    for (int i : adj[node])
    {
        // nếu chưa thăm
        if (!visited[i])
        {
            // gọi tiếp các con của nó
            dfs(i, adj, visited);
        }
    }
}
int countConnectedCmp(int n, vector<pair<int, int>> &edges)
{
    // khởi tạo graph, bool
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    // nhét edge vào
    for (auto p : edges)
    {
        adj[p.first].push_back(p.second);
        adj[p.second].push_back(p.first);
    }
    int res = 0;
    for (int node = 1; node <= n; node++)
    {
        if (!visited[node])
        {
            dfs(node, adj, visited);
            res++;
        }
    }
    return res;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back(make_pair(x, y));
    }
    cout << countConnectedCmp(n, edges);
}