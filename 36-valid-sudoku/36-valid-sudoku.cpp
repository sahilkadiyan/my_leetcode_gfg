class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         int i, j, k, l;
        
        //Checking each row
        for (i = 0; i < 9; i++)
        {
            unordered_map<char, int> m;
            for (j = 0; j < 9; j++)
                if (board[i][j] != '.')
                {
                    if (m[board[i][j]] > 0)
                        return false;
                    else
                        m[board[i][j]]++;
                } 
        }
        
        //Checking each column
        for (j = 0; j < 9; j++)
        {
            unordered_map<char, int> m;
            for (i = 0; i < 9; i++)
                if (board[i][j] != '.')
                {
                    if (m[board[i][j]] > 0)
                        return false;
                    else
                        m[board[i][j]]++;
                }
        }
        
        //Checking each 3X3 box
        for (k = 3; k < 10; k += 3)
            for (l = 3; l < 10; l += 3)
            {
                unordered_map<char, int> m;
                for (i = k-3; i < k; i++)
                    for (j = l-3; j < l; j++)
                        if (board[i][j] != '.')
                        {
                            if (m[board[i][j]] > 0)
                                return false;
                            else
                                m[board[i][j]]++;
                        }
            }
        
        return true;
    }
};