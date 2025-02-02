//* submitted at Feb 02, 2025 13:22
class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        int peak = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] > nums[(i+1)%n]) peak++;
        }

        return peak <= 1;

    }
};