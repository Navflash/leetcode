from collections import Counter


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        lookup = Counter(magazine)
        #print(lookup)
        for c in ransomNote:
            if lookup[c] == 0:
                return False
            lookup[c] -= 1
        return True