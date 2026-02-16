class Solution {
public:
    int reverseBits(int n) {
        unsigned int num = (unsigned int) n;
        unsigned int result = n;
        for(int i = 0;i < 32; i++){
            result <<= 1;          // shift result left
            result |= (n & 1);     // take last bit of n