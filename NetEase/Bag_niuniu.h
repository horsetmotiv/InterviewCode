

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
// https://www.nowcoder.com/discuss/70736?type=0&order=0&pos=15&page=1
// 这算法超时 只通过了80%的测试用例
int helper(vector<int> &value, int start, long cur, long capacity) {
    if (start >= value.size()) {
        return 1;
    }
    int res = 0;
    if (cur + value[start] <= capacity) {
        res += helper(value, start + 1, cur + value[start], capacity);
    }
    res += helper(value, start + 1, cur, capacity);
    return res;
}
int test() {
    int n, capacity;
    long long sum = 0;
    cin >> n >> capacity;
    vector<int> value(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
        sum += value[i];
    }
    int res = 0;
    if (sum <= capacity) {
        res = (1 << n);
    } else {
        res = helper(value, 0, 0, capacity);
    }
    cout << res << endl;
    return 0;
}
// 上面的优化版 通过了所有的用例
int res = 0;
void helper1(vector<int> &value, int start, long cur, long capacity) {
    res++;
    for (int i = start; i < value.size(); i++) {
        if (cur + value[i] <= capacity) {
            helper1(value, i + 1, cur + value[i], capacity);
        }
    }
}

int test1() {
    int n, capacity;
    long long sum = 0;
    cin >> n >> capacity;
    vector<int> value(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
        sum += value[i];
    }
    if (sum <= capacity) {
        res = (1 << n);
    } else {
        helper1(value, 0, 0, capacity);
    }
    cout << res << endl;
    return 0;
}

// 改进的方案 来自网上的答案  每天在详细分析一下
// https://www.nowcoder.com/discuss/70736?type=0&order=0&pos=15&page=1
void permulate(vector<long long> &item, int start, int end, int capicity,
               vector<long long> &v) {
    int m = 1 << (end - start);
    for (int i = 0; i < m; i++) {
        long long sum = 0;
        for (int j = start; j < end; j++) {
            if (i & (1 << (j - start))) {
                sum += item[j];
                if (sum > capicity) {
                    break;
                }
            }
        }
        if (sum <= capicity) {
            v.push_back(sum);
        }
    }
}
int test2() {
    int n, capacity;
    cin >> n >> capacity;
    vector<long long> value(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    vector<long long> v1, v2;
    permulate(value, 0, n / 2, capacity, v1);
    permulate(value, n / 2, n, capacity, v2);
    sort(v2.begin(), v2.end());
    long long res = 0;
    for (int i = 0; i < v1.size(); i++) {
        res += upper_bound(v2.begin(), v2.end(), capacity - v1[i]) - v2.begin();
    }
    cout << res << endl;

    return 0;
}