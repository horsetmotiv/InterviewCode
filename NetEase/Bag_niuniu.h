

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

int test1() {
    int n, capacity;
    cin >> n >> capacity;
    vector<int> value(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    cout << helper(value, 0, 0, capacity) << endl;
    return 0;
}

// 改进的方案 来自网上的答案  每天在详细分析一下
// https://www.nowcoder.com/discuss/70736?type=0&order=0&pos=15&page=1