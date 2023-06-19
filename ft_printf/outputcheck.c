#include <stdio.h>
int main()
{
	printf("%u\n", -123);
	printf("%i\n", -123);
	printf("%d\n", -123);
	int tmp = 0;
	printf("%p\n", &tmp);
	printf("%x\n", &tmp);
	printf("%d\n", &tmp);
	printf("%", tmp);
	return 0;
}
