from collections import Counter


class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        powers = [2**n for n in range(32)]
        
        for p in powers:
            if Counter(str(p)) == Counter(str(n)):
                return True
            
        return False