/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * Realname：Wang Chenxin  github userid：K-the-Executor
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.
  4. Interprets integer expressions using the Data Lab 32-bit bit-vector
     model: results outside the signed range retain their low 32 bits.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
#include "bits.h"

// P1
/* 
 * signMask - return a mask with only the most significant bit set (0x80000000)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int signMask(void) {
  int a1=1<<31;
  return a1;
}

// P2
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1, bitXor(7, 7) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 2
 */
int bitXor(int x, int y) {
  int a2=~(~(~x & y) &~(x & ~y));
	return a2;
}

// P3
/*
 * negativePart - return -x if x < 0, otherwise return 0
 *   Examples: negativePart(-10) = 10, negativePart(5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int negativePart(int x){
  int a=x>>31;
  int b=~x+1;
  return a&b;
}


// P4
/*
 * copyByteWithin - copy byte src of x to byte dst, leaving all other bytes unchanged
 *   Bytes are numbered from 0 (least significant) to 3 (most significant).
 *   You can assume 0 <= src <= 3 and 0 <= dst <= 3.
 *   Example: copyByteWithin(0x11223344, 0, 2) = 0x11443344
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int copyByteWithin(int x, int src, int dst) {
  int src0 = (x >> (src << 3)) & 0xFF;
  int clear = ~(0xFF << (dst << 3));
  int a4=(x & clear) | (src0 << (dst << 3));
  return a4;
}

// P5
/* 
 * logicalShift - shift x to the right by n bits, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int logicalShift(int x, int n) {
  int x1=x>>n;
  int x2=~(((1<<31)>>n)<<1);
  int a5=x1&x2;
  return a5;
}

// P6
/*
 * swapNibblePairs - swap the low and high 4 bits within each byte of x
 *   Examples: swapNibblePairs(0xAB) = 0xBA
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4
 */
int swapNibblePairs(int x) {
  int low = 0x0F | (0x0F << 8) | (0x0F << 16) | (0x0F << 24);
  int high = ~low;
  int lowpart = (x&low) << 4;
  int highpart = (x&high) >> 4;
  int mask=~((1<<31)>>3);
  highpart=highpart&mask;
  int a6= lowpart|highpart;
  return a6;
}

// P7
/*
 * secondLowestZeroBit - return a mask that marks the position of the second least significant 0 bit
 *   Examples: secondLowestZeroBit(0xFFFFFFFA) = 0x4, secondLowestZeroBit(0x7FFFFFFF) = 0
 *             secondLowestZeroBit(-1) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowestZeroBit(int x) {
  int n0=~x&(x+1);
  int x1=n0|x;
  int n1=~x1&(x1+1);
  return n1;
}

// P8
/*
 * oddParity - return the odd parity bit of x, that is,
 *      when the number of 1s in the binary representation of x is even, then the return 1, otherwise return 0.
 *   Examples: oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Rating: 5
 */
int oddParity(int x) {
  x = x ^ (x >> 16);
  x = x ^ (x >> 8);
  x = x ^ (x >> 4);
  x = x ^ (x >> 2);
  x = x ^ (x >> 1);
  int a8=!(x & 1);
  return a8;
}

// P9
/* 
 * rotateRightBits - rotate x to right by n bits
 *   you can assume n >= 0
 *   Examples: rotateRightBits(0x12345678, 8) = 0x78123456
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 5
 */
int rotateRightBits(int x, int n) {
  n=n&31;
  int x1=x>>n;
  x1=~(((1<<31)>>n)<<1)&x1;
  int x2=x<<((33+~n)&31);
  int a9=x1|x2;
  return a9;
}

// P10
/*
 * roundEvenPow2 - round nonnegative x to the nearest multiple of 2^n.
 *   If x is exactly halfway between two multiples, choose the multiple whose
 *   quotient by 2^n is even.
 *   You can assume 0 <= x <= 0x3fffffff and 1 <= n <= 16.
 *   Examples: roundEvenPow2(10, 2) = 8, roundEvenPow2(14, 2) = 16
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 5
 */
int roundEvenPow2(int x, int n) {
  int mask = ~(~0 << n);
  int low = x & mask; 
  int high = x & (~0 << n);
  int half = (1 << n) >> 1; 
  int judge = low + half;
  int up_half = judge >> n;
  int noteq_half = judge & mask;
  int x_n = (x >> n) & 1;
  int not_eq_half = !!noteq_half;
  int pop = up_half & (not_eq_half | x_n);
  int a10 = high + (pop << n);
  return a10;
}

