//* Submitted at Mar 01, 2025 10:14
//? TC --> O(N) SC --> O(1)
class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size();
            vector<int>ans;
            for(int i=0; i<n-1; i++)
            {
                if(nums[i] == nums[i+1])
                {
                    nums[i] *= 2;
                    nums[i+1] = 0;
                }
            }
            int cnt = 0;
            for(int i=0; i<n; i++)
            {
                if(nums[i] == 0) cnt++;
                else ans.push_back(nums[i]);
            }
            while(cnt--) ans.push_back(0);
            return ans;
        }
    };