/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

void DFS(struct TreeNode* curNode,int direction,int len,int* curAns){
    printf("%d\n",*curAns);
    if(direction == 1){
        if(curNode->right){
            DFS(curNode->right,0,len+1,curAns);
        }
        *curAns = max(len,*curAns);
        if(curNode->left){
            DFS(curNode->left,1,1,curAns);
        }
    }
    else{
        if(curNode->left){
            DFS(curNode->left,1,len+1,curAns);
        }
        *curAns = max(len,*curAns);
        if(curNode->right){
            DFS(curNode->right,0,1,curAns);
        }
    }
}


int longestZigZag(struct TreeNode* root) {
    int* curAns = (int*)malloc(sizeof(int));
    *curAns = 0;
    if(root->left && root->right){
        DFS(root->left,1,1,curAns);
        DFS(root->right,0,1,curAns);
    }
    else if(root->left){
        DFS(root->left,1,1,curAns);
    }
    else if(root->right){
        DFS(root->right,0,1,curAns);
    }
    return *curAns;
}