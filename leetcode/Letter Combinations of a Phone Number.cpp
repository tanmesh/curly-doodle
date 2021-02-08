class Solution {
    void dfs(int i, string currentCombination, string digits, vector<string> &letterCombinations, unordered_map<int, string> &telephone) {
        if (i >= digits.size()) {
            letterCombinations.push_back(currentCombination);
        }

        int number = digits[i] - '0';
        for (int j = 0; j < telephone[number].size(); ++j) {
            dfs(i + 1, currentCombination + telephone[number][j], digits, letterCombinations, telephone);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }

        vector<string> letterCombinations;

        unordered_map<int, string> telephone;

        telephone[2] = "abc";
        telephone[3] = "def";
        telephone[4] = "ghi";
        telephone[5] = "jkl";
        telephone[6] = "mno";
        telephone[7] = "pqrs";
        telephone[8] = "tuv";
        telephone[9] = "wxyz";

        dfs(0, "", digits, letterCombinations, telephone);

        return letterCombinations;
    }
};