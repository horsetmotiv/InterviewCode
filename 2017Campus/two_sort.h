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
    cin >> n;
    vector<string> a(n);
    bool is_lexicographically = true, is_length = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i].size() < a[i - 1].size()) {
            is_length = false;
        }
        if (a[i] < a[i - 1]) {
            is_lexicographically = false;
        }
    }
    cout << (is_length && is_lexicographically
                 ? "both"
                 : is_length
                       ? "lengths"
                       : is_lexicographically ? "lexicographically" : "none")
         << endl;
    return 0;
}