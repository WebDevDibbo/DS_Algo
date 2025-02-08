//*  Submitted at Feb 08, 2025 19:01
// * Approach - 1
// * TC --> O(logn) SC --> O(n)

class NumberContainers {
    public:
        unordered_map<int,int>idxmp;
        unordered_map<int,set<int>>numbermp;
        NumberContainers() {}
        
        void change(int index, int number) {
            
            if(idxmp.find(index) != idxmp.end())
            {
                numbermp[idxmp[index]].erase(index);
                if(numbermp[idxmp[index]].size() == 0)
                {
                    numbermp.erase(idxmp[index]);
                }
            }
            idxmp[index] = number;
            numbermp[number].insert(index);
        }
        
        int find(int number) {
           
           if(numbermp.find(number) != numbermp.end())
           {
            int val = *numbermp[number].begin();
            return val;
           }
            return -1;
        }
    };



// * Approach - 2
// * TC --> O(logn) SC --> O(n)

class NumberContainers {
    public:
        unordered_map<int,int>idxmp;
        unordered_map<int, priority_queue<int, vector<int>, greater<int>> >numbermp;
        NumberContainers() {}
        
        void change(int index, int number) {
            idxmp[index] = number;
            numbermp[number].push(index);
        }
        
        int find(int number) {
           
           if(numbermp.find(number) != numbermp.end())
           {
              
              auto &pq = numbermp[number];
    
              while(!pq.empty())
              {
    
                int idx = pq.top();
    
                if(idxmp[idx] == number) return idx;
    
                pq.pop();
    
              }
    
           }
            return -1;
        }
    };
