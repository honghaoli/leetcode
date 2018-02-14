// LeetCode, Word Break II
// 动规，时间复杂度 O(n^2)，空间复杂度 O(n^2)
class Solution
{
  public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        // 长度为 n 的字符串有 n+1 个隔板
        vector<bool> f(s.length() + 1, false);

        // convert list of words into hashmap for O(1) time look-up.
        unordered_map<string, bool> dict;
        for (string &s : wordDict)
        {
            dict[s] = true;
        }
        // prev[i][j] 为 true，表示 s[j, i) 是一个合法单词，可以从 j 处切开 // 第一行未用
        vector<vector<bool>> prev(s.length() + 1, vector<bool>(s.length()));
        f[0] = true;
        for (size_t i = 1; i <= s.length(); ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (f[j] && dict.find(s.substr(j, i - j)) != dict.end())
                {
                    f[i] = true;
                    prev[i][j] = true;
                }
            }
        }
        vector<string> result;
        vector<string> path;
        gen_path(s, prev, s.length(), path, result);
        return result;
    }

  private:
    // DFS 遍历树，生成路径
    void gen_path(const string &s, const vector<vector<bool>> &prev,
                  int cur, vector<string> &path, vector<string> &result)
    {
        if (cur == 0)
        {
            string tmp;
            for (auto iter = path.crbegin(); iter != path.crend(); ++iter)
                tmp += *iter + " ";
            tmp.erase(tmp.end() - 1);
            result.push_back(tmp);
        }
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (prev[cur][i])
            {
                path.push_back(s.substr(i, cur - i));
                gen_path(s, prev, i, path, result);
                path.pop_back();
            }
        }
    }
};
