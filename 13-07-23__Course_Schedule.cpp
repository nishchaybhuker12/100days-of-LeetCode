class Solution {
public:
   bool detectcycle(vector<vector<int>>&v,int src,vector<int>&rst,vector<int>&vis){
        vis[src]=1;
        rst[src]=1;
        for(auto x:v[src]){
            if(!vis[x]&&detectcycle(v,x,rst,vis)){
                return true;
            }
            else if(rst[x]==1)
            return true;
        }
        rst[src]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>v(numCourses);
        stack<int>s;
        vector<int>vis(numCourses),rst(numCourses);
        for(auto x: prerequisites){
            v[x[1]].push_back(x[0]);
        }
        for(int i=0;i<numCourses;i++){
           if(!vis[i])
           if(detectcycle(v,i,rst,vis))
           return false;
        }
       
        return true;
    }
};