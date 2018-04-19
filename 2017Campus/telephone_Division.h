// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 这题其实和LeetCode的432题非常的像 其实应该是同一题
string originalDigits(string s) {
    vector<string> words = {"ZERO", "TWO",   "FOUR", "SIX",   "EIGHT",
                            "ONE",  "THREE", "FIVE", "SEVEN", "NICE"};
    vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    vector<int> distinct_char = {'Z', 'W', 'U', 'X', 'G',
                                 'O', 'R', 'F', 'V', 'I'};
    vector<int> counts(26, 0);
    string result;
    for (int i = 0; i < s.size(); i++) {
        counts[s[i] - 'A']++;
    }
    for (int i = 0; i < 10; i++) {
        int num = counts[distinct_char[i] - 'A'];
        for (int j = 0; j < words[i].size(); j++) {
            counts[words[i][j] - 'A'] -= num;
        }
        int num_convert = (nums[i] + 10 - 8) % 10;
        while (num--) {
            result += to_string(num_convert);
        }
    }
    sort(result.begin(), result.end());
    return result;
}
int test() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << originalDigits(s) << endl;
    }
    return 0;
}