/*
	用分治法在一个有序序列中如果下标和元素值相等的数
	我称之为KeyElement
*/
#include<iostream>
#include<vector>
using namespace std;
int findElement(vector<int> a, int l, int r) {
	int mid = l + ((r - l) >> 1);
	if (l != r) {
		if (a[mid] > mid) {
			return findElement(a, l, mid - 1);
		}
		else if (a[mid] < mid) {
			return findElement(a, mid + 1, r);
		}
		else {
			return mid;
		}
	}
	return a[l] == l ? l : -1;
}
int findKeyElement(vector<int> a) {
	return findElement(a, 0, a.size() - 1);
}
int main() {
	vector<int> a = { -7,-5,-2,0,4,7,9 };
	vector<int> b = { 2,3,4,5,6,7,8,99 };
	cout <<"这是第一个测试的输出：" << findKeyElement(a) << endl;
	cout << "这是第二个测试的输出：" << findKeyElement(b) << endl;
	return 0;
}