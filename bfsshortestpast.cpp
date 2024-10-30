#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//modified bfs
int bfs(int start, vector<vector<int>>& adjs, vector<bool>& visited, int end) {
    visited[start] = true;
    queue<int> q;
    q.push(start);
    int ans = 0;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        ans++;
        for(auto i: adjs[front]) {
            if(i==end) {
                return ans;
            }
            if(!visited[i]) {
                q.push(i);
                visited[i]=true;
            }
        }
    }
    return -1;
}
int main() {
    
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adjs(n+1);
    vector<bool> visited(n+1,false);
    int X,Y;
    cin >> X >> Y;
    for(int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        adjs[x].push_back(y);
        adjs[y].push_back(x);
    }
    cout << bfs(X,adjs,visited,Y);
}