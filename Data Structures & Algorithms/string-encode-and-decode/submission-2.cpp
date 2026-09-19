class Solution {
public:

    string encode(vector<string>& strs) {
        string result="";
        for(int i = 0;i<strs.size();i++) {
            result += strs[i];
            result += "?p?";
        }
        return result;
    }

    vector<string> decode(string s) {
        int prev = 0;
        vector<string> result = {};
        int curr = 0;
        if(s == "") {
            return result;
        }
        for(int i = 0;i<s.size()-2;i++) {
            cout<<s.substr(i,3)<<endl;
            if(s.substr(i,3) == "?p?") {
                result.push_back(s.substr(prev, curr));
                prev = i+3;
                i = i+2;
                curr = 0;
                continue;
            }
            curr++;
        }
        return result;
    }
};
