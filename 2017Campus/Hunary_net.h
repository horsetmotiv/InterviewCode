#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// https://blog.csdn.net/waltonhuang/article/details/52142214
// https://blog.csdn.net/waltonhuang/article/details/52143201
// https://blog.csdn.net/tqh_candy/article/details/52220871
// https://www.nowcoder.com/questionTerminal/5ee8df898312465a95553d82ad8898c3
// 公式：(a*x+b)%c = (a*(x%c)+b)%c
// 这题确实不会
int test() {
    long long position, counter = 0;
    cin >> position;
    position = (4 * position + 3) % 1000000007;
    counter = 2;
    while (position && counter <= 300000) {
        position = ((position << 1) + 1) % 1000000007;
        counter++;
    }
    int res = (counter + 2) / 3;
    cout << (res > 100000 ? -1 : res) << endl;
    return 0;
}