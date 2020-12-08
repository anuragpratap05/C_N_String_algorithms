# C_N_String_algorithms
// S and T - input strings
// You need to check if string T is present in S or not
#include<bits/stdc++.h>
//using namespace std;

int* getlps(char T[],int len)
{
	//int len = pattern.length();
	int* lps = new int[len];
	lps[0] = 0;
	int i = 1;
	int j = 0;

	while (i < len)
	{
		if (T[i] == T[j])
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
	/*for (int i = 0; i < len; i++)
	{
		cout << lps[i] << " ";
	}*/
	//cout << endl;
	return lps;
}

int kmpsearch(char S[], char T[] ,int textlen,int patternlen)
{
	//int textlen = text.length();
	//int patternlen = pattern.length();
	int i = 0;
	int j = 0;
	int* lps = getlps(T,patternlen);
	int ans;
	int ans1;
	int flag = 0;
	while (i < textlen and j < patternlen)
	{
		if (S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			if (j != 0)
			{
				flag = 1;
				j = lps[j - 1];
				//cout << "i= " << i << " and " << "[j-1]= " << j - 1 << endl;
				if (j == 0)
				{
					flag = 0;
					ans = i - j ;
				}
				//cout << ans << endl;
			}
			else
			{
				i++;
			}
		}
		ans1 = i - j;
	}
	int final;
	if (flag == 1)
		final = ans;
	else
		final = ans1;
	if (j == patternlen)
	{
		return final;
	}
	return -1;

}

int findString(char S[], char T[]) {
    // Write your code here
    
   int textlen=strlen(S);
    int patlen=strlen(T);
   // cout<<c<<" "<<p;
    return kmpsearch(S,T,textlen,patlen);
    
    
    

}

