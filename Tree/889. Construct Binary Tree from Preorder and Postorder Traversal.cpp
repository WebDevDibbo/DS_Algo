//* Submitted at Feb 23, 2025 22:28
//? TC --> O(N) SC --> O(N)
class Solution {
    public:
        TreeNode* construct(int preStart, int postStart, int preEnd, vector<int>&preorder, vector<int>&postorder, unordered_map<int, int> &mp)
        {
            if(preStart > preEnd) 
                return NULL;
    
            TreeNode * root = new TreeNode(preorder[preStart]);
            if(preStart == preEnd)
            {
                return root;
            }
    
            int leftTreeRoot = preorder[preStart+1];
            int j = mp[leftTreeRoot];
    
            int treeSize = j - postStart + 1;
    
            root->left = construct(preStart+1, postStart, preStart+treeSize, preorder, postorder, mp);
            root->right = construct(preStart+treeSize+1, j+1, preEnd, preorder, postorder, mp);
    
            return root;
        }
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            
            int n = preorder.size();
            unordered_map<int, int> mp;
            for(int i=0; i<n; i++)
            {
                mp[postorder[i]] = i;
            }
            return construct(0, 0, n-1, preorder, postorder, mp);
        }
    };