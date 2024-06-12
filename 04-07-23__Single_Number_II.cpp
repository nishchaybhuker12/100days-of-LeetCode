class Solution {
public:
    int singleNumber(vector<int>& nums) 
        {
        vector<int> freq(32,0)  ;
        
        for(auto x : nums)
        {
            for(int i=0;i<32;i++)
            {
                if(x&(1<<i))
                    freq[i]++ ;
            }
        }
        
        int ans = 0 ;
        
        for(int i=0;i<32;i++)
        {
            int f = freq[i] ;
            
            f = f%3 ;
            
            if(f)
                ans = ans + (1<<i) ;
        }
        
       
        
        return ans ;
    }
};