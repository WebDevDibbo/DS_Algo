//* Submitted at Feb 27, 2025 23:25
//? TC --> O(N^3) SC --> O(N^2) WITHOUT MEMOIZATION 
//  IF YOU MEMOIZE THEN TC --> O(N^2)

class Solution {
    public:
        int subseq(int j, int k, unordered_map<int,int>&mp, vector<int>&arr)
        {
            int target = arr[k] - arr[j];
            if(mp.count(target) and mp[target] < j)
            {
                int i= mp[target];
                return subseq(i,j,mp,arr)+1;
            }
            return 2;
        }
        int lenLongestFibSubseq(vector<int>& arr) {
            
            int n = arr.size();
            unordered_map<int,int>mp;
            for(int i=0; i<n; i++)
            {
                mp[arr[i]] = i;
            }
        
            int mx_len = 0;
            for(int j=1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    int len = subseq(j,k,mp,arr);
                    if(len >= 3)
                        mx_len = max(mx_len, len);
                }
            }
            return mx_len;
        }
    };