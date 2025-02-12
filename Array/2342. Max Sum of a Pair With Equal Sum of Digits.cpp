//* Submitted at Feb 12, 2025 17:29
//? TC --> O(n * m) m = number of digits && SC --> O(n)

class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            
            int n = nums.size();
            unordered_map<int,int>mp;
            int maxSum = -1;
    
            for(int i=0; i<n; i++)
            {
                int val = nums[i];
                int sum = 0;
    
                while(val != 0)
                {
                    int digit = val%10;
                    sum += digit;
                    val /= 10;
                }
    
                // 9 --> 18, 9 --> 36, 7 --> 43, 4 --> 13, 7 --> 7
                if(mp.find(sum) != mp.end())
                {
                    int prevVal  = mp[sum];
                    int pairsum = prevVal + nums[i];
                    maxSum = max(maxSum,pairsum);
                    mp[sum] = max(prevVal,nums[i]);
                }
                else mp[sum] = nums[i];
                
            }
    
            return maxSum;
        }
    };


//* Submitted at Feb 12, 2025 18:40
//? TC --> O(n * m) m = number of digits && SC --> O(82) which is constant O(1)
class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            
            int n = nums.size();
            // nums[i] can maximum 10^9 = 1000000000 this value digit sum is 1, maximum can be 999999999 = digitsum is 81 size
            int digit[82] = {0};
            int maxSum = -1;
    
            for(int i=0; i<n; i++)
            {
                int val = nums[i];
                int sum = 0;
    
                while(val != 0)
                {
                    sum += (val%10);
                    val /= 10;
                }
    
                if(digit[sum] > 0)
                {
                    maxSum = max(maxSum, digit[sum] + nums[i]);
                    digit[sum] = max(digit[sum], nums[i]);
                }
                else digit[sum] = nums[i];
                
            }
    
            return maxSum;
        }
    };