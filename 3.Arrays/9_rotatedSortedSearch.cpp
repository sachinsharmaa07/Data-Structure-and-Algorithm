#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>& vec, int target) {
    int st = 0, end = vec.size() - 1;
    while(st <= end) {
        int mid = st + (end - st) / 2;
        if(vec[mid] == target)
            return true;
        // Handle duplicates
        if(vec[st] == vec[mid] && vec[mid] == vec[end]) {
            ++st;//condition for not able to determine which half is sorted
            --end;
        }
        else if(vec[st] <= vec[mid]) {
            if(vec[st] <= target && target < vec[mid])
                end = mid - 1;
            else
                st = mid + 1;
        }
        else {
            if(vec[mid] < target && target <= vec[end])
                st = mid + 1;
            else
                end = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<int> vec = {2, 5, 6, 0, 0, 1, 2};
    int target = 2;
    if (search(vec, target))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;
    return 0;
}
