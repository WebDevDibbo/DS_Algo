//! TC --> O(NLog(Max(Candies)))  SC --> O(1)

class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            
            int n = candies.size(),mx= 0;
            long long total = 0;
            for(int &val:candies)
            {
                mx = max(mx,val);
                total += val;
            }    
            if(total < k) return 0;
            int i = 1, j = mx, res = 0;
            while(i <= j)
            {
                int mid = i + (j - i)/2;
                long long cnt = 0;
                for(int m=0; m<n; m++)
                {
                    cnt += candies[m]/mid;
                }
                if(cnt >= k)
                {
                    res = max(res,mid);
                    i = mid+1;
                }
                else
                    j = mid - 1;
    
            }
            return res;
        }
    };