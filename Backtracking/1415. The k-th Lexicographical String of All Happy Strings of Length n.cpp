//* Submitted at Feb 19, 2025 10:35
//  TC --> O(N * 2^N) SC --> O(N * 2^N)

class Solution {
    public:
        void checkHappyString(string &letters, int &n, vector<string>&happyString, string tmp)
        {
            if(tmp.size() == n)
            {
                happyString.push_back(tmp);
                return;
            }
    
            for(int i=0; i<letters.size(); i++)
            {
                if(!tmp.empty() and tmp.back() == letters[i]) continue;
                
                checkHappyString(letters, n, happyString, tmp + letters[i]);
            }
        }
        string getHappyString(int n, int k) {
    
            vector<string>happyString;
            string letters = "abc";
            string tmp;
    
            checkHappyString(letters, n, happyString, tmp);
    
            
            if(k > happyString.size()) return tmp;
            
            return happyString[k-1];
    
        }
    };




//? submitted at Feb 19, 2025 19:23
//  TC --> O(N * 2^N) SC --> O(N)


    class Solution {
        public:
            void checkHappyString(string &letters, int &n, string &ans, string tmp, int &k)
            {
                if(tmp.size() == n)
                {
                    k-=1;
                    if(k == 0) 
                        ans = tmp;
                    return;
                }
        
                for(int i=0; i<letters.size(); i++)
                {
                    if(!tmp.empty() and tmp.back() == letters[i]) continue;
                    
                    checkHappyString(letters, n, ans, tmp + letters[i], k);
                }
            }
            string getHappyString(int n, int k) {
        
                string letters = "abc";
                string tmp,ans;
        
                checkHappyString(letters, n, ans, tmp, k);
        
                
                if(k > n) return ans;
                
                return ans;
        
            }
        };