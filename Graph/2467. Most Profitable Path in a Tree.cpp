//* Submitted at Feb 24, 2025 20:56
//? TC --> O(N) SC --> O(N)

class Solution {
    public:
        bool bobDfs(int time, int u, unordered_map<int, vector<int>> &adj, vector<bool>&visited, unordered_map<int, int> &bobInfo)
        {
            visited[u] = true;
            bobInfo[u] = time;
    
            if(u == 0) return true;
        
            for(auto &child : adj[u])
            {
                if(!visited[child])
                {
                   if(bobDfs(time+1, child, adj, visited, bobInfo) == true) 
                        return true;
                }
            }
    
            bobInfo.erase(u);
            return false;
        }
    
        void aliceDfs(int u, int inc, int time, unordered_map<int, vector<int>> &adj, unordered_map<int, int> &bobInfo, vector<bool> &visited, vector<int> &amount, int &mxInc)
        {
            visited[u] = true;
    
    
            if(bobInfo.count(u))
            {
                if(time == bobInfo[u])  inc += amount[u]/2;
                
                else if(time < bobInfo[u]) inc += amount[u];
                
            }
    
            else inc += amount[u];
            
            // kono node er size jodi 1 hoi tahole leaf node and current node jate src node er soman na hoi
            if(adj[u].size() == 1 and u != 0)
            {
                mxInc = max(mxInc, inc);
            }
            
    
            for(auto &child : adj[u])
            {
                if(!visited[child])
                {
                    aliceDfs(child, inc, time+1, adj, bobInfo, visited, amount, mxInc);
                }
            }
    
    
        }
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    
            int n = amount.size();
            unordered_map<int, vector<int>> adj;
            unordered_map<int, int> bobInfo;
            vector<bool>visited(n,false);
            for(int i=0; i<edges.size(); i++)
            {
               int u = edges[i][0];
               int v = edges[i][1];
               adj[u].push_back(v);
               adj[v].push_back(u);
            }
            int time = 0;
            bobDfs(time, bob, adj, visited, bobInfo);
    
            visited.assign(n,false);
            int mxInc = INT_MIN;
            int inc = 0;
            aliceDfs(0, inc, time, adj, bobInfo, visited, amount, mxInc);
    
            return mxInc;
        }
    };

