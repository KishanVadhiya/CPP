// leetcode url -https://leetcode.com/problems/online-stock-span/description/
#include<iostream>
#include<stack>
using namespace std;
class StockSpanner {
    stack<pair<int,int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt=1;
        while(!st.empty() && price>=st.top().first){
            cnt+=st.top().second;
            st.pop();
        }
        st.push({price,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


int main() {
    StockSpanner* obj = new StockSpanner();
    cout << obj->next(100) << endl; // Output: 1
    cout << obj->next(80) << endl;  // Output: 1
    cout << obj->next(60) << endl;  // Output: 1
    cout << obj->next(70) << endl;  // Output: 2
    cout << obj->next(60) << endl;  // Output: 1
    cout << obj->next(75) << endl;  // Output: 4
    cout << obj->next(85) << endl;  // Output: 6
    delete obj;
    return 0;
}