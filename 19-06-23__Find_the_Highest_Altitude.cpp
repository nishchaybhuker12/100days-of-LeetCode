class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int count = 0;
        int alt = 0;
        for(int i: gain){
            count = count+i;

            if(count>alt){
                alt = count;
            }
        }
        return alt;
    }
};
