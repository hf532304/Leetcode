class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> min_Heap;
    vector<int> max_Heap;
    MedianFinder() {
        make_heap(min_Heap.begin(), min_Heap.end());
        make_heap(max_Heap.begin(), max_Heap.end());
    }
    
    void addNum(int num) {
        if(max_Heap.size() == min_Heap.size()){           //if num smaller than the biggest num in max_Heap, insert to
            if(max_Heap.empty() || num > min_Heap[0]){
                min_Heap.push_back(num);
                push_heap(min_Heap.begin(), min_Heap.end(), greater<int>());    
            }
            else{            
                max_Heap.push_back(num);   
                push_heap(max_Heap.begin(), max_Heap.end());                
            }
        }
        else if(max_Heap.size() > min_Heap.size()){
            min_Heap.push_back(num);
            push_heap(min_Heap.begin(), min_Heap.end(), greater<int>());
        }
        else{
             max_Heap.push_back(num);   
             push_heap(max_Heap.begin(), max_Heap.end());           
        }
        if(max_Heap.size() == min_Heap.size() && max_Heap[0] > min_Heap[0]){        //adjust to make the min value in min_Heap larger than
            int tmp = max_Heap[0];                                                  //max value in max_Heap
            pop_heap(max_Heap.begin(), max_Heap.end(), less<int>()); 
            max_Heap.pop_back();
            max_Heap.push_back(min_Heap[0]);
            push_heap(max_Heap.begin(),max_Heap.end());
            pop_heap(min_Heap.begin(), min_Heap.end(), greater<int>());
            min_Heap.pop_back();
            min_Heap.push_back(tmp);
            push_heap(min_Heap.begin(), min_Heap.end(), greater<int>());
        }
        return;
    }
    double findMedian() {
        if((min_Heap.size()+max_Heap.size())%2 == 1){
            return (min_Heap.size() > max_Heap.size())? min_Heap[0] : max_Heap[0];
        }
        else{
            return (max_Heap[0]+min_Heap[0])/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
