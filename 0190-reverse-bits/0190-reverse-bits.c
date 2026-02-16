int reverseBits(int n) {
    uint32_t ans = n;
    ans = ((ans >> 1) & 0x55555555) | ((ans & 0x55555555) << 1);
    
    ans = ((ans >> 2) & 0x33333333) | ((ans & 0x33333333) << 2);
    
    ans = ((ans >> 4) & 0x0F0F0F0F) | ((ans & 0x0F0F0F0F) << 4);
    
    ans = ((ans >> 8) & 0x00FF00FF) | ((ans & 0x00FF00FF) << 8);
    
    ans = (ans >> 16) | (ans << 16);
    
    return ans;
}