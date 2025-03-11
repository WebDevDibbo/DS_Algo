//! TC --> O(N)  SC --> O(1)

class Solution {
    public:
        int numberOfSubstrings(string s) {
            
            int n = s.length();
            int cnt = 0;
            int i=0, j=0;
            unordered_map<char,int>mp;
            while(j < n)
            {
                mp[s[j]]++;
                while(mp.size() == 3)
                {
                    cnt += (n-j);
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                j++;
            }
            return cnt;
        }
    };