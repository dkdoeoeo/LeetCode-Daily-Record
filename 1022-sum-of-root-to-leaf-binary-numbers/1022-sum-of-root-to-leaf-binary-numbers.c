/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int temp(struct TreeNode* curNode,int cur){
    if(curNode->left == NULL && curNode->right == NULL){
        printf("%d\n",cur);
        return cur;
    }
    else if(curNode->left == NULL){
        return temp(curNode->right,(cur<<1) + curNode->right->val);
    }
    else if(curNode->right == NULL){
        return temp(curNode->left,(cur<<1) + curNode->left->val);
    }
    else{
        return temp(curNode->left,(cur<<1) + curNode->left->val) + temp(curNode->right,(cur<<1) + curNode->right->val);
    }
}
int sumRootToLeaf(struct TreeNode* root) {
    return temp(root,root->val);
}