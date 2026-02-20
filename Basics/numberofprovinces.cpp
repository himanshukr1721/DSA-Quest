// 547. Number of Provinces
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

 

// Example 1:


// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// Example 2:


// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3
 

// Constraints:

// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] is 1 or 0.
// isConnected[i][i] == 1

// isConnected[i][j] == isConnected[j][i]

class Solution {
public:
    void bfs(int start, vector<bool>& vis, vector<vector<int>>& isConnected){
        queue<int> q;
        int n = isConnected.size();

        q.push(start);
        vis[start] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int j =0; j<n; j++){
                if(isConnected[node][j] == 1 && !vis[j]){
                    vis[j] = true;
                    q.push(j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, 0);

        int province = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                bfs(i, vis, isConnected);
                province++;
            }
        }

        return province;
    }
};