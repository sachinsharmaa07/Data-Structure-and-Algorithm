#include <iostream>
#include <vector>
using namespace std;
int router(vector<int> a, int k ){
    int low=1;
    int high=a[a.size()-1]-a[0];
    int ans =0;
    while(low<=high){
        int mid=low+(high-low)/2;
  
        int routerCount = 1;
        int lastPos = a[0];
        for (int i = 1; i < a.size(); i++) {
            if (a[i] - lastPos >= mid) {
                routerCount++;
                lastPos = a[i];
            }
        }
        if (routerCount >= k) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
    }

int main() {
    vector<int> a = {2,4,5,9,11,15,18,27,31};
    int maxDis=router(a,4);
    cout<<"Maximum Distance is : "<<maxDis<<endl;

    return 0;
}