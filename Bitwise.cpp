// BITWISE NOT ~ (FLIP) // Operates on one value // ~1110001 = 0001110

// BITWISE AND & (IF BOTH ARE 1 THEN 1) // Operates on two equal length values
// if both bits are 1, then keep 1, otherwise 0 // 101 & 100 = 100

// BITWISE OR | (IF ONE IS 1 THEN 1) // Operates on two equal length values
// if one of the bits is 1, then make it 1, otherwise 0 // 1010 | 0110 = 1110

// BITWISE XOR ^ (IF NOT IDENTICAL THEN 1) // Operates on two equal length values
// if both are 0 or both are 1 (meaning they are identical), then 0 // 1010 ^ 0110 = 1100

// BITWISE LEFTSHIFT << (power of by moving left) // Operates on one value
// shifts to the left, which in essence does a "power of"
// 16 8 4 2 1
// =  = = = =
// 1 << 4 = 16... think of it like moving 1 four postions to the left.... // Math is 1 * 2powerof4

// BITWISE RIGHTSHIFT >>  (divide by moving right) // Operates on one value
// shifts to the right, which in essence does a "divide by 2*n".. // 2 is the base, since bits are Base2 numbers
// 4 >> 1 = 2.. think of it like 4 / (2*1)
// 32 >> 8 = 2.. think of it like 32 / (2*8)

// EXERCISE 1
// shifting 1 << i bits gives you something like 0010000 (if i was 4)
// now doing AND with another value will zero out everything UNLESS that bit in the original NUM was also 1
// you check for that by comparing to 0
// bool getBit(int num, int i) {
// return (num & (1 << i)) != 0;

// EXERCISE 2
// shifting 1 << i bits give you something like 0000100 (if i was 2)
// now doing OR with another value sets 1 at that location... if it was already 1, nothing would happen
// int setBitToOne(int num, int i) {
// return (num | (1 << i));
