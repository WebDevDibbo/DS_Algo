//* Submitted at Feb 10, 2025 14:30
//? TC --> O(N)  SC --> O(N)

class Solution {
    public:
        string clearDigits(string s) {
            stack<char>st;
            int n = s.size();
    
            int i=1;
            st.push(s[0]);
            while(i<n)
            {
                if(s[i] >= '0' and s[i] <= '9')
                {
                    if(!st.empty() and st.top() >= 'a' and st.top() <= 'z')
                    {
                        st.pop();
                    }
                    else st.push(s[i]);
                }
                else st.push(s[i]);
                i++;
            }
            s.clear();
            while(!st.empty())
            {
                s += st.top();
                st.pop();
            }
            reverse(s.begin(),s.end());
            return s;
        }
    };



//* Submitted at Feb 10, 2025 20:39
//? TC --> O(N)  SC --> O(1)
class Solution {
    public:
        string clearDigits(string s) {
            int n = s.length();
            int i=0,j=0;
            while(i<n)
            {
                if(isdigit(s[i]))
                {
                    j = max(j-1,0);
                }
                else
                {
                    s[j] = s[i];
                    j++;
                }
                i++;
            }
    
            return s.substr(0,j);
        }
    };