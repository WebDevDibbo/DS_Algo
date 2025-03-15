//* TC --> O(LOGN)  SC --> O(1)

// binary search keno use holo bujte pari nai 
// sudu sorted thaklei je binary hobe eta bhul dharona 
// ?after using the dp approach time complexity was O(n*n)


class Solution {
    public:
        bool isPossible(vector<int>&nums, int &k, int mid)
        {
            int house = 0;
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i] <= mid)
                {
                    house++;
                    i++;
                }
            }
            return house >= k;
        }
        int minCapability(vector<int>& nums, int k) {
            
            int left = *min_element(begin(nums),end(nums));
            int right = *max_element(begin(nums),end(nums));
            int mid,res;
    
            while(left <= right)
            {
                mid = left + (right-left) / 2;
                if(isPossible(nums,k,mid))
                {
                    res = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            return res;
        }
    };