#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

void adjust_heap(vector<int> &a, int parent, int length) {
    int temp = a[parent], j = parent * 2 + 1;
    while (j < length) {
        if (j + 1 < length && a[j] < a[j + 1]) {
            j++;
        }
        if (temp > a[j]) {
            break;
        } else {
            a[parent] = a[j];
            parent = j;
            j = 2 * parent + 1;
        }
    }
    a[parent] = temp;
}

void heap_sort(vector<int> &a) {
    int m = a.size();
    for (int i = m / 2 - 1; i >= 0; i--) {
        adjust_heap(a, i, m);
    }

    for (int i = m - 1; i >= 0; i--) {
        swap(a[i], a[0]);
        adjust_heap(a, 0, i);
    }
}

void test() {
    vector<int> a = {1, 8, 2, 5, 0};
    heap_sort(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
    }
}