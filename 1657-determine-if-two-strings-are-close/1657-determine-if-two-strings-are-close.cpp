/*
abcdd
bcdaa

operation 1: order doesn't matter
operation 2: frequencies could be exchaged
=> if the distributions of frequencies match + the set of characters match
# a * b * c = (a * b) * c = a * (b * c)

1. diff length => false
2. any diff characters => false
3. same frequencies => selection sort => true

one unordered_set for 2nd
one unordered_map for 3rd

math + enumeration
T: O(n)
S: O(n)
*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length())
            return false;
        
        unordered_map<char, int> chars_to_occurences_1;
        unordered_map<char, int> chars_to_occurences_2;
        unordered_map<char, int> num_occurrence_to_freq_1;
        unordered_map<char, int> num_occurrence_to_freq_2;

        for (auto i = 0; i < word1.length(); ++i) {
            chars_to_occurences_1[word1[i]]++;
            chars_to_occurences_2[word2[i]]++;
        }

        for (auto pair : chars_to_occurences_1) {
            if (chars_to_occurences_2[pair.first] == 0)
                return false;

            num_occurrence_to_freq_1[pair.second] ++;
        }

        for (auto pair : chars_to_occurences_2) {
            num_occurrence_to_freq_2[pair.second] ++;
        }

        for (auto pair : num_occurrence_to_freq_1) {
            if (num_occurrence_to_freq_2[pair.first] != pair.second)
                return false;
        }

        return true;
    }
};