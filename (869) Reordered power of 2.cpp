#include<bits/stdc++.h>

class Solution {
public:
    int numLength(int x) {
        int res = 0;
        if (x == 0) return 1;
        while (x > 0)
            res += 1,
            x /= 10;
        return res;
    }
    
    bool reorderedPowerOf2(int n) {
        map<int, set<string>> power2Length;
        for (int i = 0; (1LL << i) <= INT_MAX ; i++) {
            string thisStr = to_string(1 << i);
            sort(thisStr.begin(), thisStr.end());
            power2Length[numLength(1 << i)].insert(thisStr);
        }
        
        string nStr = to_string(n);
        sort(nStr.begin(), nStr.end());
        return power2Length[nStr.size()].count(nStr);
    }
};