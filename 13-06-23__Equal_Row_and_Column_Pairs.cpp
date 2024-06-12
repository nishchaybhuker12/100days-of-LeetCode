class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        vector<vector<int>> ans = grid;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n;j++){
                swap(grid[i][j],grid[j][i]);
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i] == ans[j]){
                    count++;
                }
            }
        }
        return count;
    }
};