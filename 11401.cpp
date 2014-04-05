#include<iostream>

using namespace std;

typedef long long ull;
ull triangles[1000001];

int main()
{
    ull n;
    triangles[0] = 0;
    for(n = 1; n <= 1000000; n++)
    {
	triangles[n] = triangles[n-1]+(n-1)*(n)/2-(n/2)*(n/2+1)+1;
	if(n % 2)
	    triangles[n] -= n/2+1;
    }
    while(cin >> n && n >= 3)
	cout << triangles[n] << endl;
    
}
