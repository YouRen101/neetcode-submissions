class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;

        while(cur){
            if(!cur->left){
                k--;
                if(!k){
                    return cur->val;
                }
                cur = cur->right;
            }
            else{
                TreeNode* pre = cur->left;
                while(pre->right && pre->right != cur)
                    pre = pre->right;
                if(!pre->right){
                    pre->right = cur;
                    cur = cur->left;
                }
                else{
                    pre->right = nullptr;
                    k--;
                    if(!k) return cur->val;
                    cur = cur->right;
                }
            }
        }
        return 0;
    }
};
