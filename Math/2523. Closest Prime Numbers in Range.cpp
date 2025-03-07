//?T.C -->  O(Rlog(log(R)) + (R-L))         // S.C --> O(R)

class Solution {
    public:
        void sieveHelper(vector<bool>&isPrime, int &right)
        {
            isPrime[0] = false;
            isPrime[1] = false;
    
            for(int i=2; i*i <= right; i++)
            {
                if(isPrime[i] == true)
                {
                    for(int j = 2; i*j <= right; j++)
                    {
                        isPrime[i*j] = false;
                    }
                }
            }
        }
        vector<int> closestPrimes(int left, int right) {
            
            vector<bool>isPrime(right+1, true);
            sieveHelper(isPrime, right);
    
            vector<int>primes;
    
            for(int i = left; i <= right; i++)
            {
                if(isPrime[i] == true) 
                    primes.push_back(i);
            }
    
            int mn = INT_MAX;
            vector<int>ans = {-1,-1};
    
            for(int i=1; i < primes.size(); i++)
            {
                int diff = primes[i] - primes[i-1];
                if(diff < mn)
                {
                    mn = diff;
                    ans = {primes[i-1], primes[i]};
                }
            }
    
            return ans;
        }
    };