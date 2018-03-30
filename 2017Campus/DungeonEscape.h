#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// 参考的代码
// https://www.cnblogs.com/ranranblog/p/5774712.html
// https://blog.csdn.net/zjwcdd/article/details/52563065
int test() {
    //输入的部分
    int n, m;
    cin >> n >> m;
    // vector<vector<char>> matrix(n, vector<char>(m, '.'));
    vector<vector<int>> dis(n, vector<int>(m, -2));
    vector<string> matrix;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        matrix.push_back(s);
    }
    pair<int, int> source;
    cin >> source.first >> source.second;
    vector<pair<int, int>> dir;
    int steps;
    cin >> steps;
    for (int i = 0; i < steps; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        dir.push_back(p);
    }
    queue<pair<int, int>> q;
    q.push(source);
    dis[source.first][source.second] = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        for (int i = 0; i < steps; i++) {
            int x = p.first + dir[i].first;
            int y = p.second + dir[i].second;
            if (x >= 0 && x < n && y >= 0 && y < m && dis[x][y] == -2) {
                if (matrix[x][y] == '.') {
                    dis[x][y] = dis[p.first][p.second] + 1;
                    q.push(make_pair(x, y));
                } else {
                    dis[x][y] = -1;
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.') {
                if (dis[i][j] == -2) {
                    cout << -1 << endl;
                    return 0;
                } else {
                    res = max(res, dis[i][j]);
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
