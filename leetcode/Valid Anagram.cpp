class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> alpha;
        for (int i = 0; i < 26; ++i) {
            alpha['a' + i] = 0;
        }

        for (auto ch : s) {
            ++alpha[ch];
        }

        for (auto ch : t) {
            --alpha[ch];
        }

        for (int i = 0; i < 26; ++i) {
            if (alpha['a' + i] != 0) {
                return false;
            }
        }
        return true;
    }
};