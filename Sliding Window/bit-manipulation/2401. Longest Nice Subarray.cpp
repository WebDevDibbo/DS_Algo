// this problem has 4 approaches 
//! O(N^4) --> O(N^3) --> O(N^2) --> O(N)


// TC --> O(N^2)  SC --> O(1)
class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            
            int n = nums.size();
            int res = 1;
            for(int i=0; i<n; i++)
            {
                int mask = 0;
                for(int j=i; j<n; j++)
                {
                    if((mask & nums[j]) == 0)
                    {
                        mask |= nums[j];
                        res = max(res,j-i+1);
                    }
                    else break;
                }
            }
            return res;
        }
    };



// TC --> O(N)  SC --> O(1)

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            
            int n = nums.size();
            int res = 1, mask = 0;
            int i=0,j=0;
            while(j < n)
            {
                while((mask & nums[j]) != 0)
                {
                    mask ^= nums[i];
                    i++;
                }
                res = max(res, j-i+1);
                mask |= nums[j];
                j++;
            }
            return res;
        }
    };