//* Submitted at Feb 28, 2025 21:20
// ?TC --> O(N * M) SC --> O(N * M) 
class Solution {
    public:
        int n,m;
        vector<vector<int>>dp;
        int superSequence(string &str1, string &str2, int i, int j)
        {
            if(i == n or j == m) return dp[i][j] = 0;
    
            if(dp[i][j] != -1) return dp[i][j];
    
            if(str1[i] == str2[j])
            {
                return dp[i][j] = 1 + superSequence(str1, str2, i+1, j+1);
            }
    
            return dp[i][j] = max(superSequence(str1,str2,i+1,j), superSequence(str1,str2,i,j+1));
            
        }
        string shortestCommonSupersequence(string str1, string str2) {
            n = str1.length();
            m = str2.length();
            dp.assign(n+1, vector<int>(m+1, -1));
            superSequence(str1, str2, 0, 0);
            
            string scs;
            int i=0, j=0;
            while(i < n and j < m)
            {
                if(str1[i] == str2[j])
                {
                    scs += str1[i];
                    i++, j++;
                }
                else if(dp[i+1][j] > dp[i][j+1])
                {
                    scs += str1[i];
                    i++;
                }
                else 
                {
                    scs += str2[j];
                    j++;
                }
            }
    
            while(i < n) scs += str1[i++];
            while(j < m) scs += str2[j++];
    
            return scs;
    
        }
    };