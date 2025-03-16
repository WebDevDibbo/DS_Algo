//* TC --> O(Log(Maxrank∗Cars)) SC --> O(1)

class Solution {
    public:
        bool isPossible(long long mid , vector<int>&ranks, int cars)
        {
            long long carCount = 0;
            for(int i=0; i<ranks.size(); i++)
            {
                carCount += sqrt(mid / ranks[i]); // 
            }
            return carCount >= cars;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            
            int maxRank = *max_element(begin(ranks),end(ranks));
            long long left = 1;
            long long right = (long long) maxRank * ((long long )cars*(long long )cars);
            long long ans = -1;
    
            while(left <= right)
            {
                long long mid = left + (right - left) /2 ;
                if(isPossible(mid, ranks, cars))
                {
                    ans = mid;
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
    
            return ans;
        }
    };