#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> w(n+1);
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) {
        cin >> w[i] >> v[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=x;j++) {
            // khi chưa cho đồ vật thứ i vào thì khối lượng của bag vẫn như khi cho đồ vật thứ i-1 vào
            dp[i][j] = dp[i-1][j];
            // nếu j vẫn lớn hơn w[i] hoặc bằng, tức là vẫn còn chỗ chứa cho đồ vật thứ i
            if(j>=w[i]) {
                // so sánh xem liệu khi cho thêm đồ thứ i vào thì giá trị có lớn hơn trước lúc cho vào không
                // dp[i-1][j-w[i]] có nghĩa: xét xem trước lúc cho i vào, tìm tổng value của chỗ có chỗ chứa j[w-1]
                // để khi nhét i vào thì tổng khối lượng vẫn là j
                // với i là số lượng đồ vật đã nhét vào
                dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
            }            
        }
    }
    cout << dp[n][x];
}