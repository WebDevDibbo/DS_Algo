//* Submitted at Feb 04, 2025 13:24
//! optimal TC --> O(n),  SC --> o(1)

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        int sum = nums[0];
        for(int i=1; i<n; i++)
        {
            if(nums[i] > nums[i-1]) 
            {
                sum += nums[i];
                mx = max(mx,sum);
            }
            else
            {
                sum = nums[i];
                mx = max(mx,sum);
            }
        }
        return mx;
    }
};