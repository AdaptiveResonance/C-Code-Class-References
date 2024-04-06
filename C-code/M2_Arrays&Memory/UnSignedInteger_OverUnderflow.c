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
	unsigned int unsigned_num = 4294967295;//maximum number

	// return sizeof unsigned integer
	printf("Bytesize of unsigned_num is :%d bytes or %d bits \n", sizeof(unsigned_num), sizeof(unsigned_num) * 8);

	// Print initial value before change
	printf("Initial unsigned_num value is: %u \n", unsigned_num);

	// Print new value
	printf("%u + 1 = %u \n", unsigned_num, unsigned_num + 1);
	//4294967295 + 1 = 4294967296 but returns 0 due to overflow
	return 0;
    }
