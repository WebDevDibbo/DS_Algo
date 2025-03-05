//* Submitted at Mar 05, 2025 10:19
//? TC --> O(N) SC --> O(1)

class Solution {
    public:
        long long coloredCells(int n) {
            
            long long time = 1, cells = 1;
            while(time <= n)
            {
                cells += 4 * (time-1);
                time++;
            }
            return cells;
        }
    };



//* TC --> O(1) SC --> O(1)
class Solution {
    public:
        long long coloredCells(int n) {
            return 1 + (2 * (long long)(n-1) * n);
        }
    };