class Solution {
public:

        int mod = 1000000007;
        int dr[4] = {1,0,-1,0};
        int dc[4] = {0,1,0,-1};

    bool isValid(int i,int j,vector<vector<int>>& grid){

        if(i<0 || i>= grid.size() || j<0 || j>= grid[0].size())
         return false;

        return true; 
    } 

    int dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& dp){

        if(dp[r][c] != -1)
         return dp[r][c];


        int ans = 1;

        for(int i=0;i<4;i++){

            int nr = r + dr[i];
            int nc = c + dc[i];

            if(isValid(nr,nc,grid) && grid[nr][nc] > grid[r][c]){
                ans = (ans%mod + dfs(nr,nc,grid,dp)%mod)%mod;
            }
        }

        return dp[r][c]=ans;
    } 

    int countPaths(vector<vector<int>>& grid) {
        
         vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
         long long cnt = 0;

         for(int i=0;i<grid.size();i++)
           for(int j=0;j<grid[0].size();j++)
             cnt = (cnt%mod + dfs(i,j,grid,dp)%mod)%mod;

        return (int)cnt%mod;     
    }
};