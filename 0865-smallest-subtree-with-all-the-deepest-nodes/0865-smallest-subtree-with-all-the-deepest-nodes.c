/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a,int b){
    if(a > b){
        return a;
    }
    return b;
}

int checkDeep(struct TreeNode* cur,int curDeep){
    if(cur == NULL){
        return curDeep - 1;
    }

    return max(checkDeep(cur->left,curDeep+1),checkDeep(cur->right,curDeep+1));
}

struct TreeNode* findAns(struct TreeNode* curNode, int curDeep, int deepest){
    if(curNode == NULL){
        return NULL;
    }

    if(curDeep == deepest){
        return curNode;
    }

    struct TreeNode* left = findAns(curNode->left,curDeep+1,deepest);
    struct TreeNode* right = findAns(curNode->right,curDeep+1,deepest);

    if(left && right){
        return curNode;
    }
    if(left){
        return left;
    }
    return right;
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    int deep = checkDeep(root,1);
    return findAns(root,1,deep);
}