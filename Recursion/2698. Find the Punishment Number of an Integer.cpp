//* Submitted at Feb 15, 2025 15:14
//! TC --> O(n * 2^(log10(n^2))) SC --> O(n * log10(n^2))
// ? Recusion + Memoization

class Solution {
    public:
        bool findPunishNumber(string &str,int i,int currSum, int &target, vector<vector<int>> &memo)
        {
            if(i == str.length())
            {
                return currSum == target;
            }
            if(currSum > target) return false;
            if(memo[i][currSum] != -1) return memo[i][currSum];
    
            for(int j=i; j<str.length(); j++)
            {
                string substring = str.substr(i,j-i+1);
                int num = stoi(substring);
    
                if(findPunishNumber(str, j+1, currSum + num, target, memo))
                    return true;
    
            }
    
            return memo[i][currSum] = false;
        }
        int punishmentNumber(int n) {
            
            int punish = 0;
            for(int i=1; i<=n; i++)
            {
                int decimal = i*i;
                string str = to_string(decimal);
                vector<vector<int>> memo(str.length(), vector<int>(i+1,-1));
                if(findPunishNumber(str, 0, 0, i, memo))
                {
                    punish += decimal;
                }
            }
            return punish;
        }
    };