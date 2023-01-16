#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int A[11][11];
int y[11][11];
//위, 왼, 아래, 오
int dy[8] = { -1, 0, 1, 0, -1,-1,1,1 };
int dx[8] = { 0,-1,0,1, -1, 1, -1,1 };
const int INF = 987654321;

typedef struct bb {
	int y = 0;
	int x = 0;
	int age = 0;
}TREE;
bool cmp(TREE a_, TREE b_){
	return(a_.age < b_.age);
	
}

struct QUEUE {
	int f, b;
	TREE tree[684000];
	QUEUE() {
		init();
	}
	void init() {
		f = 0; b = 0;
	}
	bool isempty() {
		return (f == b);
	}
	void push(TREE val) {
		tree[b++] = val;
	}
	void pop() {
		++f;		
	}
	TREE front() {
		return tree[f];
	}
	int size() {
		return (b - f);
	}

};
QUEUE now_tree;
QUEUE dead_tree;
QUEUE next_tree;
QUEUE old_tree;
void spring(TREE tree) {
	if (A[tree.y][tree.x] < tree.age) {//이번에 죽음
		dead_tree.push(tree);
	}
	else {//살아있음
		A[tree.y][tree.x] -= tree.age;
		tree.age++;
		next_tree.push(tree);
	}
}

void fall(TREE tree) {
	if (tree.age % 5 == 0) { //5의 배수인 나무가 번식함
		for (int i = 0; i < 8; i++) {
			int ny = tree.y + dy[i];
			int nx = tree.x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
			now_tree.push({ ny,nx,1});
		}
	}
	old_tree.push(tree);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> y[i][j];
	}
	for (int i = 0; i < m; i++)
	{
		TREE temp;
		cin >> temp.y >> temp.x >> temp.age;
		--temp.y;
		--temp.x;
		now_tree.push(temp);
	}
	fill(&A[0][0], &A[10][11], 5);

	sort(now_tree.tree, now_tree.tree + m, cmp);



	for (int i = 0; i < k; i++) {
		dead_tree.init();
		next_tree.init();
		old_tree.init();
		while (now_tree.size()) {
			TREE temp = now_tree.front(); now_tree.pop();
			spring(temp);
		}

		while (dead_tree.size()) {
			TREE temp = dead_tree.front(); dead_tree.pop();
			A[temp.y][temp.x] += (temp.age / 2);
		}
		now_tree.init();
		while (next_tree.size()) {
			TREE temp = next_tree.front(); next_tree.pop();
			fall(temp);
		}

		while (old_tree.size()) {
			TREE temp = old_tree.front(); old_tree.pop();
			now_tree.push(temp);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				A[i][j] += y[i][j];
			}
		}
	}
	cout << now_tree.size() << "\n";
	return 0;
}