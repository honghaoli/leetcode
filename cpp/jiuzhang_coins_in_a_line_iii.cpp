#include<iostream>
#include<unordered_map>
#include <list>
#include <vector>
// https://mp.weixin.qq.com/s?__biz=MzA5MzE4MjgyMw==&mid=2649455794&idx=1&sn=5a85dd3cafcaf80589522b2db21d3b17&chksm=887e12babf099bace3eaf6941e526833d97556dedd0ec2578d9c790309bcae6c90655cd635a1&mpshare=1&scene=1&srcid=03177dZgf4Nze5VUHepEmnwU&key=58168eb9596d1eca8bc25037720153ac3a8c9441b456e6e6ece28a53675e20a5488ae7617817c334a503c11089c4eb285d7da98029834786dbba2aa6569ca8ebf59f3161706c6dc2a8024afb8777da1c&ascene=0&uin=MTUyMzg3NjAwMA%253D%253D&devicetype=iMac+MacBookAir7%252C1+OSX+OSX+10.12.3+build(16D32)&version=12020010&nettype=WIFI&fontScale=100&pass_ticket=0AiIToHJN8yqpuqRAsA5PaaQMJr8KtvlnZ2EqkX0zx%252BEZweRvHKyF%252ByjmycpUbVn

using namespace std;

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n = values.size();
        if (n < 3) return true;
        // dp[i][j] means in range num_i -- num_j, the max net score of the first player
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            dp[i][i] = values[i];
        }
        int net = find(values, 0, n - 1, dp);
        if (net >= 0) return true;
        else return false;
    }

private:
    int find(vector<int> &values, int i, int j, vector<vector<int>> &dp) {
        if (dp[i][j] >= 0) return dp[i][j];
        dp[i][j] = max(values[i] - find(values, i + 1, j, dp), values[j] - find(values, i, j - 1, dp));
        return dp[i][j];
    }
};


int main() {
    vector<int> test;
    Solution s;
    test = {3, 2, 2};
    cout << s.firstWillWin(test) << endl;
    test = {1, 2, 4};
    cout << s.firstWillWin(test) << endl;
    test = {1, 20, 4};
    cout << s.firstWillWin(test) << endl;
}