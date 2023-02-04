#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, m;
set<long long> s;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        long long x = 0; long long y = 0; cin >> x >> y;
        while(s.upper_bound(y * m + x) != s.end()) {
            s.erase(*s.upper_bound(y * m + x));
        }
        s.insert(y * m + x);
    }
    cout << s.size();
    return 0;
}



#if 0
#include <iostream>
#include <set>
#include <tuple>

#define MAX_N 100000

using namespace std;

// ���� ����
int n, t;
// x ������ �����Ͽ� ������� �����մϴ�.
set<pair<int, int> > people_x;
// ������ ������� ������ �ð� ������ �����Ͽ� ��ǵ��� �����մϴ�.
set<tuple<double, int, int> > event_t;

int x[MAX_N], v[MAX_N];

// (x1, v1) ����� �ٷ� �տ� �ִ� (x2, v2)�� ����ġ�� �� �ɸ��� �ð�
// ������ ��� ��� ������ �߰��մϴ�. 
void AddEvent(int x1, int v1, int x2, int v2) {
	// ���� �������� �� ���� ����� �����մϴ�.
	if (v1 <= v2)
		return;

	event_t.insert(make_tuple(1.0 * (x2 - x1) / (v1 - v2), x1, v1));
}

// (x1, v1) ����� �ٷ� �տ� �ִ� (x2, v2)�� ����ġ�� �� �ɸ��� �ð�
// ������ ��� �ش� ��� ������ �����մϴ�.
void RemoveEvent(int x1, int v1, int x2, int v2) {
	// ���� �������� �� ���� ����� �����մϴ�.
	if (v1 <= v2)
		return;

	event_t.erase(make_tuple(1.0 * (x2 - x1) / (v1 - v2), x1, v1));
}

int main() {
	// �Է�:
	cin >> n >> t;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> v[i];

	// ������� set���� �����մϴ�.
	for (int i = 0; i < n; i++)
		people_x.insert(make_pair(x[i], v[i]));

	// ������ ������� ������ ��ǵ� set���� �����մϴ�.
	// (t, x, v) : 
	// ���� x ��ġ���� �ӵ� v�� �̵��ϴ� �����
	// �ٷ� �տ� �ִ� ����� 
	// ����ġ�� �� �Ÿ��� �ð� t��� ���� ����
	for (int i = 0; i < n - 1; i++)
		AddEvent(x[i], v[i], x[i + 1], v[i + 1]);

	// �������� ����� �����Ѵٸ� �ݺ��մϴ�.
	while (!event_t.empty()) {
		double curr_t; int x, v;
		tie(curr_t, x, v) = *event_t.begin();

		// �̹� t���� �Ѿ��ٸ� �����մϴ�.
		if (curr_t > t)
			break;

		// �ش� ����� ����� �����մϴ�.
		people_x.erase(make_pair(x, v));
		event_t.erase(make_tuple(curr_t, x, v));

		// �ٷ� �� ��� ��ġ�� ���մϴ�.
		set<pair<int, int> >::iterator it = people_x.upper_bound(make_pair(x, v));
		int nx, nv;
		tie(nx, nv) = *it;

		// �ٷ� �ڿ� ����� �ִٸ� 
		// ���� ����� �����ϰ�
		// ���ο� ����� �߰��մϴ�.
		if (it != people_x.begin()) {
			it--;
			int px, pv;
			tie(px, pv) = *it;
			RemoveEvent(px, pv, x, v);
			AddEvent(px, pv, nx, nv);
		}
	}

	// ���� �ٸ� �׷��� ���� ����մϴ�.
	cout << (int)people_x.size();
	return 0;
}
#endif