//* submitted at Feb 18, 2025 19:21
//? TC --> O(N) SC --> O(N)

class Solution {
    public:
        string smallestNumber(string pattern) {
            int n = pattern.size();
            string ans;
            int num = 1;
            stack<char>st;
            for(int i=0; i<=n; i++)
            {
                st.push(num + '0');
                num++;
                if(i == n or pattern[i] == 'I')
                {
                    while(!st.empty())
                    {
                        ans += st.top();
                        st.pop();
                    }
                }
            }
            return ans;
        }
    };