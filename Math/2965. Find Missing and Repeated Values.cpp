//* Submitted at Mar 06, 2025 11:31
//? TC --> O(n^2) SC --> O(N^2)

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            
            unordered_map<int,int>mp;
            int n = grid.size();
            for(auto &vec:grid)
            {
                for(auto &val : vec)  mp[val]++;
            }
            int a = -1, b = -1;
            for(int i=1; i<=n*n; i++)
            {
                if(!mp.count(i)) b = i;
                else if(mp[i] == 2) a = i;
            }
            return {a,b};
        }
    };



//? TC --> O(n^2) SC --> O(1)

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            
            
            int n = grid.size();
            long long m = n*n;
            
            long long gridSum = 0;
            long long gridSquareSum = 0;
    
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    gridSum += grid[i][j];
                    gridSquareSum += grid[i][j] * grid[i][j];
                }   
            }
    
            long long expectedSum = (m * (m + 1)) / 2;
            long long expectedSquareSum = (m * (m + 1) * (2 * m + 1)) / 6;
    
            long long sumDiff = gridSum - expectedSum;
            long long squareSumDiff = gridSquareSum - expectedSquareSum;
    
            int a = (squareSumDiff/sumDiff + sumDiff) / 2;
            int b = (squareSumDiff/sumDiff - sumDiff) / 2;
    
            return {a,b};
        }
    };