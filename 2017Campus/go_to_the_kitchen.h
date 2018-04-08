#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int test() {
    set<string> dir;
    string s;
    while (cin >> s) {
        dir.insert(s);
    }
    cout << dir.size() << endl;
    return 0;
}