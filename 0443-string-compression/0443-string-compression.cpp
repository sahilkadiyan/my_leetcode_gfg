class Solution {
public:
    int compress(vector<char>& chars) {    
        int index = 0;
        int i = 0;
        while (i < chars.size()) {
            char c = chars[i];
            int count = 0;
            while (i < chars.size() && chars[i] == c) {
                i++;
                count++;
            }

            chars[index] = c;
            index++;
            if (count > 1) {
                string s = to_string(count);
                for (int j = 0; j < s.size(); j++) {
                    chars[index] = s[j];
                    index++;
                }
            }
        }
        return index;
    }
};
