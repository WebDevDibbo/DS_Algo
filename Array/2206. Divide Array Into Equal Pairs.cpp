//! TC --> O(N) SC --> O(N)
class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            int n = nums.size() / 2;
            unordered_map<int,int>mp;
    
            for(int &num:nums)
                mp[num]++;
    
            int cnt = 0;
            for(auto &it:mp)
            {
                if(it.second%2 == 0) cnt += it.second/2;
                else cnt += it.second/2;
            }
    
            return cnt == n;
        }
    };