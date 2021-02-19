class cmp {
public:
    bool operator() (const string &a, const string &b) const {
        return a + b > b + a;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numsInString;
        for (auto num : nums) {
            numsInString.push_back(to_string(num));
        }

        sort(numsInString.begin(), numsInString.end(), cmp());

        if (numsInString[0] == "0") {
            return numsInString[0];
        }

        string result = "";
        for (auto it : numsInString) {
            result += it;
        }

        return result;
    }
};