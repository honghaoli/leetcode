class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size <= 1)
            return s;
        
        string revs(s);
        reverse(revs.begin(), revs.end());
        int start=0, end=0, length = 1;
        int _start = -1, _start_revs = -1, _length = 0;
        int istart, iend;
        //cout << size << endl;
        for (int shift = -size + 1; shift < size; shift++) {
            if (shift >=0) {
                istart = 0;
                iend = size - shift;
            } else {
                istart = -shift;
                iend = size;
            }
            //printf("shift %d, istart %d, iend %d\n", shift, istart, iend);    
            _start = -1;
            _start_revs = -1;
            _length = 0;
            for (int i = istart; i < iend; i++) {
                if (s[i] == revs[i + shift]) {
                    if (_start < 0) {
                        _start = i;
                        _start_revs = i + shift;
                    }
                    _length++;
                    //cout << _length << endl;
                    //cout << _start << ", " << _start_revs << endl;
                     if (_length > length && _start + _start_revs + _length == size) {
                            length = _length;
                            start = _start;
                    }
                } else {
                    _start = -1;
                    _start_revs = -1;
                    _length = 0;
                }
            }   
        }

        if (length == 1)
            start = 0;
        //printf("length %d, start %d, end %d\n", length, start, end);    
        return s.substr(start, length);
    }
};
