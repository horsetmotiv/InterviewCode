#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

void select_sort(vector<int> &a) {
    int m = a.size();
    for (int i = 0; i < m; i++) {
        int minIndex = i;
        for (int j = i + 1; j < m; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

void test() {
    vector<int> a = {1, 5, 32, 7, 105, 2};
    select_sort(a);
    for (int i = 0, m = a.size(); i < m; i++) {
        cout << a[i] << " ";
    }
}