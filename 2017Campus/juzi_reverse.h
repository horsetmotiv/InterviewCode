#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int test() {
    string s;
    vector<string> res;
    while (cin >> s) {
        res.push_back(s);
    }
    reverse(res.begin(), res.end());
    cout << res[0];
    for (int i = 1; i < res.size(); i++) {
        cout << " " << res[i];
    }
    return 0;
}