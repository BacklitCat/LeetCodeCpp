#include <cstdint> // uint32_t

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0; // 务必
        uint32_t temp;
        for (int i = 0; i < 32; i++) {
            if (n & 1) {
                temp = 1;
                temp = temp << (31 - i);
                ret |= temp;
            }
            n = n >> 1;
        }
        return ret;
    }
};