// P11
/* 
 * midpointTowardFirst - return the exact mathematical midpoint (x+y)/2
 *   without overflow. If the exact midpoint lies halfway between two
 *   integers, choose the adjacent integer that is closer to the first
 *   argument x.
 *   Examples: midpointTowardFirst(4, 7) = 5,
 *             midpointTowardFirst(7, 4) = 6
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 32
 *   Rating: 5
 */
int midpointTowardFirst(int x, int y) {  
  int sx = x >> 31;
  int sy = y >> 31;
  int difference = x + ~y + 1;
  int sd = difference >> 31;
  int greater = (~sx & sy) | (~(sx ^ sy) & ~sd & !!difference);
  int floor = (x & y) + ((x ^ y) >> 1);
  int a11=floor + ((x ^ y) & greater & 1);
  return a11;
}


// P12
/* 
 * isBetweenEitherOrder - return 1 when x lies in the inclusive interval whose
 *   endpoints are a and b. The endpoints may be given in either order.
 *   Example: isBetweenEitherOrder(5, 8, 3) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 48
 *   Rating: 7
 */
int isBetweenEitherOrder(int x, int a, int b) {  int sx = x >> 31;
  int sa = a >> 31;
  int sb = b >> 31;
  int da = x + ~a + 1;
  int db = x + ~b + 1;
  int sda = da >> 31;
  int sdb = db >> 31;
  int sameA = ~(sa ^ sx);
  int sameB = ~(sb ^ sx);
  int aLeX = (sa & ~sx) | (sameA & ~sda);
  int xLeA = (sx & ~sa) | (sameA & (sda | !da));
  int bLeX = (sb & ~sx) | (sameB & ~sdb);
  int xLeB = (sx & ~sb) | (sameB & (sdb | !db));
  return ((aLeX & xLeB) | (bLeX & xLeA)) & 1;
}

// P13
/* 
 * mul5Sat - return x*5, and if x*5 overflow, change the result to 
 * INT_MAX(0x7fffffff) or INT_MIN(0x80000000) correspondingly
 *   Examples: mul5Sat(1) = 0x5, mul5Sat(0x40000000) = 0x7fffffff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7
 */
int mul5Sat(int x) {
  int quadruple = x << 2;
  int product = quadruple + x;
  int overflow4 = !!(x ^ (quadruple >> 2));
  int overflowAdd = ((~(quadruple ^ x) & (quadruple ^ product)) >> 31) & 1;
  int overflow = overflow4 | overflowAdd;
  int mask = ~overflow + 1;
  int saturation = (~(1 << 31)) ^ (x >> 31);
  return (mask & saturation) | (~mask & product);
}

// P14
/* 
 * classifyAdd3 - classify the exact mathematical sum x+y+z.
 *   Return 1 if the sum is greater than INT_MAX, -1 if it is less than
 *   INT_MIN, and 0 otherwise. You may not use a wider integer type.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 52
 *   Rating: 7
 */
int classifyAdd3(int x, int y, int z) {  
  int sum2 = x + y;
  int sum3 = sum2 + z;
  int sx = x >> 31;
  int sy = y >> 31;
  int sz = z >> 31;
  int s2 = sum2 >> 31;
  int s3 = sum3 >> 31;
  int positive1 = ~sx & ~sy & s2;
  int negative1 = sx & sy & ~s2;
  int positive2 = ~s2 & ~sz & s3;
  int negative2 = s2 & sz & ~s3;
  int positive = (positive1 | positive2) & ~(negative1 | negative2);
  int negative = (negative1 | negative2) & ~(positive1 | positive2);
  return (positive & 1) | negative;
}

// P15
/*
 * floatScaleThreeHalves - Return bit-level equivalent of expression f*3/2 for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   Use round-to-nearest-even. Preserve the sign of both +0 and -0.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 60
 *   Rating: 7
 */
unsigned floatScaleThreeHalves(unsigned uf) {
  unsigned sign = uf & 0x80000000u;
  unsigned exp = (uf >> 23) & 0xffu;
  unsigned frac = uf & 0x7fffffu;
  unsigned mant, product, resultMant, rem;
  if (exp == 0xffu) {
    return uf; 
  }
  if (exp == 0u) {
    product = frac * 3u;
    resultMant = product >> 1;
    rem = product & 1u;
    if (rem && (resultMant & 1u)) {
      resultMant = resultMant + 1u;
    }
    if (resultMant >= 0x800000u) {

      return sign | (1u << 23) | (resultMant & 0x7fffffu);
    }
    return sign | resultMant;
  }
  mant = frac | 0x800000u;
  product = mant * 3u;

  if (product < 0x2000000u) {
    resultMant = product >> 1;
    rem = product & 1u;
    if (rem && (resultMant & 1u)) {
      resultMant = resultMant + 1u;
    }

  } else {
    resultMant = product >> 2;
    rem = product & 3u;
    if ((rem > 2u) || ((rem == 2u) && (resultMant & 1u))) {
      resultMant = resultMant + 1u;
    }
    exp = exp + 1u;
  }

  if (resultMant >= 0x1000000u) {
    resultMant = resultMant >> 1;
    exp = exp + 1u;
  }
  if (exp >= 0xffu) {
    return sign | 0x7f800000u; 
  }
  return sign | (exp << 23) | (resultMant & 0x7fffffu);
}


