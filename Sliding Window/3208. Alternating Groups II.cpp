//? TC --> O(N)  SC --> O(1)

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
    
            int total = 0;
            for(int i=0; i<k-1; i++)
            {
                colors.push_back(colors[i]);
            }
            int n = colors.size();
            int i = 0, j = 1;
    
            while(j < n)
            {
                
                if(colors[j] == colors[j-1]) i = j;
                if(j-i+1 == k)
                {
                    total++;
                    i++;
                }
                j++;
            };
            return total;
        }
    };