#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

bool isInVaildBoardary(vector<vector<int>> &grid, int row, int col) {
    int m = grid.size(), n = grid[0].size();
    if (row >= 0 && row < m && col >= 0 && col < n) {
        return true;
    }
    return false;
}

// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/571cfbe764824f03b5c0bfd2eb0a8ddf

// 我的第一种写法 广度优先的方法 但是无法输出路径
int test() {
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n, p;
    cin >> m >> n >> p;
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    queue<pair<int, int>> q;
    if (matrix[0][0]) {
        q.push({0, 0});
        visited[0][0] = true;
    }
    while (!q.empty()) {
        int m = q.size();
        for (int i = 0; i < m; i++) {
            auto p = q.front();
            q.pop();
            if (p.first == 0 && p.second == n - 1) {
                ////////
                return 0;
            }
            for (int j = 0; j < direction.size(); j++) {
                pair<int, int> point;
                point.first = p.first + direction[i][0];
                point.second = p.second + direction[i][1];
                if (isInVaildBoardary(matrix, point.first, point.second) &&
                    !visited[point.first][point.second] &&
                    matrix[point.first][point.second] != 0) {
                    q.push(point);
                }
            }
        }
    }
    cout << "Can not escape!" << endl;
    return 0;
}

// 我得第二种方法 深度优先的搜索方法 写的过程中还是参照了官方的题解

int m, n, p;
int maxEnergy = -1;
vector<pair<int, int>> pathRes;
void helper(vector<vector<int>> &matrix, int row, int col, int energy,
            vector<pair<int, int>> &path) {
    if (p < 0 || !isInVaildBoardary(matrix, row, col) ||
        matrix[row][col] != 1) {
        return;
    }
    matrix[row][col] = 0;
    path.push_back({row, col});
    if (row == 0 && col == m - 1) {
        if (maxEnergy < energy) {
            maxEnergy = energy;
            pathRes = path;
        }
        matrix[row][col] = 1;
        path.pop_back();
        return;
    }
    helper(matrix, row, col + 1, energy - 1, path);
    helper(matrix, row + 1, col, energy, path);
    helper(matrix, row - 1, col, energy - 3, path);
    helper(matrix, row, col - 1, energy - 1, path);
    matrix[row][col] = 1;
    path.pop_back();
}
int test2() {
    cin >> n >> m >> p;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    if (matrix[0][0] == 0 || matrix[0][m - 1] == 0) {
        cout << "Can not escape!" << endl;
        return 0;
    }
    vector<pair<int, int>> path;
    helper(matrix, 0, 0, p, path);
    if (maxEnergy == -1) {
        cout << "Can not escape!" << endl;
    } else {
        cout << "[" << pathRes[0].first << "," << pathRes[0].second << "]";
        for (int i = 1; i < pathRes.size(); i++) {
            cout << ",[" << pathRes[i].first << "," << pathRes[i].second << "]";
        }
    }
    return 0;
}