#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
/*
3
LRR

E
*/
int test() {
    map<int, char> dir = {{0, 'N'}, {1, 'E'}, {2, 'S'}, {3, 'W'}};
    map<char, int> direction = {{'R', 1}, {'L', -1}};
    int m;
    cin >> m;
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res += direction[s[i]];
    }
    res = (res < 0 ? -1 : 1) * (abs(res) % 4);
    res = (res + 4) % 4;
    cout << dir[0 + res] << endl;
    return 0;
}