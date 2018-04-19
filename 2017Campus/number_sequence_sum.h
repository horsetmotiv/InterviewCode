#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int test() {
    int m, n;
    while (cin >> n >> m) {
        double res = 0;
        double temp = n;
        for (int i = 0; i < m; i++) {
            res += temp;
            temp = sqrt(temp);
        }
        printf("%.2f", res);
    }
    return 0;
}