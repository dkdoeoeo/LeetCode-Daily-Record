
typedef struct {
    long long val;
    int prev;
    int next;
    bool removed;
} Node;

typedef struct {
    long long sum;
    int u;
    int v;
} HeapNode;

typedef struct {
    HeapNode* data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->data = (HeapNode*)malloc(sizeof(HeapNode) * (capacity + 1));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

bool isSmaller(HeapNode a, HeapNode b) {
    if (a.sum != b.sum) return a.sum < b.sum;
    return a.u < b.u;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* h, HeapNode val) {
    h->size++;
    int i = h->size;
    h->data[i] = val;
    while (i > 1 && isSmaller(h->data[i], h->data[i / 2])) {
        swap(&h->data[i], &h->data[i / 2]);
        i /= 2;
    }
}

HeapNode pop(MinHeap* h) {
    HeapNode top = h->data[1];
    h->data[1] = h->data[h->size];
    h->size--;
    
    int i = 1;
    while (2 * i <= h->size) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = i;
        
        if (left <= h->size && isSmaller(h->data[left], h->data[smallest])) smallest = left;
        if (right <= h->size && isSmaller(h->data[right], h->data[smallest])) smallest = right;
        
        if (smallest != i) {
            swap(&h->data[i], &h->data[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
    return top;
}

int minimumPairRemoval(int* nums, int numsSize) {
    int n = numsSize;
    if (n <= 1) return 0;


    Node* nodes = (Node*)malloc(sizeof(Node) * n);
    int unsorted_count = 0;
    
    MinHeap* pq = createHeap(n * 2);

    for (int i = 0; i < n; i++) {
        nodes[i].val = nums[i];
        nodes[i].prev = i - 1;
        nodes[i].next = (i == n - 1) ? -1 : i + 1;
        nodes[i].removed = false;

        if (nodes[i].next != -1) {
            if (nodes[i].val > nums[nodes[i].next]) {
                unsorted_count++;
            }

            HeapNode hn = {nodes[i].val + nums[nodes[i].next], i, nodes[i].next};
            push(pq, hn);
        }
    }

    int ops = 0;


    while (unsorted_count > 0 && pq->size > 0) {
        HeapNode top = pop(pq);
        int u = top.u;
        int v = top.v;

        if (nodes[u].removed || nodes[v].removed || nodes[u].next != v || 
            (nodes[u].val + nodes[v].val != top.sum)) {
            continue;
        }

        int prev_u = nodes[u].prev;
        if (prev_u != -1 && nodes[prev_u].val > nodes[u].val) unsorted_count--;
        

        if (nodes[u].val > nodes[v].val) unsorted_count--;
        

        int next_v = nodes[v].next;
        if (next_v != -1 && nodes[v].val > nodes[next_v].val) unsorted_count--;


        nodes[u].val += nodes[v].val;
        nodes[v].removed = true;

        nodes[u].next = next_v;
        if (next_v != -1) nodes[next_v].prev = u;
        
        if (prev_u != -1 && nodes[prev_u].val > nodes[u].val) unsorted_count++;
        
        if (next_v != -1 && nodes[u].val > nodes[next_v].val) unsorted_count++;

        ops++;

        if (next_v != -1) {
            HeapNode hn = {nodes[u].val + nodes[next_v].val, u, next_v};
            push(pq, hn);
        }
        
        if (prev_u != -1) {
            HeapNode hn = {nodes[prev_u].val + nodes[u].val, prev_u, u};
            push(pq, hn);
        }
    }

    free(nodes);
    free(pq->data);
    free(pq);
    
    return ops;
}