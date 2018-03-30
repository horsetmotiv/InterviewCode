

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
/*
3
5 0
6 0
7 0
59
6 59

输出例子1:
6 0

*/
int test1() {
    int n;
    int class_hour, class_minute;
    int time_delay;
    cin >> n;
    vector<int> hour(n, 0), minute(n, 0);
    vector<int> hour_time(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> hour[i] >> minute[i];
        hour_time[i] = hour[i] * 60 + minute[i];
    }
    cin >> time_delay;
    cin >> class_hour >> class_minute;
    int target = class_hour * 60 + class_minute;
    sort(hour_time.begin(), hour_time.end());
    auto it =
        upper_bound(hour_time.begin(), hour_time.end(), target - time_delay);
    --it;
    cout << *it / 60 << " " << *it % 60 << endl;
    return 0;
}