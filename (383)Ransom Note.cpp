class Solution {
    vector<int> getFreq(string& s) {
        vector<int> freq(26, 0);
        for (auto& letter: s) 
            freq[letter - 'a']++;
        return freq;
    }
public:
    bool canConstruct(string ransomNote, string magazine) {
        auto freqRansom = getFreq(ransomNote), freqMag = getFreq(magazine);
        for (int i = 0; i < 26; ++i) {
            if (freqRansom[i] > freqMag[i]) {
                return false;
            }
        }
        return true;
    }
};