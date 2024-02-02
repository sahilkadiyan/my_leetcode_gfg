class Solution
{
public:
    vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool func(int i, int j, int k, vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();
        if (k == word.size())
            return true;
        bool ans = false;
        char ch = board[i][j];
        board[i][j] = '-1';
        for (auto &mov : moves)
        {
            int p = i + mov.first, q = j + mov.second;
            if (p >= 0 and q >= 0 and p < n and q < m and board[p][q] == word[k] and board[p][q] != '-1')
                ans |= func(p, q, k + 1, board, word);
        }
        board[i][j] = ch;
        return ans;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        bool ans = false;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == word[0] and func(i, j, 1, board, word))
                    return true;
        return false;
    }
};