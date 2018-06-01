class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remain_bytes = 0;
        for (int n : data) {
            if (remain_bytes == 0) {
                remain_bytes = num_bytes(n);
                if (remain_bytes < 0) return false;
            } else {
                if (!check_prefix10(n)) return false;
            }
            remain_bytes--;
        }
        return remain_bytes == 0;
    }

private:
    int num_bytes(int n) {
        if (!get_bit(n, 7)) return 1;   // 1 byte data
        int i = 6;
        while (!get_bit(n, i) && i >= 3)
            i--;
        if (i == 6 || i < 3) return -1;       // wrong, there can only be 2,3,4 prefix 1s.
        return 7 - i;
    }

    inline bool check_prefix10(int n) {
        return get_bit(n, 7) && !get_bit(n, 6);
    }

    inline bool get_bit(int n, int i) {
        return (n >> i) & 1;
    }
};