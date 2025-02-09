//* Submitted at Feb 09, 2025 12:05
//? TC --> o(N) SC --> O(N)
// ![nums[i] - i != nums[j] - j] --> re-arrange the ordering

class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            
            int n = nums.size();
            long long cnt = 0;
            for(int i=0; i<n; i++)
            {
                nums[i] = nums[i] - i;
            }
            unordered_map<int,int>mp;
            mp[nums[0]] = 1;
    
            for(int i = 1; i<n; i++)
            {
                int countofnums = mp[nums[i]];
                int totalnums = i;
                int badpairs = totalnums - countofnums;
                cnt += badpairs;
                mp[nums[i]]++;
            }
            return cnt;
        }
    };