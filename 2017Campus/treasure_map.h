// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int test() {
    string s, subs;
    cin >> s;
    cin >> subs;
    int i = 0, j = 0;
    for (; i < s.size() && j < subs.size(); i++) {
        if (subs[j] == s[i]) {
            j++;
        }
    }
    if (j == subs.size()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}