class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        map<int,int>m;
        int mx=0;
        for(int i=0;i<arr.size();i++){
            m[arr[i]] = 1 + m[arr[i]-d];
            mx=max(mx,m[arr[i]]);
        }
        return mx;
    }
};