/*63. Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int m, n;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& obstacleGrid) {
        // base case

        // 1. out of bounds
        if (i >= m || j >= n) {
            return 0;
        }
        // 2. obstacle
        if (obstacleGrid[i][j] == 1) {
            return 0;
        }
        // 3. reached the end
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = solve(i + 1, j, obstacleGrid);
        int right = solve(i, j + 1, obstacleGrid);

        return dp[i][j] = down + right;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        dp.resize(m, vector<int>(n, -1));

        return solve(0, 0, obstacleGrid);
    }
};