#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

void insert_sort(vector<int> &a) {
    int m = a.size();
    for (int i = 0; i < m; i++) {
        int j = i;
        while (j > 0 && a[j] < a[j - 1]) {
            swap(a[j], a[j - 1]);
            j--;
        }
    }
}

void test() {
    vector<int> a = {1, 5, 32, 7, 105, 2};
    insert_sort(a);
    for (int i = 0, m = a.size(); i < m; i++) {
        cout << a[i] << " ";
    }
}