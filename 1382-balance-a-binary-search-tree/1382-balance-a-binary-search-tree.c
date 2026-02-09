/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* list[20000];
int idx = 0;

void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    list[idx++] = root;
    inorder(root->right);
}

struct TreeNode* build(int l, int r) {
    if (l > r) return NULL;
    int mid = (l + r) / 2;
    struct TreeNode* root = list[mid];
    root->left = build(l, mid - 1);
    root->right = build(mid + 1, r);
    
    return root;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    idx = 0;
    
    inorder(root);

    return build(0, idx - 1);
}