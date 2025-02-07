//* Submitted at Feb 07, 2025 19:57
//! TC --> O(N)  SC --> O(N)

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        int n = queries.size();
        vector<int>ans;

        unordered_map<int,int>colormp;
        unordered_map<int,int>ballmp;

        for(auto &query:queries)
        {
            int ball = query[0];
            int color = query[1];
            if(ballmp.count(ball))
            {
                int currentball = ballmp[ball];
                colormp[currentball]--;
                if(colormp[currentball] == 0) colormp.erase(currentball);
            }
            
            ballmp[ball] = color;
            colormp[color]++;
            
            ans.push_back(colormp.size());
 
        }

        return ans;
    }
};