//* Submitted at Feb 01, 2025 09:30

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        int n = nums.size();
        bool flag = false;
        for(int i=1; i<n; i++)
        {
            if(nums[i]%2 == 0 and nums[i-1]%2 != 0)continue;
            else if(nums[i]%2 != 0 and nums[i-1]%2 == 0)continue;
            else 
            {
                flag = true;
                break;
            }

        }
        
        if(n == 1) return true;
        return flag == false ? true : false;
    }
};