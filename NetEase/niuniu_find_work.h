#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

/*
3 3
1 100
10 1000
1000000000 1001
9 10 1000000000

100
1000
1001
*/

// 自己写的第一种方案 超时 通过80%的测试用例
class Solution_1 {
  public:
    int findMaxVlaue(vector<pair<int, int>> &v, int ai) {
        for (int i = 0; i < v.size(); i++) {
            if (ai >= v[i].first) {
                return v[i].second;
            }
        }
        return 0;
    }
    int test() {
        int m, n;
        cin >> n >> m;
        vector<pair<int, int>> v;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int di, pi;
            cin >> di >> pi;
            v.push_back(make_pair(di, pi));
        }
        sort(v.begin(), v.end(),
             [](const pair<int, int> &a, const pair<int, int> &b) {
                 return a.second == b.second ? a.first < b.first
                                             : a.second > b.second;
             });
        for (int i = 0; i < m; i++) {
            int ai;
            cin >> ai;
            res.push_back(findMaxVlaue(v, ai));
        }
        for (int i = 0; i < m; i++) {
            cout << res[i] << endl;
        }
        return 0;
    }
};

/*
3 3
1 100
10 1000
1000000000 1001
9 10 1000000000
对应输出应该为:

100
1000
1001

你的输出为:

100
100
1000
*/

// 这里是正确的答案 通过了100%的用例
class Solution_1_1 {
  public:
    // 这种方案 用到了map
    int test() {
        int m, n;
        cin >> n >> m;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            int di, pi;
            cin >> di >> pi;
            v.push_back(make_pair(di, pi));
        }
        sort(v.begin(), v.end(),
             [](const pair<int, int> &a, const pair<int, int> &b) {
                 return a.first == b.first ? a.second > b.second
                                           : a.first < b.first;
             });
        for (int i = 1; i < n; i++) {
            v[i].second = max(v[i].second, v[i - 1].second);
        }
        map<int, int> dir(v.begin(), v.end());
        for (int i = 0; i < m; i++) {
            int ai;
            cin >> ai;
            auto it = dir.upper_bound(ai);
            cout << (--it)->second << endl;
        }
        return 0;
    }
    // 这种方案 不用map
    int test1() {
        int m, n;
        cin >> n >> m;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            int di, pi;
            cin >> di >> pi;
            v.push_back(make_pair(di, pi));
        }
        sort(v.begin(), v.end(),
             [](const pair<int, int> &a, const pair<int, int> &b) {
                 return a.first == b.first ? a.second > b.second
                                           : a.first < b.first;
             });
        for (int i = 1; i < n; i++) {
            v[i].second = max(v[i].second, v[i - 1].second);
        }
        for (int i = 0; i < m; i++) {
            int ai;
            cin >> ai;
            auto it = upper_bound(
                v.begin(), v.end(), make_pair(ai, 0),
                [](const pair<int, int> &a, const pair<int, int> &b) {
                    return a.first < b.first;
                });
            cout << (--it)->second << endl;
        }
        return 0;
    }
};