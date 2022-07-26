class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (p->val==root->val || q->val==root->val ) return root;
       TreeNode* l=lowestCommonAncestor(root->left,p,q);
       TreeNode* r=lowestCommonAncestor(root->right,p,q);
        if (l!=NULL && r!=NULL) return root;
        if(l!=NULL) return l;
        if(r!=NULL) return r;
        return NULL;
    }
};