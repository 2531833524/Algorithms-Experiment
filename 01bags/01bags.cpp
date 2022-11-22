#include <iostream>
#include<stack>
#include<vector>
using namespace std;
int N = 10;
vector<int> f(N, 0);
vector<int> g(N, 0);
int bags(vector<int> weight, vector<int> values, int capicity) {
	f.resize(N);
	g.resize(N);
	stack<int> stk;
	int left = capicity;
	int value = 0;
	int max=0;
	int n = weight.size();
	for (int i = 0; ; i++) {
		if (left-weight[i]>=0) {
			stk.push(i);
			f[i] = 1;
			value +=values[i];
			left -= weight[i];
		}
		if (i == n - 1) {
			if (max < value) {
				max = value;
				for (int i = 0; i < f.size(); i++) {
					g[i] = f[i];
				}
			}
				
			i = stk.top();
			stk.pop();
			f[i] = 0;
			left += weight[i];
			value -= values[i];
			if (i == n - 1) {
				if (stk.empty())
					break;
				i = stk.top();
				stk.pop();
				f[i] = 0;
				left += weight[i];
				value -= values[i];
			}
		}
	}
	return max;
}
int main()
{
	int ca, n;
	cout << "输入背包容量和物品数量" << endl;
	cin >> ca >> n;
	N = n;
	vector<int> w(n,0);
	vector<int> v(n,0);
	cout << "输入物品对应的重量和价值" << endl;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	cout <<"最大价值为：" << bags(w, v, ca)<<endl;
	cout << "解向量为:";
	for (int i = 0; i < n; i++) {
		cout << g[i] << " ";
	}
}
