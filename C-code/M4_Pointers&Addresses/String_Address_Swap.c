#include<stdio.h>


int swap(int a, int b)
//will only change the value in a locally, not in main
{
	int temp;
	printf("a: %p b; %p\n", &a, &b);
	printf("a: %d b: %d\n", a, b);
	temp = a;
	a = b;
	b = temp;
	printf("a: %p b: %p\n", a, b);
	printf("a: %d b: %d\n", a, b);
	return(0);
}
int swap2(int* a, int* b)
//using the memory location to pass the value is one way to 'save' back in main
{
	int temp;
	printf("a2: %p b2; %p\n", a, b);
	printf("a2: %d b2: %d\n", *a, *b);
	temp = *a;
	*a = *b;
	*b = temp;
	printf("a2: %p b2: %p\n", a, b);
	printf("a2: %d b2: %d\n\n", *a, *b);
	return(0);
}
int main()
{
	int aval = 100, bval = 200000;
	printf("initial aval: %p bval: %p\n", &aval, &bval);
	printf("initial aval: %d bval: %d\n\n", aval, bval);
	swap(aval, bval);

	printf("\nFinal aval: %p bval: %p\n", &aval, &bval);
	printf("Final aval: %d bval: %d\n\n", aval, bval);
	swap2(&aval, &bval);
	printf("Final aval: %d bval: %d\n", aval, bval);
	//now we see the actual value changed
}