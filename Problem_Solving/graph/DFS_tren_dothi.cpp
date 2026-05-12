#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/**********************************************************************
 * @brief   Phương pháp biểu diễn đồ thị
 *          1. Ma trận kề
 *          2. Danh sách cạnh
 *          3. Danh sách kề
 * @note    Dựa trên mô hình ta biểu diễn, DFS sẽ có sự khác biệt
 **********************************************************************/

int visited[1005] = {0};

// 1. Ma trận kề (Adjacency matrix)
int matrix[1005][1005];
int n; // số đỉnh
void DFS_matrix(int u) {
    cout << u << ' ';
    visited[u] = 1;
    for (int v = 1; v <= n; v++) {
        if (matrix[u][v] == 1 && visited[v] == 0) { 
            DFS_matrix(v);
        }
    }
}

// 2. Danh sách cạnh
vector<pair<int,int>> edge_list;

void DFS_edgeList(int u) {
    cout << u << ' ';
    visited[u] = 1;
    for (pair<int,int>& p : edge_list) {
        if (p.first == u && !visited[p.second]) {
            DFS_edgeList(p.second);
        }
        else if(p.second == u && !visited[p.first]) {
            DFS_edgeList(p.first);
        }
    }
}

// 3. Danh sách kề (Adjacency list)
vector<int> adj_list[1005];

void DFS_adjList(int u) {
    // In ra đỉnh/hoặc làm gì đó khác
    cout << u << ' ';
    visited[u] = 1;

    for (int v : adj_list[u]) {
        if (visited[v] == 0) {
            DFS_adjList(v);
        }
    }
}


int main() {
    
}