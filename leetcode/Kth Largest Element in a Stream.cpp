class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> stream;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        this->size = k;
        for (auto num : nums) {
            this->stream.push(num);
            if (this->stream.size() > k) {
                this->stream.pop();
            }
        }
    }

    int add(int val) {
        this->stream.push(val);

        if (this->stream.size() > this->size) {
            this->stream.pop();
        }

        return this->stream.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */