class Solution {
public:
    /**
     * @param key: A string you should hash
     * @param HASH_SIZE: An integer
     * @return: An integer
     */
    int hashCode(string &key, int HASH_SIZE) {
        // write your code here
        int sum = 0;
        for (auto &c : key) {
            sum *= 33;
            sum += c;
            sum %= HASH_SIZE;
        }
        return sum;
    }
};