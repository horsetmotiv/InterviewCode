#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 基数排序讲解的网址
// https://blog.csdn.net/yabber0914/article/details/52279537
void radixSort(vector<int> &a) {
    int radix = 10, divide = 1;
    int digitNum = 3;
    int m = a.size();
    vector<int> b(m, 0), count(radix, 0);
    for (int i = 0; i < digitNum; i++) {
        b = a;
        fill_n(count.begin(), radix, 0);
        for (int j = 0; j < m; j++) {
            int key = (b[j] / divide) % radix;
            count[key]++;
        }
        for (int j = 1; j < radix; j++) {
            count[j] = count[j] + count[j - 1];
        }
        for (int j = m - 1; j >= 0; j--) {
            int key = (b[j] / divide) % radix;
            count[key]--;
            a[count[key]] = b[j];
        }
        divide *= radix;
    }
}
void test() {
    vector<int> a = {1, 5, 32, 7, 105, 2};
    radixSort(a);
    for (int i = 0, m = a.size(); i < m; i++) {
        cout << a[i] << " ";
    }
}