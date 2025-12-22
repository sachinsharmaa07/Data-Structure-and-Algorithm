#include <iostream>
#include <vector>
using namespace std;

int PeakSearch(vector<int>& vec) {
    int st = 1, end = vec.size() - 2;
    while(st <= end) {
        int mid = st + (end - st) / 2;
        if(vec[mid]>vec[mid-1] && vec[mid]>vec[mid+1]){
            return mid;
        }
        if(vec[mid-1]<vec[mid] ){
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int main() {
    vector<int> vec = {2, 5, 6, 0, 1};
    int res=PeakSearch(vec);
    cout<<res<<" is the peak index";
}
