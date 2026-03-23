// 1594. Maximum Non Negative Product in a Matrix
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.

// Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.

// Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.

// Notice that the modulo is performed after getting the maximum product.

 

// Example 1:


// Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
// Output: -1
// Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
// Example 2:


// Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
// Output: 8
// Explanation: Maximum non-negative product is shown (1 * 1 * -2 * -4 * 1 = 8).
// Example 3:


// Input: grid = [[1,3],[0,-4]]
// Output: 0
// Explanation: Maximum non-negative product is shown (1 * 0 * -4 = 0).
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 15
// -4 <= grid[i][j] <= 4

class Solution {
public:
    pair<long long,long long> dp[16][16];
    bool vis[16][16];
    const long long MOD = 1e9 + 7;

    pair<long long,long long> solve(int i,int j,vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
      
        if(i==n-1 && j==m-1){
            return {grid[i][j],grid[i][j]};
        }
      
        if(vis[i][j]) return dp[i][j];
        vis[i][j] = true;

        long long maxi_p = LLONG_MIN;
        long long mini_p = LLONG_MAX;

        if(j+1<m){
            auto res = solve(i,j+1,grid);
            long long first = grid[i][j] * res.first;
            long long second = grid[i][j] * res.second;
            maxi_p = max({maxi_p,first,second});
            mini_p = min({mini_p,first,second});
        }
        if(i+1<n){
            auto res = solve(i+1,j,grid);
            long long first = grid[i][j] * res.first;
            long long second = grid[i][j] * res.second;
            maxi_p = max({maxi_p,first,second});
            mini_p = min({mini_p,first,second});
        }
        return dp[i][j] = {mini_p,maxi_p};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        memset(vis,false,sizeof(vis));

        auto res = solve(0, 0, grid);
        if (res.second < 0) return -1;
        return res.second % MOD;
    }
};