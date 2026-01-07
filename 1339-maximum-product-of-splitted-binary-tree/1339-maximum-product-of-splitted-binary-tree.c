/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

long long modmun = 1000000007;
int add(struct TreeNode* cur,int curMun){
    if(cur->left){
        curMun += add(cur->left,0);
    }

    if(cur->right){
        curMun += add(cur->right,0);
    }

    curMun += cur->val;

    return curMun;
}

long long findAns(struct TreeNode* cur,int curMun ,int total,long long* curans){
    if(cur->left){
        curMun += findAns(cur->left,0,total,curans);
    }

    if(cur->right){
        curMun += findAns(cur->right,0,total,curans);
    }

    curMun += cur->val;

    long long tempans = (long long)curMun * (total - curMun);

    if(tempans > *curans){
        *curans = tempans;
    }

    return curMun;
}

int maxProduct(struct TreeNode* root) {
    int total = add(root,0);
    long long ans = 0;
    findAns(root,0,total,&ans);
    return ans%modmun;
}