class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        helper(result, curr, s);
        return result;
    }
    void helper(vector<vector<string>>& result,vector<string>& currVector ,string& s) {
        if(s.size() == 0) {
            result.push_back(currVector);
            return;
        }
        for(int i =1;i<=s.size();i++) {
            string subString = s.substr(0,i);
            string currString = i<s.size() ? s.substr(i) : "";
            if(isPalindrome(subString)) {
                currVector.push_back(subString);
                helper(result, currVector, currString);
                currVector.pop_back();
            }
        }
    }
    bool isPalindrome(string s) {
        int size = s.size();
        int hsize = size/2;
        for(int i = 0;i<hsize;i++) {
            if(s[i] != s[size-i-1]) {
                return false;
            }
        }
        return true;
    }
};
