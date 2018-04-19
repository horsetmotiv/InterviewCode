#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
int Partition(vector<int> &a, int left, int right) {
    int i = left, j = right;
    int x = a[left];
    while (true) {
        while (a[++i] < x && i < right - 1)
            ;
        while (a[--j] > x)
            ;
        if (i >= j) {
            break;
        }
        swap(a[i], a[j]);
    }
    swap(a[left], a[j]);
    return j;
}
void QuickSort(vector<int> &a, int left, int right) { //半开半闭区间
    if (left < right - 1) {
        int position = Partition(a, left, right);
        QuickSort(a, left, position);
        QuickSort(a, position + 1, right);
    }
}

void test() {
    vector<int> a = {1, 5, 32, 7, 105, 2};
    int m = a.size();
    QuickSort(a, 0, m);
    for (int i = 0, m = a.size(); i < m; i++) {
        cout << a[i] << " ";
    }
}