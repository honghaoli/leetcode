class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        size_ = size;
        sum_ = 0;
    }
    
    double next(int val) {
        data_.push_back(val);
        sum_ += val;
        if (data_.size() > size_) {
            sum_ -= data_.front();
            data_.pop_front();
        }
        return sum_ * 1.0 / data_.size();
    }

private:
    int size_;
    int sum_;
    list<int> data_;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */