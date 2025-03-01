//* Submitted at Mar 01, 2025 10:14
//? TC --> O(N) SC --> O(N)
// 3 loop
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

    //? TC --> O(N) SC --> O(1)
    // 2 loop 
    class Solution {
        public:
            vector<int> applyOperations(vector<int>& nums) {
                int n = nums.size();
                for(int i=0; i<n-1; i++)
                {
                    if(nums[i] == nums[i+1])
                    {
                        nums[i] *= 2;
                        nums[i+1] = 0;
                    }
                }
                int i=0,j=0;
                while(i < n)
                {
                    if(nums[i] != 0)
                    {
                        swap(nums[j],nums[i]);
                        j++;
                    }
                    i++;
                }
                return nums;
            }
        };

    

    //? TC --> O(N) SC --> O(1)
    // one loop 1 pass solution            
        class Solution {
            public:
                vector<int> applyOperations(vector<int>& nums) {
                    int n = nums.size();
                    int j = 0;
                    for(int i=0; i<n; i++)
                    {
                        if( i+1 < n and nums[i] == nums[i+1])
                        {
                            nums[i] *= 2;
                            nums[i+1] = 0;
                        }
                        if(nums[i] != 0)
                        {
                            if(j != i)  swap(nums[i],nums[j]);
                            j++;
                        }
            
                    }
                    return nums;
                    
                }
            };