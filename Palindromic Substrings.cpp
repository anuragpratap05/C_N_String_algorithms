# C_N_String_algorithms
#include<bits/stdc++.h>
int countPalindromeSubstrings(char s[]) {
	// Write your code here
    int n = strlen(s);
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		int l = i;
		int r = i;
		while (l >= 0 and r < n and s[l] == s[r])
		{
			c++;
			l--;
			r++;
		}

		l = i;
		r = i + 1;
		while (l >= 0 and r < n and s[l] == s[r])
		{
			c++;
			l--;
			r++;
		}

	}
	return c;
	
}

