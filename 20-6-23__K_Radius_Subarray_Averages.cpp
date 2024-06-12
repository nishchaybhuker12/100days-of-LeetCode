class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans;

        if(nums.size()>=2*k+1)
        {
            int i=0,j=2*k+1;
            long long int sum=0;
        
            for(int p=0;p<2*k+1;p++) 
                sum+=nums[p];
            
            for(int i=0;i<k;i++)
                ans.push_back(-1);
        
            while(j<nums.size())
            {
                ans.push_back(sum/(2*k+1));
                sum+=nums[j]-nums[i];
                j++;
                i++;
            }

            ans.push_back(sum/(2*k+1));
        }
    
        while(ans.size()<nums.size()) 
            ans.push_back(-1);
        return ans;
    }
};