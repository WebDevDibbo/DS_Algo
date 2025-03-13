//* this question has 4 approach 
//* BELOW IS 3RD APPROACH
//? TC --> O(LOG(Q) * (Q+N)) SC --> O(N)


class Solution {
    public:
        int n, q;
        bool differenceArrayTech(vector<int>& nums, vector<vector<int>>& queries,
                                 int k) {
            vector<int> diffArray(n, 0);
    
            for (int i = 0; i <= k; i++) {
                int l = queries[i][0];
                int r = queries[i][1];
                int val = queries[i][2];
    
                diffArray[l] += val;
                if (r + 1 < n) {
                    diffArray[r + 1] -= val;
                }
            }
            int cumsum = 0;
            for (int i = 0; i < n; i++) {
                cumsum += diffArray[i];
                diffArray[i] = cumsum;
    
                if (nums[i] - diffArray[i] > 0)
                    return false;
            }
            return true;
        }
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    
            n = nums.size();
            q = queries.size();
    
            auto lambda = [](int x){
                return x == 0;
            };
    
            if(all_of(begin(nums),end(nums), lambda)) return 0;
    
    
            int left = 0, right = q-1, ans = -1;
            while (left <= right) {
    
                int mid = left + (right-left) / 2;
    
                if (differenceArrayTech(nums, queries, mid)) 
                {
                   ans = mid+1;
                   right = mid - 1;
                }
                else 
                    left = mid + 1;
            }
            return ans;
        }
    };