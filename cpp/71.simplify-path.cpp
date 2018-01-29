class Solution {
public:
    string simplifyPath(string path) {
        int s = 0, e = 1;
        int n = path.size();
        if (n <= 1) return path;

        vector<string> folders;
        while (e < n + 1) {
            if (path[e] == '/' || e == n) {
                if (e == s + 1)  {       // two // at the same place;
                } else if (e == s + 2 && path[e - 1] == '.') {
                } else if (e == s + 3 && path.substr(s+1, 2) == "..") {
                    if (!folders.empty())
                        folders.pop_back();
                } else {
                    // normal new folder
                    folders.push_back(path.substr(s + 1, e - s - 1));
                }
                s = e;
                e = s + 1;
            } else {
                e++;
            }
        }

        if (folders.empty()) return "/";

        // combine all
        string result = "";
        for (auto &s : folders) {
            result.append("/" + s);
        }
        return result;
    }
};
