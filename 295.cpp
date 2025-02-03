class MedianFinder {
public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        size++;
        if (maxheap.empty()) {
            maxheap.push(num);
            return;
        }

        if (num <= maxheap.top()) {
            maxheap.push(num);
        } else {
            minheap.push(num);
        }
        
        if (maxheap.size() - minheap.size() == 2) {
                minheap.push(maxheap.top());
                maxheap.pop();
        }

        if (minheap.size() - maxheap.size() == 2) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        
    }
    
    double findMedian() {
        if (maxheap.size() > minheap.size()) {
            return maxheap.top();
        }

        if (minheap.size() > maxheap.size()) {
            return minheap.top();
        } 

        return ((double)maxheap.top() + minheap.top()) / 2;
        
    }


    std::priority_queue<int, std::vector<int>> maxheap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;
    int size;

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
