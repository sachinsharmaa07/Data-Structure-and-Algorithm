#include<iostream>
using namespace std;
bool search(vector<int>& vec, int target) {
        int st = 0, end = vec.size() - 1;
        while(st <= end) {
            int mid = st + (end - st) / 2;
            if(vec[mid] == target) {
                return true;
            }
            if(vec[st] == vec[mid] && vec[mid] == vec[end]) {
                ++st;
                --end;
            }
            else if(vec[st] <= vec[mid]) { // left side is sorted
                if(vec[st] <= target && target < vec[mid]) {
                    end = mid - 1;
                }
                else {
                    st = mid + 1;
                }
            }
            else { // right side is sorted
                if(vec[mid] < target && target <= vec[end]) {
                    st = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
int main(){
    
}
