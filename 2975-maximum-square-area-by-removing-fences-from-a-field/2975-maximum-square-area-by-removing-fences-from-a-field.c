int cmpInt(const void* a, const void* b) {
    int val1 = *(int*)a;
    int val2 = *(int*)b;
    return (val1 > val2) - (val1 < val2);
}

int cmpLL(const void* a, const void* b) {
    long long val1 = *(long long*)a;
    long long val2 = *(long long*)b;
    if (val1 < val2) return -1;
    if (val1 > val2) return 1;
    return 0;
}

long long maximizeSquareArea(int m, int n, int* hFences, int hFencesSize, int* vFences, int vFencesSize) {
    int hCount = hFencesSize + 2;
    int* hArr = (int*)malloc(sizeof(int) * hCount);
    for(int i=0; i<hFencesSize; i++) hArr[i] = hFences[i];
    hArr[hFencesSize] = 1;
    hArr[hFencesSize+1] = m;
    
    qsort(hArr, hCount, sizeof(int), cmpInt);
    
    long long maxGapsSize = (long long)hCount * hCount; 
    long long* hGaps = (long long*)malloc(sizeof(long long) * maxGapsSize);
    int hGapIdx = 0;
    
    for (int i = 0; i < hCount; i++) {
        for (int j = i + 1; j < hCount; j++) {
            hGaps[hGapIdx++] = (long long)hArr[j] - hArr[i];
        }
    }
    
    qsort(hGaps, hGapIdx, sizeof(long long), cmpLL);
    
    int vCount = vFencesSize + 2;
    int* vArr = (int*)malloc(sizeof(int) * vCount);
    for(int i=0; i<vFencesSize; i++) vArr[i] = vFences[i];
    vArr[vFencesSize] = 1;
    vArr[vFencesSize+1] = n;
    
    qsort(vArr, vCount, sizeof(int), cmpInt);
    
    long long maxSide = -1;
    
    for (int i = 0; i < vCount; i++) {
        for (int j = i + 1; j < vCount; j++) {
            long long currentGap = (long long)vArr[j] - vArr[i];
            
            if (currentGap <= maxSide) continue;
            
            if (bsearch(&currentGap, hGaps, hGapIdx, sizeof(long long), cmpLL) != NULL) {
                maxSide = currentGap;
            }
        }
    }
    
    free(hArr);
    free(vArr);
    free(hGaps);
    
    if (maxSide == -1) return -1;
    
    long long MOD = 1e9 + 7;
    return (maxSide * maxSide) % MOD;
}