//* Submitted at Feb 11, 2025 10:53
//? TC --> O(N*M) SC --> O(1)
class Solution {
    public:
        string removeOccurrences(string s, string part) {
    
            int n = s.length();
            int m = part.length();
            
            while(true)
            {
                int res = s.find(part);
        //string::npos == string::npos // if it will find the occurence res will give idx, otherwise string::npos
                if(res == string::npos) break;
    
                s.erase(res,m);
            }
            return s;
        }
    };

//* Submitted at Feb 11, 2025 11:00
//? TC --> O(N*M) SC --> O(M)

class Solution {
    public:
        bool solve(stack<char>&st, int &m, string &part)
        {
            stack<char>tmp = st;
            for(int i=m-1; i>=0; i--)
            {
                if(part[i] != tmp.top()) return false;
                tmp.pop();
            }
            return true;
        }
        string removeOccurrences(string s, string part) {
    
            int n = s.length();
            int m = part.length();
            
            stack<char>st;
    
            for(int i=0; i<n; i++)
            {
                st.push(s[i]);
    
                if(st.size() >= m and solve(st,m,part))
                {
                    for(int i=0; i<m; i++) st.pop();
                }
            }
            string ans;
            while(!st.empty())
            {
                ans += st.top();
                st.pop();
            }
            reverse(begin(ans),end(ans));
            return ans;
        }
    };