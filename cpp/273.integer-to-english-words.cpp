class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        const int T = 4;
        vector<int> s(T, 0);
        long m = 1;
        for (int i = 0; i < T; i++) {
            s[i] = (num % (m * 1000)) / m;
            m *= 1000;
        }
        string result;
        for (int i = T - 1; i >= 0; i--) {
            if (s[i] != 0) {
                if (result != "") result += " ";
                result += segment(s[i]);
                if (i != 0)
                    result += " " + orders[i];
            }
        }
        return result;
    }

private:
    const vector<string> ones = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    const vector<string> teens = {"Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    const vector<string> tens = {"0", "Ten", "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    const vector<string> orders = {"", "Thousand","Million","Billion"};

    string segment(int n) {
        string result;
        int h = n / 100;
        int t = (n % 100) / 10;
        int s = n % 10;
        if (h > 0)
            result += ones[h] + " Hundred";
        if (t == 1) {
            if (result != "") result += " ";
            result += teens[s];
        } else if (t > 1) {
            if (result != "") result += " ";
            result += tens[t];
            if (s > 0)
                result += " " + ones[s];
        } else if (s > 0) {
            if (result != "") result += " ";
            result += ones[s];
        }
        return result;
    }
};
