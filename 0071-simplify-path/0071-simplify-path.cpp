class Solution {
public:
    string simplifyPath(string path) {
        vector<string> spl = this->split(path, slash);
        stack<string> st;
        for (string s : spl) {
            if (s == "" || s == ".") {
                continue;
            } else if (s == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(s);
            }
        }
        if (st.empty()) {
            return slash;
        }

        string result = "";
        while (!st.empty()) {
            string s = st.top();
            st.pop();
            result = slash + s + result;
        }
        return result;
    }
private:
    const string slash = "/";

    vector<string> split(string s, string delimiter) {
        int d = delimiter.length();
        int start = 0;
        int end = d;
        string token;
        vector<string> result;

        while ((end = s.find(delimiter, start)) != string::npos) {
            token = s.substr(start, end - start);
            start = end + d;
            result.push_back(token);
        }

        result.push_back(s.substr(start));
        return result;
    }

};