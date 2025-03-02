//* submitted at Mar 02, 2025 09:41
//? TC --> O(N + M + NLOGN) SC --> O(N+M)
class Solution {

    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            
            int n = nums1.size();
            int m = nums2.size();
    
            map<int,int>mp;
            for(int i=0; i<n; i++)
            {
                int id = nums1[i][0];
                int val = nums1[i][1];
                mp[id] += val;
            }
            for(int i=0; i<m; i++)
            {
                int id = nums2[i][0];
                int val = nums2[i][1];
                mp[id] += val;
            }
            vector<vector<int>>ans;
            for(auto &it:mp)
            {
                vector<int>tmp = {it.first,it.second};
                ans.push_back(tmp);
            }
            return ans;
        }
    };



    //? TC --> O(N + M) SC --> O(1)


    class Solution {
        public:
            vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
                
                int n = nums1.size();
                int m = nums2.size();
        
                int i = 0, j = 0;
                vector<vector<int>>ans;
        
                while(i<n and j<m)
                {
                    int id1 = nums1[i][0];
                    int id2 = nums2[j][0];
        
                    if(nums1[i][0] == nums2[j][0])
                    {
                        ans.push_back({ nums1[i][0], nums1[i][1] + nums2[j][1]});
                        i++, j++;
                    }
                    else if(id1 < id2)
                    {
                        ans.push_back(nums1[i]);
                        i++;
                    }
                    else if(id2 < id1)
                    {
                        ans.push_back(nums2[j]);
                        j++;
                    }
                }
                while(i<n)
                {
                    ans.push_back({nums1[i][0],nums1[i][1]});
                    i++;
                }
                while(j<m)
                {
                    ans.push_back({nums2[j][0],nums2[j][1]});
                    j++;
                }
                return ans;
            }
        };