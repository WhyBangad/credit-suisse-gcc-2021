#pragma GCC optimize("O1")

#include <iostream>

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", 2 * (n/ 3) + (n % 3 != 0));
}
