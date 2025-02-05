// * Submitted at Feb 05, 2025 13:04
// ! TC --> O(N) SC --> O(1)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        if(s1 == s2) return true;
        int n = s1.length();
        int cnt = 0;
        int idx1 = 0, idx2 = 0;
        for(int i=0; i<n; i++)
        {
            if(s1[i] != s2[i] )
            {
                if(cnt < 1) idx1 = i;
                else idx2 = i;
                cnt++;
            }
        }
        if(cnt > 2) return false;
        if(s1[idx1] == s2[idx2] and s2[idx1] == s1[idx2]) return true;
        return false;
        
    }
};