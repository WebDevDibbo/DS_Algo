//* Submitted at Feb 20, 2025 13:34
//? TC --> O(2^N) SC --> O(N)

class Solution {
    public:
        void backtrack(int &n, string &ans, unordered_set<string>&st, string tmp)
        {
            if(tmp.size() == n) 
            {
                if(st.find(tmp) == st.end()) 
                    ans = tmp;
                return;
            }
            backtrack(n, ans, st, tmp + '0');
            backtrack(n, ans, st, tmp + '1');
        }
        string findDifferentBinaryString(vector<string>& nums) {
            
            unordered_set<string>st;
            int n = nums.size();
            string ans,tmp;
            for(string &s:nums) st.insert(s);
            
            backtrack(n, ans, st, tmp);
            return ans;
        }
    };




//* Submitted at Feb 20, 2025 12:15
//? TC --> O(N^N) SC --> O(N)

class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            
            unordered_set<int>st;
            int n = nums.size();
            string ans;
            for(string &s:nums)
            {
                int num = stoi(s,nullptr,2);
                st.insert(num);
            }
            for(int i=0; i<=n; i++)
            {
                if(st.find(i) == st.end())
                {
                    ans = bitset<16>(i).to_string();
                    break;
                }
            }
            return ans.substr(16-n,n);
        }
    };



//* Submitted at Feb 20, 2025 15:04
//? TC --> O(N) SC --> O(1)

class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            string ans;
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i][i] == '0')
                    ans += '1';
                else
                    ans += '0';
            }
            return ans;
        }
    };