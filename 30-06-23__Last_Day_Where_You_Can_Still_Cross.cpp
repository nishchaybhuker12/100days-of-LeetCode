class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo = 1, hi = cells.size(), ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canWalk(cells, row, col, mid)) {
                ans = mid;
                lo = mid + 1; 
            } else hi = mid - 1;
        }
        return ans;
    }
    bool canWalk(vector<vector<int>>& cells, int row, int col, int mid) {
        vector<vector<bool>> grid(row, vector<bool>(col, 0)); 
        for (int i = 0; i < mid; i++) grid[cells[i][0]-1][cells[i][1]-1] = 1;
        queue<pair<int, int>> q;
        for (int c = 0; c < col; c++) {
            if (grid[0][c] == 0) {
                q.push({0, c});
                grid[0][c] = 1; 
            }
        }
        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,1,-1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (r == row - 1) return true;
            for (int i = 0; i < 4; ++i) {
                int nr = r + delrow[i], nc = c + delcol[i];
                if (nr < 0 || nr == row || nc < 0 || nc == col || grid[nr][nc] == 1)     continue;
                grid[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
        return false;
    }
};