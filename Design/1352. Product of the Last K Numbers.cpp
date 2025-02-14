//* Submitted at Feb 14, 2025 14:15
// ? TC --> o(1) SC--> o(N)

class ProductOfNumbers {
    public:
        vector<int>stream;
        int n;
        ProductOfNumbers() 
        {
            stream.clear();
            n = 0;
        }
        
        void add(int num) { 
            
           if(num==0){
                stream.clear();
                n = 0;
           }
           else{
                if(stream.empty()) stream.push_back(num);
                else{
                    stream.push_back(stream[n-1] * num);
                }
                n++;
           }
           
        }
        
        int getProduct(int k) {
            if(k > n){
                return 0;
            }else if(k == n){
                return stream[n-1];
            }
    
            return stream[n - 1] / stream[n - k - 1];
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */