#include <cstdint> // uint32_t

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            count += (int) (n & (uint32_t) 1);
            n >>= 1;
        }
        return count;
    }
};