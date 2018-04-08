#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int test() {
    int n;
    while (cin >> n) {
        vector<string> res;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            res.push_back(s);
        }
        sort(res.begin(), res.end(), [](const string &a, const string &b) {
            return (a + b) < (b + a);
        });
        for (int i = 0; i < res.size(); i++) {
            cout << res[i];
        }
    }
    return 0;
}