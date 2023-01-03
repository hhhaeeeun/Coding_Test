#include<bits/stdc++.h>
using namespace std;
int n,m;
int a, c, g, t;
int num[4];

bool is_password()
{
	if (a > num[0])
		return false;
	if(c>num[1])
		return false;
	if(g>num[2])
		return false;
	if(t>num[3])
		return false;

	return true;

}
void DNA_collect(char DNA)
{
	if (DNA == 'A')
		++num[0];
	else if (DNA == 'C')
		++num[1];
	if (DNA == 'G')
		++num[2];
	else if (DNA == 'T')
		++num[3];
}

void DNA_recollect(char DNA)
{
	if (DNA == 'A')
		--num[0];
	else if (DNA == 'C')
	    --num[1];
	if (DNA == 'G')
		--num[2];
	else if (DNA == 'T')
		--num[3];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 0;
	string DNA = "";
	cin >> n >> m;
	cin >> DNA;
	cin >> a;	cin >> c;	cin >> g;	cin >> t;

	for (int j = 0; j < m; j++)
	{
		DNA_collect(DNA[j]);
	}
	if (true == is_password())
		count++;

	int s_p = 0;
	int e_p = m-1;


	for (int i = 0; i < n - m; i++)
	{
		DNA_recollect(DNA[s_p++]); 
		DNA_collect(DNA[++e_p]);
		if (true == is_password())
			count++;
	}

	cout << count << "\n";
	return 0;
}
