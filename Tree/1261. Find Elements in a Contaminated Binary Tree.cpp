//* Submitted at Feb 21, 2025 10:55
//* TC --> O(N) SC --> O(N)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
    public:
        unordered_set<int>st;
        FindElements(TreeNode* root) {
    
            queue<TreeNode*>q;
            root->val = 0;
    
            q.push(root);
    
            while(!q.empty())
            {
                TreeNode* tmp = q.front();
                st.insert(tmp->val);
                q.pop();
    
                if(tmp->left)
                {
                    tmp->left->val = 2 * tmp->val + 1;
                    q.push(tmp->left);
                }
    
                if(tmp->right)
                {
                    tmp->right->val = 2 * tmp->val + 2;
                    q.push(tmp->right);
                }
            }
        }
        
        bool find(int target) {
            if(st.find(target) != st.end()) return true;
            return false;
        }
    };



//* Submitted at Feb 21, 2025 11:15
//* TC --> O(N) SC --> O(N)
class FindElements {
    public:
        void DFS(TreeNode* root, int x, unordered_set<int>&st)
        {
            if(!root) return;
            if(root->left)
            {
                root->left->val = 2 * x + 1;
                st.insert(root->left->val);
                DFS(root->left, root->left->val, st);
            }
            if(root->right)
            {
                root->right->val = 2 * x + 2;
                st.insert(root->right->val);
                DFS(root->right, root->right->val, st);
            }
        }
        unordered_set<int>st;
        FindElements(TreeNode* root) {
            root->val = 0;
            st.insert(0);
            DFS(root, 0, st);
        }
        
        bool find(int target) {
            if(st.find(target) != st.end()) return true;
            return false;
        }
    };
        