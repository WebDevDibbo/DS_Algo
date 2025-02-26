
// Submitted at Feb 26, 2025 23:52
// TC --> O(N) SC --> O(1)

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            
            int n = nums.size();
    
            int maxSum = nums[0], minSum = nums[0];
            int currmaxsum = nums[0], currminsum = nums[0];
    
            for(int i=1; i<n; i++)
            {
                
                currmaxsum = max(nums[i], currmaxsum+nums[i]);
                maxSum = max(maxSum, currmaxsum);
    
                currminsum = min(nums[i], currminsum+nums[i]);
                minSum = min(minSum, currminsum);
    
            }
            return max(maxSum, abs(minSum));
        }
    };