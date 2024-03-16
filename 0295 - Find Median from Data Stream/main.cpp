// add O(log(n)) solution (priority queues)

class MedianFinder {
public:
    MedianFinder() = default;
    
    void addNum(int num) {
        if(maxh.empty() || num <= maxh.top()) {
            maxh.push(num);
            if(maxh.size() > minh.size() + 1) {
                minh.push(maxh.top());
                maxh.pop();
            }
        } else {
            minh.push(num);
            if(minh.size() > maxh.size()) {
                maxh.push(minh.top());
                minh.pop();
            }
        }
    }
    
    double findMedian() {
        return maxh.size() > minh.size() ? maxh.top() : (maxh.top() + minh.top()) / 2.0;
    }
private:
    std::priority_queue<int> maxh;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minh;
};

// there's a much more beautiful solution involving standard priority queues, but flipping the sign on one of them - this 

class MedianFinder {
public:
    MedianFinder() = default;
    
    void addNum(int num) {
        lhs.push(num);
        rhs.push(-lhs.top());
        lhs.pop();

        if (lhs.size() < rhs.size() {
            lhs.push(-rhs.top();
            rhs.pop();
        }
    }
    
    double findMedian() {
        return lhs.size() > rhs.size() ? lhs.top() : (lhs.top() + rhs.top()) / 2.0;
    }
private:
    std::priority_queue<int> lhs;
    std::priority_queue<int> rhs;
};
