Given three positive integers L, R and Y, the task is to count the numbers in the range [L, R] whose sum of digits is equal to X

#include"bits/stdc++.h"
#define         int                 long long
#define         pb                  push_back
#define         fr                  first
#define         sc                  second
#define         pii                 pair<int,int>
#define         vi                  vector<int>
#define         mod                 1000000007
#define         sz(x)               (int)((x).size())
#define         all(x)              (x).begin(),(x).end()
#define         FOR(i,a,b)          for(int i=a;i<b;i++)
#define         INF                 3000000000000000000
#define         endl                "\n"
using namespace std;

int dp[20][2][2][190];

int calc(string &num, int n, int i, int tight, int lead, int sum) {
	if (sum < 0) {
		return 0;
	}
	if (i == n) {
		return (sum == 0);
	}
	if (dp[i][tight][lead][sum] != -1) {
		return dp[i][tight][lead][sum];
	}
	int ans = 0;
	int no = num[i] - '0';
	int ub = tight ? no : 9;
	if (lead) {
		ans += calc(num, n, i + 1, 0, 1, sum);
	}
	else {
		ans += calc(num, n, i + 1, tight & (no == 0), 0, sum);
	}
	for (int d = 1; d <= ub; d++) {
		ans += calc(num, n, i + 1, tight & (no == d), 0, sum - d);
	}
	return dp[i][tight][lead][sum] = ans;
}

void brute_force(int l, int r, int x) {
	int cnt = 0;
	for (int i = l; i <= r; i++) {
		int y = i;
		int sum = 0;
		while (y > 0) {
			sum += y % 10;
			y /= 10;
		}
		if (sum == x) {
			cnt++;
		}
	}
	cout << cnt << endl;
}

void TEST_CASE() {

	int L, R, x;
	cin >> L >> R >> x;
	brute_force(L, R, x);
	string num = to_string(R);
	memset(dp, -1, sizeof(dp));
	int ans = calc(num, sz(num), 0, 1, 1, x);

	memset(dp, -1, sizeof(dp));
	num = to_string(L - 1);

	ans -= calc(num, sz(num), 0, 1, 1, x);
	cout << ans << endl;
}

signed main() {
#ifndef UV3
	freopen("Error.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		TEST_CASE();
	}
	return 0;
}
