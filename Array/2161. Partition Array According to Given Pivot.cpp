// Submitted at Mar 03, 2025 10:21
// TC --> O(3N) ~= O(N) SC --> 0(N)

class Solution {

    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int>ans;
            int n = nums.size();
    
            for(int i=0; i<n; i++)
            {
                if(nums[i] < pivot)  ans.push_back(nums[i]);
                
            }
            for(int i=0; i<n; i++)
            {
                if(nums[i] == pivot)  ans.push_back(nums[i]);
            }
    
            for(int j = 0; j<n; j++)
            {
                if(nums[j] > pivot)  ans.push_back(nums[j]);
            }
            return ans;
        }
    };






// TC --> O(2N) ~= O(N) SC --> 0(1) space is not considered as an auxiliary 
class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int n = nums.size();
            vector<int>ans(n);
    
            int lesscnt = 0, equalcnt = 0;
            for(int i=0; i<n; i++)
            {
                if(nums[i] < pivot) lesscnt++;
                else if(nums[i] == pivot) equalcnt++;
            }
            int i = 0, j = lesscnt, k = lesscnt + equalcnt;
            for(int &num : nums)
            {
                if(num < pivot) 
                {
                    ans[i] = num;
                    i++;
                }
                else if(num == pivot)
                {
                    ans[j] = num;
                    j++;
                }
                else
                {
                    ans[k] = num;
                    k++;
                }
            }
            return ans;
        }
    };




    
//* TC -> O(2N) ~= O(N) SC -> O(1) 
//? they are saying that it is one pass solution but however you are traverse every single element twice using i and j pointer i --> n , 0 <-- j
class Solution {
        public:
            vector<int> pivotArray(vector<int>& nums, int pivot) {
                int n = nums.size();
                vector<int>ans(n);
        
                int i = 0, j = n-1;
                int x = 0, y = n-1;
                while(i < n and j>= 0)
                {
                    if(nums[i] < pivot)
                    {
                        ans[x++] = nums[i];
                    }
                    if(nums[j] > pivot)
                    {
                        ans[y--] = nums[j];
                        
                    }
                    i++, j--;
                }
        
                while(x <= y)
                    ans[x++] = pivot;
                
                
                return ans;
            }
        };





