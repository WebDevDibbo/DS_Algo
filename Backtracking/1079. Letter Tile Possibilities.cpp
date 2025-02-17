//* Submitted at Feb 17, 2025 17:12
//* TC --> O(N!)  SC --> O(N * N!)
class Solution {
    public:
        void solve(vector<bool>&tmp, string &tiles, int &n, unordered_set<string>&st, string &s)
        {
    
            for(int j=0; j<n; j++)
            {
                if(tmp[j]) continue;
    
                s += tiles[j];  
    
                st.insert(s);
                tmp[j] = true;
                
                solve(tmp, tiles, n, st, s);
                
                s.pop_back();
                tmp[j] = false;
            }
        }
        int numTilePossibilities(string tiles) {
            int n = tiles.size();
            unordered_set<string>st;
            vector<bool>tmp(n,false);
            string s;
            solve(tmp, tiles, n, st, s);
            return st.size();
        }
    };