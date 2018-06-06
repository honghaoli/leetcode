/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

// measure the number of matched chars for each two words
// then according to the match number returned from guess, we can try to guess the secret
// we mark each word as visited if it's already guessed.
// pre calculated table:
// matches[i][j] = {x1, x2, x3...}
//          means:
//              for word[i], all the other words has j chars matched with it, 
//                          those words index are x1, x2, x3...
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int n = wordlist.size();
        int len = wordlist.at(0).size();
        // precalculate diff O(n^2)
        matches = vector<vector<unordered_set<int>>>(n, vector<unordered_set<int>>(len + 1, unordered_set<int>()));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int m = match(wordlist[i], wordlist[j]);
                matches[i][m].insert(j);
                matches[j][m].insert(i);
            }
        }
        // try to guess
        visited = vector<bool>(n, false);

        int guess_id = 0;
        visited[guess_id] = true;
        int m = master.guess(wordlist[guess_id]);
        restriction[guess_id] = m;
        while (m != len) {
            // find the next guess id
            guess_id = find_next(guess_id, m);
            if (guess_id < 0) return;   // should never happen
            m = master.guess(wordlist[guess_id]);
            restriction[guess_id] = m;
        }
    }

private:
    vector<vector<unordered_set<int>>> matches;
    vector<bool> visited;
    unordered_map<int, int> restriction;    // restriction[i] = k: ith word has k matches with secret

    int match(string &w1, string &w2) {
        int m = 0;
        for (int i = 0; i < w1.size(); ++i) {
            if (w1[i] == w2[i]) {
                ++m;
            }
        }
        return m;
    }

    int find_next(int guess_id, int m) {
        auto &set = matches[guess_id][m];
        for (auto it = set.begin(); it != set.end(); ++it) {
            if (visited[*it]) continue;
            // next word must be consistent with all previous results
            bool found = true;
            for (auto iter = restriction.begin(); iter != restriction.end(); ++iter) {
                if (matches[iter->first][iter->second].count(*it) == 0) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return *it;
            }
        }
        // should never happen
        return -1;
    }

};

