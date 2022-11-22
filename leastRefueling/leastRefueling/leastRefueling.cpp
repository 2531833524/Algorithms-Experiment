#include<iostream>
#include<vector>
using namespace std;
int leastRefuling(int n,vector<int> distances) {
	int ans = 0;
	int left = n;
	if (distances[0] > n)
		return -1;
	for (int i = 0; i < distances.size(); i++) {
		if (left >= distances[i]) {
			left = left - distances[i];//能到达下一个加油站就把剩余里程减小
		}
		else {//不能到达就加油
			left = n;
			ans++;
			cout << "在第" << i << "个加油站加油" << endl;
			left = left - distances[i];
		}
	}
	return ans;
}
int main() {
	int n, k;
	cout << "请输入加满油能行驶的里程:" << endl;
	cin >> n;
	cout << "请输入有多少个加油站" << endl;
	cin >> k;
	cout << "输入加油站之间的距离：" << endl;
	vector<int> d(k);
	for (int i = 0; i < k; i++) {
		cin >> d[i];
	}
	cout << "加油次数为：" << leastRefuling(n, d) << endl;
	return 0;
}