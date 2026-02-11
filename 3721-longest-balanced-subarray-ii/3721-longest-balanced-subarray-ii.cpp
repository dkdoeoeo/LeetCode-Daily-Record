
struct Node {
    int min_val;
    int max_val;
    int lazy;
} tree[400005];

void push(int v) {
    tree[2 * v].lazy += tree[v].lazy;
    tree[2 * v].min_val += tree[v].lazy;
    tree[2 * v].max_val += tree[v].lazy;
    
    tree[2 * v + 1].lazy += tree[v].lazy;
    tree[2 * v + 1].min_val += tree[v].lazy;
    tree[2 * v + 1].max_val += tree[v].lazy;
    
    tree[v].lazy = 0;
}


void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r) return;
    if (l == tl && r == tr) {
        tree[v].lazy += add;
        tree[v].min_val += add;
        tree[v].max_val += add;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), add);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
        tree[v].min_val = min(tree[2 * v].min_val, tree[2 * v + 1].min_val);
        tree[v].max_val = max(tree[2 * v].max_val, tree[2 * v + 1].max_val);
    }
}

int findFirstZero(int v, int tl, int tr, int l, int r) {
    if (l > r || tree[v].min_val > 0 || tree[v].max_val < 0) return -1;
    
    if (tl == tr) {
        return (tree[v].min_val == 0) ? tl : -1;
    }
    
    push(v);
    int tm = (tl + tr) / 2;

    int res = findFirstZero(2 * v, tl, tm, l, min(r, tm));
    if (res == -1) {
        res = findFirstZero(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    return res;
}

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= 4 * n; i++) {
            tree[i] = {0, 0, 0};
        }

        unordered_map<int, int> lastPos;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            int val = nums[right];
            int prev = -1;
            
            if (lastPos.count(val)) {
                prev = lastPos[val];
            }
            lastPos[val] = right;

            int delta = (val % 2 != 0) ? 1 : -1;
            update(1, 0, n - 1, prev + 1, right, delta);

            int leftIndex = findFirstZero(1, 0, n - 1, 0, right);
            
            if (leftIndex != -1) {
                maxLen = max(maxLen, right - leftIndex + 1);
            }
        }
        
        return maxLen;
    }
};