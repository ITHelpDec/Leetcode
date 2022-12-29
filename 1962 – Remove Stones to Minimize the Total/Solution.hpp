#ifndef Solution_h
#define Solution_h

#include <vector>
#include <queue>
#include <iostream>

class Solution {
public:
    int minStoneSum(const std::vector<int> &piles, int k) {
        std::priority_queue<int> pq(piles.begin(), piles.end());
        
        while (k--) {
            int top = pq.top();
            pq.pop();
            top = top - (top >> 1);
            pq.push(top);

            // print_pq(pq);
        }
        
        while (!pq.empty()) {
            solution += pq.top();
            pq.pop();
        }
        
        return solution;
    }
private:
    int solution = 0;
    
    void print_pq(std::priority_queue<int> pq_local) {
        std::cout << "pq: ";
        while (!pq_local.empty()) {
            std::cout << pq_local.top() << " ";
            pq_local.pop();
        } std::cout << std::endl;
    }
};

#endif /* Solution_h */
