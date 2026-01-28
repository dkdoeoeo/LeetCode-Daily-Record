
#define INF 1e18

typedef struct {
    int val;
    int r, c;
} Point;

typedef struct {
    long long cost;
    int r, c;
    int k;
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

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a; *a = *b; *b = temp;
}

void push(MinHeap* h, HeapNode node) {
    h->size++;
    int i = h->size;
    h->data[i] = node;
    while (i > 1 && h->data[i].cost < h->data[i / 2].cost) {
        swap(&h->data[i], &h->data[i / 2]);
        i /= 2;
    }
}

HeapNode pop(MinHeap* h) {
    HeapNode top = h->data[1];
    h->data[1] = h->data[h->size--];
    int i = 1;
    while (2 * i <= h->size) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = i;
        if (left <= h->size && h->data[left].cost < h->data[smallest].cost) smallest = left;
        if (right <= h->size && h->data[right].cost < h->data[smallest].cost) smallest = right;
        if (smallest != i) {
            swap(&h->data[i], &h->data[smallest]);
            i = smallest;
        } else break;
    }
    return top;
}

int cmpPoint(const void* a, const void* b) {
    return ((Point*)a)->val - ((Point*)b)->val;
}

int minCost(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = *gridColSize;
    
    int total_points = m * n;
    Point* points = (Point*)malloc(sizeof(Point) * total_points);
    int pIdx = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            points[pIdx].val = grid[i][j];
            points[pIdx].r = i;
            points[pIdx].c = j;
            pIdx++;
        }
    }

    qsort(points, total_points, sizeof(Point), cmpPoint);
    
    int* processed_idx = (int*)calloc(k + 1, sizeof(int));

    long long*** dist = (long long***)malloc(m * sizeof(long long**));
    for(int i=0; i<m; i++){
        dist[i] = (long long**)malloc(n * sizeof(long long*));
        for(int j=0; j<n; j++){
            dist[i][j] = (long long*)malloc((k + 1) * sizeof(long long));
            for(int t=0; t<=k; t++) dist[i][j][t] = -1; // -1 代表 INF
        }
    }

    MinHeap* pq = createHeap(m * n * (k + 1) + 2000);
    
    dist[0][0][0] = 0;
    HeapNode startNode = {0, 0, 0, 0};
    push(pq, startNode);
    
    long long ans = -1;
    int dirs[2][2] = {{0, 1}, {1, 0}};

    while (pq->size > 0) {
        HeapNode top = pop(pq);
        int r = top.r;
        int c = top.c;
        int used_k = top.k;
        long long cost = top.cost;
        
        if (dist[r][c][used_k] != -1 && cost > dist[r][c][used_k]) continue;

        if (r == m - 1 && c == n - 1) {
            ans = cost;
            break;
        }
        
        for (int i = 0; i < 2; i++) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                long long newCost = cost + grid[nr][nc];
                if (dist[nr][nc][used_k] == -1 || newCost < dist[nr][nc][used_k]) {
                    dist[nr][nc][used_k] = newCost;
                    HeapNode next = {newCost, nr, nc, used_k};
                    push(pq, next);
                }
            }
        }
        
        if (used_k < k) {
            int next_k = used_k + 1;
            int limitVal = grid[r][c];
            
            while (processed_idx[next_k] < total_points) {
                int currIdx = processed_idx[next_k];
                Point p = points[currIdx];
                
                if (p.val > limitVal) {
                    break;
                }
                
                long long newCost = cost; 
                
                if (dist[p.r][p.c][next_k] == -1 || newCost < dist[p.r][p.c][next_k]) {
                    dist[p.r][p.c][next_k] = newCost;
                    HeapNode next = {newCost, p.r, p.c, next_k};
                    push(pq, next);
                }
                
                processed_idx[next_k]++;
            }
        }
    }
    
    free(points);
    free(processed_idx);
    free(pq->data);
    free(pq);

    return ans;
}