#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

//冒泡排序
void bubble_sort(vector<int> &a) {
    int m = a.size();
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

//冒泡排序2
void bubble_sort2(vector<int> &a) {
    int m = a.size();
    for (int i = 0; i < m - 1; i++) {
        bool flag = true;
        for (int j = 0; j < m - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                flag = false;
            }
        }
        if (flag) {
            break;
        }
    }
}

// 冒泡的改进版

void test() {
    vector<int> a = {1, 5, 32, 7, 105, 2};
    bubble_sort2(a);
    for (int i = 0, m = a.size(); i < m; i++) {
        cout << a[i] << " ";
    }
}