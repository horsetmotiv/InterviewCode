#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int test() {
    int m, n;
    while (cin >> m >> n) {
        int counter = 0;
        for (int i = m; i <= n; i++) {
            if (pow(i / 100, 3) + pow((i % 100) / 10, 3) + pow(i % 10, 3) ==
                i) {
                counter++;
                if (counter == 1) {
                    cout << i;
                } else {
                    cout << " " << i;
                }
            }
        }
        if (counter == 0) {
            cout << "no" << endl;
        }
    }
    return 0;
}