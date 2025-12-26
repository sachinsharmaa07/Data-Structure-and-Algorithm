#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class StockSpanner {

public:stack<pair<int,int>> st; 
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;

        // Merge spans of smaller or equal prices
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};
int main(){
    StockSpanner* stockSpanner = new StockSpanner();
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for (int price : prices) {
        cout << stockSpanner->next(price) << " ";
    }
    return 0;
}