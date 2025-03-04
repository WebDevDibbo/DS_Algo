
//* Submitted at Mar 04, 2025 10:54
//* O(LOGN)

class Solution {
    public:
        bool checkPowersOfThree(int n) {
            
            while(n != 0)
            {
                if(n%3 == 0 or n%3 == 1) n /= 3;
                else return false;
            }
            return true;
        }
    };

