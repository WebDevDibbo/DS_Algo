//* Submitted at Feb 13, 2025 10:29
//? TC --> O(NLOGN) SC --> O(N)
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            
            int n = nums.size();
            int operation = 0;
            priority_queue<long,vector<long>,greater<long>>pq;
            for(int i=0; i<n; i++)
            {
                pq.push(nums[i]); // logn
            }
    
            while(!pq.empty())
            {
                if(pq.top() >= k) break;
                
                if(pq.size() >= 2)
                {
                    long x = pq.top();
                    pq.pop();
                    long y = pq.top();
                    pq.pop();
                    long newVal = min(x,y) * 2 + max(x,y);
                    pq.push(newVal);
                    operation++;
                }
            }
    
            return operation;
        }
    };