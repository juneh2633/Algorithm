#include <cstdio>
#include <algorithm>
using namespace std;

char buf[1<<16];
int idx = 1<<16;

inline char read()
{
    if (idx == 1<<16)
    {
        fread(buf, 1, 1<<16, stdin);
        idx = 0;
    }
    return buf[idx++];
}
inline int readInt()
{
    int sum = 0;
    char now = read();
    
    while (now == ' ' || now == '\n') now = read();
    while (now >= '0' && now <= '9')
    {
        sum = sum*10 + now-48;
        now = read();
    }
    
    return sum;
}
int main()
{
	int a = readInt();
    int b = readInt();
	
	int ary1[a];
	int ary2[b];
	for (int i = 0; i < a; ++i) ary1[i] = readInt();
	for (int i = 0; i < b; ++i) ary2[i] = readInt();
	
	sort(ary1, ary1 + a);
	sort(ary2, ary2 + b);
	
	int ap = 0;
	int bp = 0;
	int ans = 0;
	while (ap < a && bp < b)
	{
		while (ap < a && ary1[ap] < ary2[bp]) ans++, ap++;
		while (bp < b && ary1[ap] > ary2[bp]) ans++, bp++;
		if (ary1[ap] == ary2[bp]) ap++, bp++;
	}
	
	printf("%d", ans + (b - bp) + (a - ap));
	return 0;
}