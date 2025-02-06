//* Submitted at Feb 06, 2025 16:07
//! TC-->O(n^2) SC --> O(N)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        
        int s = nums.size();
        int cnt = 0;
        unordered_map<int,int>mp;
        for(int i=0; i<s; i++)
        {
            for(int j=i+1; j<s; j++)
            {
                int p1 = nums[i] * nums[j];
                mp[p1]++;
            }
        }

        for(auto &it:mp)
        {
            if(it.second >= 2)
            {
                int tuple = it.second * (it.second-1) / 2;
                cnt += tuple;
            }
        }
        return cnt*8;
    }
};