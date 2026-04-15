/*2515. Shortest Distance to Target String in a Circular Array
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the array's beginning.

Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is words[(i - 1 + n) % n], where n is the length of words.
Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.

Return the shortest distance needed to reach the string target. If the string target does not exist in words, return -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        bool found = false;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                found = true;

                int diff = abs(i - startIndex);
                int dist = min(diff, n - diff);

                ans = min(ans, dist);
            }
        }
        if(found == true) {
            return ans;
        } else {
            return -1;
        }
    }
};
