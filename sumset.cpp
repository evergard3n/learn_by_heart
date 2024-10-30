#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
int main() {
  int n,x;
  cin >> n >> x;
  vector<int> arr(n);
  for(int i=0;i<n;i++) {
    cin >> arr[i];
  }
  vector<bool> dp(x+1, false);
  dp[0] = true;
  for(int i=0;i<n;i++) {
    // biến j chạy từ tổng cho trước cho đến phần tử a[i] đang xét xem a[i] có cộng cái gì để thành j được không
    for(int j= x; j>=arr[i];j--) {
      // nếu đã tồn tại tổng j-arr[i] thì cũng tổn tại tổng j (do arr[i] luôn tồn tại)
      if(dp[j-arr[i]]== true) {
        dp[j] = true;
      }
    }
  }
  if(dp[x]) cout << 1;
  else cout << 0;
}