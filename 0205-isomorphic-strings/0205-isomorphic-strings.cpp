class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Use hashmaps to save the replacement for every character in the first string...
        unordered_map <char , char> rep;
        unordered_map <char , bool> used;
        // Traverse all elements through the loop...
        for(int idx = 0 ; idx < s.length() ; idx++) {
            // If rep contains s[idx] as a key...
            if(rep.count(s[idx])) {
                // Check if the rep is same as the character in the other string...
                // If not, the strings can’t be isomorphic. So, return false...
                if(rep[s[idx]] != t[idx])
                    return false;
            }
            // If no replacement found for first character, check if the second character has been used as the replacement for any other character in the first string...
            else {
                if(used[t[idx]])
                    return false;
                // If there exists no character whose replacement is the second character...
                // Assign the second character as the replacement of the first character.
                rep[s[idx]] = t[idx];
                used[t[idx]] = true;
            }
        }
        // Otherwise, the strings are not isomorphic.
        return true;
    }
};