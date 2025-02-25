//? submitted at Feb 25, 2025 14:23
// * TC --> O(N)  SC --> O(1)

class Solution {
    public:
        
        int numOfSubarrays(vector<int>& arr) {
            int n = arr.size();
            int odd = 0, even = 1, sum = 0, res = 0;
            int m = 1e9+7;
            for(int i=0; i<n; i++)
            {
               sum += arr[i];
               if(sum%2 == 0)
               {
                 res = (res + odd) % m;
                 even++;
               }
               else
               {
                 res = (res + even) % m;
                 odd++;
               }
            }
            return res;
        }
    };