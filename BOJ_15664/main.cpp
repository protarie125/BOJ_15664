#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n, m;
vi kh;

int bf;
vi now;

void solve(int b) {
	if (m == now.size()) {
		for (const auto& x : now) {
			cout << x << ' ';
		}
		cout << '\n';

		return;
	}

	for (auto i = b; i < n; ++i) {
		if (bf == kh[i]) {
			continue;
		}

		now.push_back(kh[i]);
		solve(i + 1);
		now.pop_back();

		bf = kh[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m;

	kh = vi(n);
	for (auto&& x : kh) {
		cin >> x;
	}

	sort(kh.begin(), kh.end());

	bf = 10001;
	solve(0);

	return 0;
}