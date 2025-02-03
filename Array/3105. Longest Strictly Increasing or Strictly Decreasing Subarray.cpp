// * Submitted at Feb 03, 2025 13:06
// ? Bruteforce
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int longest = 1;
        for(int i=0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                bool increasing = true, decreasing = true;

                for(int k = i; k<j; k++)
                {
                    if(nums[k] <= nums[k+1])
                    {
                        decreasing = false;
                    }
                    if(nums[k] >= nums[k+1])
                    {
                        increasing = false;
                    }
                }
                if(increasing or decreasing)
                {
                    longest = max(longest,j-i+1);
                }
                else break;
            }
        }
        return longest;
    }
};


//* Submitted at Feb 03, 2025 14:02
//? Optimal
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, decr = 1, mx = 1;
        for(int i=1; i<n; i++)
        {
            if(nums[i] > nums[i-1])
            {
                inc++;
                mx = max({mx,inc,decr});
                decr = 1;
            }
            else if(nums[i] < nums[i-1])
            {
                decr++;
                mx = max({mx,inc,decr});
                inc = 1;
            }
            else{
                inc=1;
                decr=1;
            }
        }
        return mx;
    }
};