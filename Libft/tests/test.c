#include <stdio.h>

typedef struct{
	int *age;
} MyAge;

int main()
{
	MyAge me;
	int value = 20;
	me.age = &value;
	MyAge *lst = &me;
	int *firstcase = lst->age;
	int secondcase = *lst->age;
	printf("first case : %ls \n", firstcase);
	printf("second case : %d \n", secondcase);
	return 0;
}
