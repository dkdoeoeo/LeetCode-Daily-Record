#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int to;
    long long weight;
    int next;
} Edge;

typedef struct {
    int u;
    long long cost;
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

void push(MinHeap* h, int u, long long cost) {
    h->size++;
    int i = h->size;
    h->data[i].u = u;
    h->data[i].cost = cost;
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

int minCost(int n, int** edges, int edgesSize, int* edgesColSize) {
    int* head = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) head[i] = -1;

    Edge* adj = (Edge*)malloc(sizeof(Edge) * edgesSize * 2);
    int edgeCount = 0;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[edgeCount].to = v;
        adj[edgeCount].weight = w;
        adj[edgeCount].next = head[u];
        head[u] = edgeCount++;

        adj[edgeCount].to = u;
        adj[edgeCount].weight = (long long)2 * w;
        adj[edgeCount].next = head[v];
        head[v] = edgeCount++;
    }

    long long* dist = (long long*)malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++) dist[i] = -1; // -1 代表 INF

    MinHeap* pq = createHeap(edgesSize * 2 + n);
    
    dist[0] = 0;
    push(pq, 0, 0);

    while (pq->size > 0) {
        HeapNode top = pop(pq);
        int u = top.u;
        long long d = top.cost;

        if (dist[u] != -1 && d > dist[u]) continue;
        
        if (u == n - 1) {
            free(head); free(adj); free(dist); free(pq->data); free(pq);
            return d;
        }

        for (int i = head[u]; i != -1; i = adj[i].next) {
            int v = adj[i].to;
            long long newDist = d + adj[i].weight;

            if (dist[v] == -1 || newDist < dist[v]) {
                dist[v] = newDist;
                push(pq, v, newDist);
            }
        }
    }

    long long ans = dist[n - 1];

    free(head);
    free(adj);
    free(dist);
    free(pq->data);
    free(pq);

    return ans;
}