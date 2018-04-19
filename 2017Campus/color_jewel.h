#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 这题跑歪了 一开始理解错了题意 所以没写出来
// 下面是我一开始的思路
int test() {
    // string s;
    // cin >> s;
    // unordered_map<char, int> dir;
    // set<char> search = {'A', 'B', 'C', 'D', 'E'};
    // int counter = 0;
    // for (int i = 0, j = 0, m = s.size(); i < m;) {
    //     if (search.count(s[i]) && dir[s[j]] == 0) {
    //         counter++;
    //     }
    //     dir[s[j]]++;
    // }
    return 0;
}

// 看过官方的思路后修改原本上面的思路
// 修改后 官方题解里面应该没有比我这个修改后的解法更牛逼的解法了
int test2() {
    string s;
    while (cin >> s) {
        unordered_map<char, int> dir;
        set<char> search = {'A', 'B', 'C', 'D', 'E'};
        int counter = 0, length = s.size(), res = s.size();
        s = s + s;
        for (int i = 0, j = 0, m = s.size(); i < m && j < m;) {
            if (search.count(s[j]) && dir[s[j]]++ == 0) {
                counter++;
            }
            while (counter == 5) {
                res = min(res, j - i + 1);
                if (search.count(s[i]) && --dir[s[i]] == 0) {
                    counter--;
                }
                i++;
            }
            j++;
        }
        cout << length - res << endl;
    }
    return 0;
}