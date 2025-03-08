//* T.C : O(n*k)     S.C : O(1)

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            
            int n = blocks.size();
            int mn = INT_MAX;
            for(int i=0; i<n; i++)
            {
                int oper = 0;
                int j = i ;
                int m = j+k;
                if(m > n) break;
                while(j < m and m <= n)
                {
                    if(blocks[j] == 'W') oper++;
                    j++;
                }
                mn = min(mn,oper);
            }
            return mn;
        }
    };


//? T.C : O(n)      S.C : O(1)
    class Solution {
        public:
            int minimumRecolors(string blocks, int k) {
                
                int n = blocks.size();
                int mn = INT_MAX;
                int i=0, j = 0, oper = 0;
                while(j < n)
                {
                    
                    if(blocks[j] == 'W') oper++;
                    if(j-i + 1 == k)
                    {
                        mn = min(mn,oper);
                        if(blocks[i] == 'W') oper--;
                        i++;
                    }
                    j++;
                }
                
                return mn;
            }
        };