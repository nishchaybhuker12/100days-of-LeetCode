class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int x = grid.size();
        int y = grid[0].size();
        int count = 0;
        for(int i = 0; i<x; i++){
            for(int j = 0; j<y; j++){
                if(grid[i][j]<0){
                    count++;
                }
            }
        }
        return count;
    }
};