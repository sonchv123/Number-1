#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<int> vi;
typedef vector<ii> vii;

//const int oo = 1e17 + 7;
const int MOD = 1e9 + 7;
const int maxN = 1e5 + 7;

int n, k, a[maxN];
bool isPrint[maxN];
string S;	

int main()
{
	//freopen("in.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> S;	n = S.size();
	cin >> k;
	memset(isPrint, true, sizeof(isPrint));
	for (int i = 0; i < n; i++)
		a[i + 1] = S[i] - '0';
	int st = 1;
	while(st <= n && k > 0)
	{
		int posMin = st;
		for (int i = st; i <= min(st + k, n); i++)
		{
			if (a[i] < a[posMin])	posMin = i;
		}
		for (int i = st; i < posMin; i++)	
		{
			isPrint[i] = false;
			k--;
		}
		st = posMin + 1;
	}
	while(k--)
	{
		for (int i = n; i >= 1; i--)
			if (isPrint[i])
			{
				isPrint[i] = false;
				break;
			}
	}
	for (int i = 1; i <= n; i++)
		if (isPrint[i])	cout << a[i];
	return 0;
}
