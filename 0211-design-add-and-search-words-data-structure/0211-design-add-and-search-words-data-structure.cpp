class WordDictionary {
    struct Zobrist {
        uint64_t table[30][26];

        Zobrist() {
            std::random_device rd;
            std::mt19937_64 gen(rd());

            for (auto& pos_vec: table) {
                for (auto& bucket: pos_vec) {
                    bucket = gen();
                }
            }
        }
    };

    static const Zobrist z;

    std::vector<string> words_vec[30];
    std::unordered_set<uint64_t> words_set[30];

    template <class It1, class It2>
    static constexpr bool fuzzy_equal(It1 st1, It1 ed1, It2 st2) noexcept {
        while (st1 != ed1) {
            if (*st1 != *st2 && *st2 != '.')
                return false;
            st1++;
            st2++;
        }
        return true;
    }

public:
    WordDictionary() = default;

    void addWord(string word) {
        const int sz = word.size();

        words_vec[sz].push_back(word);

        uint64_t word_hash = 0;
        
        for (int i = 0; i < sz; i++) {
            word_hash ^= z.table[i][word[i] - 'a'];
        }
        
        words_set[sz].insert(word_hash);

        if (sz >= 1) {
            for (int i = 0; i < sz; i++) {
                words_set[sz].insert(word_hash ^ z.table[i][word[i] - 'a']);
            }
        }
    }
    
    bool search(string word) const {
        const int sz = word.size();
        int dot_pos[3];
        int dot_len = 0;
        uint64_t word_hash = 0;

        for (int i = 0; i < sz; i++) {
            if (word[i] == '.') {
                dot_pos[dot_len++] = i;
            } else {
                word_hash ^= z.table[i][word[i] - 'a'];
            }
        }

        if (dot_len <= 1) {
            return words_set[sz].count(word_hash);
        } else if (dot_len == 2) {
            for (int i = 0; i < 26; i++) {
                if (words_set[sz].count(word_hash ^ z.table[dot_pos[0]][i])) {
                    return true;
                }
            }
        } else {
            if (words_vec[sz].size() * sz < 26 * 26) {
                const auto word_st = std::begin(word);
                for (const auto& w: words_vec[sz]) {
                    if (fuzzy_equal(std::begin(w), std::end(w), word_st))
                        return true;
                }

                return false;
            }

            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    const auto h = z.table[dot_pos[0]][i] ^ z.table[dot_pos[1]][j];
                    if (words_set[sz].count(word_hash ^ h))
                        return true;
                }
            }
        }
        return false;
    }
};

const WordDictionary::Zobrist WordDictionary::z;