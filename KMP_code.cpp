# C_N_String_algorithms
#include<bits/stdc++.h>
using namespace std;

int* getlps(string pattern)
{
	int len = pattern.length();
	int* lps = new int[len];
	lps[0] = 0;
	int i = 1;
	int j = 0;

	while (i < len)
	{
		if (pattern[i] == pattern[j])
		{
			lps[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}

bool kmpsearch(string text, string pattern)
{
	int textlen = text.length();
	int patternlen = pattern.length();
	int i = 0;
	int j = 0;
	int* lps = getlps(pattern);
	while (i < textlen and j < patternlen)
	{
		if (text[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				i++;
			}
		}
	}
	if (j == patternlen)
	{
		return true;
	}
	return false;

}

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif

	string str = "abcxabcdabcdabcy";
	string substring = "abcdabcy";
	cout << kmpsearch(str, substring);
	return 0;

}
