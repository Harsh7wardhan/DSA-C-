// 1 dfs
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        int index = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[index])
                {
                    if (search(i, j, index, board, word))
                        return true;
                }
            }
        }

        return false;
    }

    bool search(int i, int j, int index, vector<vector<char>> &board, string &word)
    {
        int m = board.size(), n = board[0].size();

        if (index == word.size())
            return true;
        if (i < 0 or j < 0 or i >= m or j >= n)
            return false;

        bool all = false;
        if (word[index] == board[i][j])
        {
            char temp = word[index];
            board[i][j] = '#';
            all = search(i + 1, j, index + 1, board, word) or search(i - 1, j, index + 1, board, word) or
                  search(i, j + 1, index + 1, board, word) or search(i, j - 1, index + 1, board, word);

            board[i][j] = temp;
        }

        return all;
    }
};

// 2 dfs
bool exist(vector<vector<char>> &board, string word)
{
    for (unsigned int i = 0; i < board.size(); i++)
        for (unsigned int j = 0; j < board[0].size(); j++)
            if (dfs(board, i, j, word))
                return true;
    return false;
}

bool dfs(vector<vector<char>> &board, int i, int j, string &word)
{
    if (!word.size())
        return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
        return false;
    char c = board[i][j];
    board[i][j] = '*';
    string s = word.substr(1);
    bool ret = dfs(board, i - 1, j, s) || dfs(board, i + 1, j, s) || dfs(board, i, j - 1, s) || dfs(board, i, j + 1, s);
    board[i][j] = c;
    return ret;
}