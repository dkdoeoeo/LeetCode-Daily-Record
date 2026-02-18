bool hasAlternatingBits(int n) {
    unsigned int b = n ^ (n >> 1);
    return ((b+1) & b) == 0;
}