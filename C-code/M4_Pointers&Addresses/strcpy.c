#include<stdio.h>
#include <string.h>

//String copy take a source string and saves it to destination
void strcpy1 (char *dest, char *src)
{
	strcpy(src, "Hola ");
	strcpy(dest, src);
	//destination first then what we copy second
}
int main()
{
char array[5]={'H','E','l','L','O'};
char Narray[5];
strcpy1(Narray, array);
printf("new string is: %s", Narray);
}
