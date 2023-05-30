#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N = 100;
const int MAX_SUM = 1e5;

// bool dp[MAX_N + 1][MAX_SUM + 1];

// int main() {
// 	int n;
// 	cin >> n;

// 	vector<int> coins_values(n);
// 	for (int i = 0; i < n; i++) { cin >> coins_values[i]; }

// 	dp[0][0] = true;

// 	for (int i = 1; i <= n; i++) {
// 		for (int current_sum = 0; current_sum <= MAX_SUM; current_sum++) {
// 			dp[i][current_sum] = dp[i - 1][current_sum];
// 			int prev_sum = current_sum - coins_values[i - 1];
// 			if (prev_sum >= 0 && dp[i - 1][prev_sum]) {
// 				dp[i][current_sum] = true;
// 			}
// 		}
// 	}

// 	vector<int> possible;
// 	for (int sum = 1; sum <= MAX_SUM; sum++) {
// 		if (dp[n][sum]) { possible.push_back(sum); }
// 	}

// 	cout << (int)(possible.size()) << endl;

// 	for (int sum : possible) { cout << sum << " "; }
// 	cout << endl;
//     return 0;
// }


int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>coins[i];
        sum+=coins[i];
    }

    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    dp[0][0] = true;

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=sum;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(j >= coins[i-1]){
                dp[i][j] = dp[i][j] | dp[i-1][j-coins[i-1]];
            }
        }
    }

    string ans_str = "";
    int cnt = 0;

    for(int i=1;i<=sum;i++){
        if(dp[n][i]){
            cnt++;
            ans_str += to_string(i);
            ans_str += " ";
        }
    }
    cout << cnt << endl;
    cout << ans_str << endl;
    return 0;
}