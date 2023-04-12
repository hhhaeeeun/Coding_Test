#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int TC, n, m;
int MaxTreeSize;
vector<int>TreeDVD;
vector<int> ID;

//������ Ʈ�� �ʱ�ȭ
int init_tree(int idx, int start, int end) {
	if (start == end) {
		//m�ʰ��� node�� 1�� �ֱ�
		//m������ node�� 0�� �ֱ�
		if (start > m)
		{
			return TreeDVD[idx] = 1;
		}
		return 0;
	}
	int mid = (start + end) / 2;
	//�ڽ� ����� ������ �κ��� �ϼ�
	return TreeDVD[idx] = init_tree(idx * 2, start, mid) + init_tree(idx * 2 + 1, mid + 1, end);
}
void init_vector() {
	MaxTreeSize = n + m;
	TreeDVD.resize(MaxTreeSize * 4);
	for (int i = 0; i < 4 * MaxTreeSize + 1; i++)
		TreeDVD[i] = 0;
	init_tree(1, 1, MaxTreeSize);
	ID.resize(n + 2);
	for (int i = 0; i < n+2; i++)
		ID[i] = 0;
	for (int i = 1; i <= n; i++) {
		ID[i] = i + m;
	}
}
void update(int idx, int start, int end, int target, int diff) {
	if (start == end) {
		TreeDVD[idx] += diff;
		return;
	}
	int mid = (start + end) / 2;
	if (target <= mid)
		update(idx * 2, start, mid, target, diff);
	else
		update(idx * 2 + 1, mid + 1, end, target, diff);
	TreeDVD[idx] = TreeDVD[idx * 2] + TreeDVD[idx * 2 + 1];
	return;
}
int sum(int idx, int start, int end, int left, int right) {
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return TreeDVD[idx];
	int mid = (start + end) / 2;
	return sum(idx * 2, start, mid, left, right) + sum(idx * 2 + 1, mid + 1, end, left, right);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("input_230412.txt", "rt", stdin);

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		cin >> n >> m;
		//n,m�� ���� Ʈ���� �ٽ� �ʱ�ȭ ��
		init_vector();
		//���� ���� ��ġ ����
		int next_idx = m + 1;
		for (int j = 0; j < m; j++) {
			int move = 0; cin >> move;
			//������ ��� ����ó��
			if (ID[move] == next_idx) {
				cout << 0 << ' ';
				continue;
			}
			//������ �ƴ� ���
			int ret = sum(1, 1, MaxTreeSize, 1, ID[move] - 1);
			cout << ret << ' ';
			update(1, 1, MaxTreeSize, ID[move], -1);
			ID[move] = --next_idx;
			update(1, 1, MaxTreeSize, ID[move], 1);
		}
		cout << '\n';
	}

	return 0;
}