#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 这题是个垃圾的题目 根本就在误导别人

// 看了答案才知道这破题目坑爹
// https://www.nowcoder.com/questionTerminal/4faa2d4849fa4627aa6d32a2e50b5b25?toCommentId=717165
int test() {
    int n;
    cin >> n;
    vector<int> parents(n, 0), chlidrens(n, 0);
    vector<bool> isValid(n, 0);
    for (int i = 0; i < n; i++) {
        parents[i] = i;
    }
    isValid[0] = true;
    for (int i = 0; i < n - 1; i++) {
        int parent, chlid;
        cin >> parent >> chlid;
        if (parent <= n - 1 && isValid[parent] && chlidrens[parent] < 2) {
            chlidrens[parent]++;
            parents[chlid] = parent;
            isValid[chlid] = true;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int count = 1;
        int start = i;
        while (parents[start] != start) {
            start = parents[start];
            count++;
        }
        res = max(res, count);
    }
    cout << res << endl;
    return 0;
}