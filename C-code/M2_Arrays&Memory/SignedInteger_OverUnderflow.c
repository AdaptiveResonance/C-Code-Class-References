// Integer Overflow/Underflow & Signed + Unsigned integers
// 32-bit system/code compiled as 32 bits, occupies 32 bits of space
// 2**32 produces 4,294,967,296 possible values
// so unsigned int should be able to contain 0 to 4,294,967,295 
// as unsigned int only allows for positive values!
// Signed int allows for negative integers in a range of 
// −2,147,483,648 to 2,147,483,647
// Overflow is essentially applying a value to a datatype
// that is too big to hold so it "spills over"

#include <stdio.h>

int main()
    {
	signed int signed_num = -2147483648;
	// return sizeof signed integer
	printf("Bytesize of signed_num is :%d bytes or %d bits \n", sizeof(num_signed), sizeof(num_signed) * 8);

	// Print initial value before change
	printf("Initial signed_num value is: %u \n", num_signed);

	// Print new value
	printf("%d - 1 = %d \n", num_signed, num_signed -1);
	//-2147483648 -1 should equal -2,147,483,649 however returns 2147483648
	return 0;
    }