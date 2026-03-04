// 542. 01 Matrix
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two cells sharing a common edge is 1.

 

// Example 1:


// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]
// Example 2:


// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// mat[i][j] is either 0 or 1.
// There is at least one 0 in mat.
 


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = INT_MAX;
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();
            int row = cell.first;
            int col = cell.second;

            for (pair<int, int> direction : directions) {
                int newRow = row + direction.first;
                int newCol = col + direction.second;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && mat[newRow][newCol] > mat[row][col] + 1) {
                    mat[newRow][newCol] = mat[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }

        return mat;        
    }
};