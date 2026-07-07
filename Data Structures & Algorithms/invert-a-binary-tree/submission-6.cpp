class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
       if(!root) return nullptr;

       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
        TreeNode* nd = q.front();
        q.pop();
        swap(nd->left , nd->right);
        if(nd->left) q.push(nd->left);
        if(nd->right) q.push(nd->right);
       }

       return root;
    }
};