// P16
/* 
 * floatRoundEven - round the floating-point value represented by uf to the
 *   nearest integer, with halfway cases rounded to the even integer. Return
 *   the bit-level representation of that integer as a single-precision float.
 *   If rounding produces zero, preserve the input sign; thus a negative
 *   value that rounds to zero returns -0. When uf is NaN or infinity,
 *   return uf unchanged.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 65
 *   Rating: 10
 */
unsigned floatRoundEven(unsigned uf) {
  unsigned sign = uf & 0x80000000u;
  unsigned exponent = (uf >> 23) & 0xffu;
  unsigned fraction = uf & 0x7fffffu;
  unsigned shift;
  unsigned mask;
  unsigned remainder;
  unsigned halfway;
  unsigned rounded;

  if (exponent == 0xffu) return uf;
  if (exponent < 126u) return sign;
  if (exponent == 126u) {
    if (fraction == 0) return sign;
    return sign | 0x3f800000u;
  }
  if (exponent >= 150u) return uf;

  shift = 150u - exponent;
  mask = (1u << shift) - 1u;
  remainder = fraction & mask;
  halfway = 1u << (shift - 1u);
  rounded = uf & ~mask;
  if (remainder > halfway ||
      (remainder == halfway && ((uf >> shift) & 1u))) {
    rounded += 1u << shift;
  }
  return rounded;
}

// P17
/*
 * float_i2f - Return bit-level equivalent of expression (float) x.
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 10
 */
unsigned float_i2f(int x) {
  unsigned sign = 0;
  unsigned magnitude;
  unsigned scan;
  unsigned significand;
  unsigned remainder;
  unsigned halfway;
  unsigned mask;
  int highest = 0;
  int shift;

  if (x == 0) return 0;
  magnitude = x;
  if (x < 0) {
    sign = 0x80000000u;
    magnitude = ~magnitude + 1;
  }
  scan = magnitude;
  while (scan > 1) {
    scan >>= 1;
    highest++;
  }

  if (highest <= 23) {
    significand = magnitude << (23 - highest);
  } else {
    shift = highest - 23;
    significand = magnitude >> shift;
    mask = (1u << shift) - 1;
    remainder = magnitude & mask;
    halfway = 1u << (shift - 1);
    if (remainder > halfway ||
        (remainder == halfway && (significand & 1))) {
      significand++;
    }
  }
  return sign | (((highest + 126) << 23) + significand);
}



// P18
/*
 * bitCount - return count of number of 1's in the binary representation of x
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 10
 */
int bitCount(int x) {
    int m8 = 0xff | (0xff << 16);
  int m4 = m8 ^ (m8 << 4);
  int m2 = m4 ^ (m4 << 2);
  int m1 = m2 ^ (m2 << 1);
  int m16 = 0xff | (0xff << 8);
  x = (x & m1) + ((x >> 1) & m1);
  x = (x & m2) + ((x >> 2) & m2);
  x = (x & m4) + ((x >> 4) & m4);
  x = (x & m8) + ((x >> 8) & m8);
  return (x & m16) + ((x >> 16) & m16);
}

// P19
/*
 * bitReverse - Reverse bits in an 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *             bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 34
 *   Rating: 10
 */
int bitReverse(int x)
{
  int m8 = 0xff | (0xff << 16);
  int m4 = m8 ^ (m8 << 4);
  int m2 = m4 ^ (m4 << 2);
  int m1 = m2 ^ (m2 << 1);
  int m16 = 0xff | (0xff << 8);
  x = ((x >> 1) & m1) | ((x & m1) << 1);
  x = ((x >> 2) & m2) | ((x & m2) << 2);
  x = ((x >> 4) & m4) | ((x & m4) << 4);
  x = ((x >> 8) & m8) | ((x & m8) << 8);
  return ((x >> 16) & m16) | (x << 16);
}
