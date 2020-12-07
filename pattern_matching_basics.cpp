#include<bits/stdc++.h>
using namespace std;

bool pattern(string s1, string s2)
{
	int n1 = s1.length();
	int n2 = s2.length();

	for (int i = 0; i <= n1 - n2; i++)
	{
		bool found = true;
		for (int j = 0; j < n2; j++)
		{
			if (s1[i + j] != s2[j])
			{
				found = false;
				break;
			}
		}
		if (found == true)
		{
			return true;
		}
	}
	return false;
}

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	string s1, s2;
	cin >> s1 >> s2;
	if ( pattern(s1, s2))
	{
		cout << "pattern found";
	}
	else
	{
		cout << "not found";
	}
}
