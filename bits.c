/*
 * Modified CS:APP Data Lab
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 */

/* Read the following instructions carefully.

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
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

EXAMPLES OF ACCEPTABLE CODING STYLE:
  // pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
  int pow2plus1(int x) {
      // exploit ability of shifts to compute powers of 2
      return (1 << x) + 1;
  }

  // pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
  int pow2plus4(int x) {
      // exploit ability of shifts to compute powers of 2
      int result = (1 << x);
      result += 4;
      return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any
arithmetic,
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
  1. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  2. Use the btest test harness to check your functions for correctness.
  3. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
 */

/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x)
{
    int y = x >> 30 >> 1;
    return (x ^ y) + (~y + 1);
}

/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000, 0x80000000) = 0,
 *            addOK(0x80000000, 0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y)
{
    int x_s = x >> 30 >> 1;
    int y_s = y >> 30 >> 1;
    int xy_s = (x + y) >> 30 >> 1;
    return (((x_s ^ y_s) & 1) | (~((x_s & y_s) ^ xy_s) & 1));
}

/*
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x)
{
    x = x & (x >> 2);
    x = x & (x >> 4);
    x = x & (x >> 8);
    x = x & (x >> 16);
    return x & 1;
}

/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
    x = x & (x >> 2);
    x = x & (x >> 4);
    x = x & (x >> 8);
    x = x & (x >> 16);
    x = x >> 1;
    return x & 1;
}

/*
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x)
{
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    return x & 1;
}

/*
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x)
{
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    x = x >> 1;
    return x & 1;
}

/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x)
{
    int ans = (1 & (1 ^ ((x | (~x + 1)) >> 30 >> 1)));
    return ans;
}

/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y)
{
    return ~((~x) | (~y));
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x)
{
    int mask1 = 0x55;
    int mask2 = 0x33;
    int mask3 = 0x0f;
    mask1 |= mask1 << 8;
    mask1 |= mask1 << 16;
    mask2 |= mask2 << 8;
    mask2 |= mask2 << 16;
    mask3 |= mask3 << 8;
    mask3 |= mask3 << 16;
    int ans = (x & mask1) + ((x >> 1) & mask1);
    ans = (ans & mask2) + ((ans >> 2) & mask2);
    ans = (ans & mask3) + ((ans >> 4) & mask3);
    return (ans + (ans >> 8) + (ans >> 16) + (ans >> 24)) & 0x3f;
}

/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5, 3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit)
{
    int hi = ~((-1) << (highbit) << 1);
    int lo = ~((1 << lowbit) - 1);
    return hi & lo;
}

/*
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~ and &
 *   Example: bitMatch(0x7, 0xE) = 0x6
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitMatch(int x, int y)
{
    return ~(~x & y) & ~(x & ~y);
}

/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y)
{
    return ~x & ~y;
}

/*
 * bitOr - x|y using only ~ and &
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y)
{
    return ~(~x & ~y);
}

/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x)
{
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 1;
}

/*
 * bitReverse - Reverse bits in a 32-bit word
 *   Examples: bitReverse(0x80000002) = 0x40000001
 *             bitReverse(0x89ABCDEF) = 0xF7D3D591
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int bitReverse(int x)
{
    int mask1 = 0x55;
    int mask2 = 0x33;
    int mask3 = 0x0f;
    int mask4 = 0x00ff;
    int mask5 = 0xff;

    mask1 |= mask1 << 8;
    mask1 |= mask1 << 16;
    mask2 |= mask2 << 8;
    mask2 |= mask2 << 16;
    mask3 |= mask3 << 8;
    mask3 |= mask3 << 16;
    mask4 |= mask4 << 16;
    mask5 |= mask5 << 8;

    x = ((x >> 1) & mask1) | ((x & mask1) << 1);
    x = ((x >> 2) & mask2) | ((x & mask2) << 2);
    x = ((x >> 4) & mask3) | ((x & mask3) << 4);
    x = ((x >> 8) & mask4) | ((x & mask4) << 8);
    x = ((x >> 16) & mask5) | ((x & mask5) << 16);
    return x;
}

/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
    return ~(~(~x & y) & ~(x & ~y));
}

/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m)
{
    int set1 = (x >> (n << 3)) & 0xff;
    int set2 = (x >> (m << 3)) & 0xff;
    int xor = (set1 ^ set2);
    xor = (xor << (n << 3)) | (xor << (m << 3));
    return x ^ xor;
}

/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
    int s = (!!x + (~1 + 1)) & (-1);
    return (y & (-1 + (~s + 1))) | (z & (s));
}

/*
 * countLeadingZero - count the number of zero bits preceding the
 *                    most significant one bit
 *   Example: countLeadingZero(0x00000F00) = 20,
 *            countLeadingZero(0x00000001) = 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int countLeadingZero(int x)
{
    int mask1 = 0x55;
    int mask2 = 0x33;
    int mask3 = 0x0f;
    mask1 |= mask1 << 8;
    mask1 |= mask1 << 16;
    mask2 |= mask2 << 8;
    mask2 |= mask2 << 16;
    mask3 |= mask3 << 8;
    mask3 |= mask3 << 16;

    x = x | (x >> 16);
    x = x | (x >> 8);
    x = x | (x >> 4);
    x = x | (x >> 2);
    x = x | (x >> 1);

    // bitCount
    int ans = (x & mask1) + ((x >> 1) & mask1);
    ans = (ans & mask2) + ((ans >> 2) & mask2);
    ans = (ans & mask3) + ((ans >> 4) & mask3);
    return 32 - ((ans + (ans >> 8) + (ans >> 16) + (ans >> 24)) & 0x3f);
}

/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x)
{
    int s = x & 0x1;
    return !s - 1;
}

/*
 * distinctNegation - returns 1 if x != -x.
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 5
 *   Rating: 2
 */
int distinctNegation(int x)
{
    x = x << 1;
    return !(!x);
}

/*
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
 *                Round toward zero
 *   Examples: dividePower2(15, 1) = 7, dividePower2(-33, 4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int dividePower2(int x, int n)
{
    int s = x >> 30 >> 1;
    return (x + (((1 << n) - 1) & s)) >> n;
}

/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void)
{
    int x = 0x55;
    x |= x << 8;
    x |= x << 16;
    return x;
}

/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *                  Should exactly duplicate effect of C expression (x*3/4),
 *                  including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x)
{
    x = x + (x << 1);
    return (x + ((x >> 30 >> 1) & 3)) >> 2;
}

/*
 * fitsBits - return 1 if x can be represented as an n-bit, two's complement
 *            integer.
 *            1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n)
{
    int mask = 32 + (~n + 1);
    return !(x ^ (x << mask >> mask));
}

/*
 * fitsShort - return 1 if x can be represented as a 16-bit, two's complement
 *             integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x)
{
    return !(x ^ (x << 16 >> 16));
}

/*
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *               floating point argument f.
 *               Both the argument and result are passed as unsigned int's,
 *               but they are to be interpreted as the bit-level
 *               representations of single-precision floating point values.
 *               When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf)
{
    unsigned ma = uf & 0x007fffff;
    unsigned ex = (uf & 0x7f800000);
    return (ex == 0x7f800000 && ma) ? uf : (0x7fffffff & uf);
    //    return (uf > 0x7f800000) ? uf : (0x7fffffff & uf);
}

/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *                  for floating point argument f.
 *                  Argument is passed as unsigned int, but it is to be
 *                  interpreted as the bit-level representation of a
 *                  single-precision floating point value.
 *                  Anything out of range (including NaN and infinity) should
 *                  return 0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
    unsigned s = (uf & 0x80000000) >> 30 >> 1;
    unsigned ma = (uf & 0x007fffff) | 0x00800000;  // 1.xxxx...
    int ex = (((uf & 0x7f800000) >> 23) - 127);
    unsigned ans;
    if (ex < 0)
        return 0;
    else if (ex > 31)
        return 0x80000000u;
    if (ex < 23)
        ans = ma >> (23 - ex);
    else
        ans = ma << (ex - 23);
    if (s)
        return ~ans + 1;

    return ans;
}

/*
 * floatInt2Float - Return bit-level equivalent of expression (float) x
 *                  Result is returned as unsigned int, but it is to be
 *                  interpreted as the bit-level representation of a
 *                  single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
/*
unsigned floatInt2Float(int x)
{
    int s   = x&0x80000000;
    int exp = -1;
    int ma  = 0;

    if (!x)
        return 0;
    else if (x==0x80000000)
        return 0xcf000000;

    if (s) x=~x+1;
    //ma = x;

    while(x) {
        x >>= 2;
        exp++;
    }

    if (exp <= 23) {
        ma = x;
        exp <<= 23;
    }
    else {

    }


    return s | exp | ma;
}
*/
unsigned floatInt2Float(int x)
{
    int i = 1;
    int nega = 0;
    unsigned temp;
    unsigned result;

    if (x & 0x80000000) {
        nega = 1;
        x = ~x + 1;
    }
    if (x == 0) {
        return 0;
    }
    while ((x & 0x80000000) != 0x80000000) {
        ++i;
        x <<= 1;
    }
    result = x << 1;
    temp = result;
    result >>= 9;
    if (nega) {
        result |= 0x80000000;
    } else {
        result &= 0x7FFFFFFF;
    }
    i = (32 - i) + 127;
    result = (result & 0x807FFFFF) | (i << 23);
    if ((temp & 0x00000100) == 0x00000100) {
        if (temp & 0x000000FF) {
            return result + 1;
        } else {
            if (result & 1) {
                return result + 1;
            } else {
                return result;
            }
        }
    }
    return result;
}

/*
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *                Both the arguments are passed as unsigned int's, but
 *                they are to be interpreted as the bit-level representations
 *                of single-precision floating point values.
 *                If either argument is NaN, return 0.
 *                +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
int floatIsEqual(unsigned uf, unsigned ug)
{
    int mask_us = 0x7fffffff;
    int exmask = 0x7f800000;
    int isNaN = ((uf & mask_us) > exmask || (ug & mask_us) > exmask);
    int zeros = (!((uf & mask_us) || ((ug & mask_us))));
    return (!isNaN) && (zeros || (uf == ug));
}

/*
 * floatIsLess - Compute f < g for floating point arguments f and g.
 *               Both the arguments are passed as unsigned int's, but
 *               they are to be interpreted as the bit-level representations
 *               of single-precision floating point values.
 *               If either argument is NaN, return 0.
 *               +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int floatIsLess(unsigned uf, unsigned ug)
{
    int mask_us = 0x7fffffff;
    int exmask = 0x7f800000;
    int mamask = 0x007fffff;
    int uf_s = (uf >> 31) & 1, ug_s = (ug >> 31) & 1;
    int uf_ex = (uf >> 23) & 0xff, ug_ex = (ug >> 23) & 0xff;
    int uf_ma = (uf & mamask), ug_ma = (ug & mamask);
    int isNaN = ((uf & mask_us) > exmask || (ug & mask_us) > exmask);
    if (!(uf & mask_us) && !(ug & mask_us))
        return 0;
    if (isNaN)
        return 0;
    if (uf_s ^ ug_s)
        return uf_s > ug_s;
    if (uf_ex ^ ug_ex)
        return (uf_ex < ug_ex) ^ uf_s;
    if (uf_ma ^ ug_ma)
        return (uf_ma < ug_ma) ^ uf_s;
    return 0;
}

/*
 * floatNegate - Return bit-level equivalent of expression -f for
 *               floating point argument f.
 *               Both the argument and result are passed as unsigned int's,
 *               but they are to be interpreted as the bit-level
 *               representations of single-precision floating point values.
 *               When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf)
{
    if ((uf & 0x7fffffff) > 0x7f800000)
        return uf;
    return uf ^ 0x80000000;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *               (2.0 raised to the power x) for any 32-bit integer x.
 *
 *               The unsigned value that is returned should have the
 *               identical bit representation as the single-precision
 *               floating-point number 2.0^x.
 *               If the result is too small to be represented as a denorm,
 *               return 0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
    unsigned INF = 0xff << 23;
    int e = 127 + x;
    if (x < 0)
        return 0;
    if (e >= 255)
        return INF;
    return e << 23;
}

/*
 * floatScale1d2 - Return bit-level equivalent of expression 0.5*f for
 *                 floating point argument f.
 *                 Both the argument and result are passed as unsigned int's,
 *                 but they are to be interpreted as the bit-level
 *                 representation of single-precision floating point values.
 *                 When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale1d2(unsigned uf)
{
    unsigned s = uf & 0x80000000;
    unsigned ex = uf & 0x7f800000;

    if (ex >= 0x7f800000)
        return uf;
    ex >>= 23;
    if (ex <= 1) {
        if ((uf & 3) == 3)
            uf += 2;
        return s | ((uf >> 1) & 0x007fffff);
    }
    return (uf & 0x807fffff) | ((ex - 1) << 23);
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *               floating point argument f.
 *               Both the argument and result are passed as unsigned int's,
 *               but they are to be interpreted as the bit-level representation
 *               of single-precision floating point values.
 *               When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf)
{
    unsigned s = uf & 0x80000000;
    unsigned ex = uf & 0x7f800000;

    if (ex == 0x7f800000)
        return uf;
    if (ex == 0)
        return s | (uf << 1);
    ex += (1 << 23);
    if (ex == 0x7f800000)
        return s | 0x7f800000;

    return (uf & 0x807fffff) | ex;
}

/*
 * floatScale64 - Return bit-level equivalent of expression 64*f for
 *                floating point argument f.
 *                Both the argument and result are passed as unsigned int's,
 *                but they are to be interpreted as the bit-level
 *                representation of single-precision floating point values.
 *                When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 35
 *   Rating: 4
 */

unsigned floatScale64(unsigned uf)
{
    int exp = (uf & 0x7F800000) >> 23;
    int sign = uf & 0x80000000;
    int cnt = 22;
    if (exp == 0) {
        if (!(uf & 0x007E0000))
            return (uf << 6) | sign;
        while (!(uf & (1 << cnt)))
            cnt--;
        uf <<= (23 - cnt);
        return sign | (uf & 0x807FFFFF) | ((cnt - 16) << 23);
    }
    if (exp == 255)
        return uf;
    exp += 6;
    if (exp >= 255)
        return 0x7F800000 | sign;
    return (uf & 0x807FFFFF) | (exp << 23);
}

/*
 * floatUnsigned2Float - Return bit-level equivalent of expression (float) u
 *                       Result is returned as unsigned int, but it is to be
 *                       interpreted as the bit-level representation of a
 *                       single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatUnsigned2Float(unsigned u)
{
    int i = 1;
    unsigned temp;
    unsigned result;
    if (u == 0) {
        return 0;
    }
    while ((u & 0x80000000) != 0x80000000) {
        ++i;
        u <<= 1;
    }
    result = u << 1;
    temp = result;
    result >>= 9;
    result &= 0x7fffffff;
    i = (32 - i) + 127;
    result = (result & 0x807FFFFF) | (i << 23);
    if ((temp & 0x00000100) == 0x00000100) {
        if (temp & 0x000000FF) {
            return result + 1;
        } else {
            if (result & 1) {
                return result + 1;
            } else {
                return result;
            }
        }
    }
    return result;
}

/*
 * getByte - Extract byte n from word x
 *           Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n)
{
    x = x >> (n << 3);
    return x & 0xff;
}

/*
 * greatestBitPos - return a mask that marks the position of the
 *                  most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4
 */
int greatestBitPos(int x)
{
    int n = 0;
    n += ((!!(x & ((~0) << (n + 16)))) << 4);
    n += ((!!(x & ((~0) << (n + 8)))) << 3);
    n += ((!!(x & ((~0) << (n + 4)))) << 2);
    n += ((!!(x & ((~0) << (n + 2)))) << 1);
    n += (!!(x & ((~0) << (n + 1))));
    return (1 << n) & x;
}

/* howManyBits - return the minimum number of bits required to represent x in
 *               two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
    int sign, bit0, bit1, bit2, bit4, bit8, bit16;
    sign = x >> 30 >> 1;
    x = (sign & ~x) | (~sign & x);
    bit16 = !!(x >> 16) << 4;
    x = x >> bit16;
    bit8 = !!(x >> 8) << 3;
    x = x >> bit8;
    bit4 = !!(x >> 4) << 2;
    x = x >> bit4;
    bit2 = !!(x >> 2) << 1;
    x = x >> bit2;
    bit1 = !!(x >> 1);
    x = x >> bit1;
    bit0 = x;

    return bit16 + bit8 + bit4 + bit2 + bit1 + bit0 + 1;
}

/*
 * implication - return x -> y in propositional logic - 0 for false,
 *               1 for true
 *   Example: implication(1, 1) = 1
 *            implication(1, 0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y)
{
    return (!x) | y;
}

/*
 * intLog2 - return floor(log base 2 of x), where x > 0
 *   Example: intLog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int intLog2(int x)
{
    int a0 = 0xFF | (0xFF << 8);
    int a1 = a0 ^ (a0 << 8);
    int a2 = a1 ^ (a1 << 4);
    int a3 = a2 ^ (a2 << 2);
    int a4 = a3 ^ (a3 << 1);

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    x = (x & a4) + ((x >> 1) & a4);
    x = (x & a3) + ((x >> 2) & a3);
    x = (x & a2) + ((x >> 4) & a2);
    x = (x & a1) + ((x >> 8) & a1);
    x = (x & a0) + ((x >> 16) & a0);
    return x + ~0;
}

/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters
 *                '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
    return !(((!!((x >> 4) ^ 3)) | (x >> 3 & x >> 1) | (x >> 3 & x >> 2)) & 1);
}

/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y)
{
    return !(x ^ y);
}

/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y)
{
    int sign = ((~x & y) >> 30 >> 1) & 1;
    int mark = ~((x ^ y) >> 30 >> 1);
    int NotEqul = !!(x ^ y);
    return sign | ((mark) & (~(x + (~y + 1)) >> 30 >> 1) & NotEqul);
}

/*
 * isLess - if x < y  then return 1, else return 0
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y)
{
    int sign = ((x & ~y) >> 30 >> 1) & 1;
    int mark = ~((x ^ y) >> 30 >> 1);
    return sign | (((mark) & (x + (~y + 1)) >> 30 >> 1) & 1);
}

/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
    int sign = ((x & ~y) >> 30 >> 1) & 1;
    int mark = ~((x ^ y) >> 30 >> 1);
    int equl = !(x ^ y);
    return sign | ((((mark) & (x + (~y + 1)) >> 30 >> 1) | equl) & 1);
}

/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x)
{
    int sign = x >> 30 >> 1;
    return !!sign;
}

/*
 * isNonNegative - return 1 if x >= 0, return 0 otherwise
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNonNegative(int x)
{
    int sign = x >> 30 >> 1;
    return !sign;
}

/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x)
{
    int ans = (1 & (1 & ((x | (~x + 1)) >> 30 >> 1)));
    return ans;
}

/*
 * isNotEqual - return 0 if x == y, and 1 otherwise
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y)
{
    return !!(x ^ y);
}

/*
 * isPallindrome - Return 1 if bit pattern in x is equal to its mirror image
 *   Example: isPallindrome(0x01234567E6AC2480) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int isPallindrome(int x)
{
    int x_ = x;
    int a0 = 0xFF | (0xFF << 8);
    int a1 = a0 ^ (a0 << 8);
    int a2 = a1 ^ (a1 << 4);
    int a3 = a2 ^ (a2 << 2);
    int a4 = a3 ^ (a3 << 1);

    x_ = (x_ << 16) | ((x_ >> 16) & a0);
    x_ = ((x_ & a1) << 8) | ((x_ >> 8) & a1);
    x_ = ((x_ & a2) << 4) | ((x_ >> 4) & a2);
    x_ = ((x_ & a3) << 2) | ((x_ >> 2) & a3);
    x_ = ((x_ & a4) << 1) | ((x_ >> 1) & a4);

    return !(x ^ x_);
}

/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int isPositive(int x)
{
    int sign = x >> 30 >> 1;
    return (!sign & !!x);
}

/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x)
{
    int minus_noe = (~0 ^ (x >> 30 >> 1));
    return !((x & (x + minus_noe)) | !x);
}

/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
    x += 1;
    return (!!x & !(x ^ (~x + 1)));
}

/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x)
{
    return (!!x & !(x ^ (~x + 1)));
}

/*
 * isZero - returns 1 if x == 0, and 0 otherwise
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x)
{
    return !x;
}

/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int leastBitPos(int x)
{
    return x & (~x + 1);
}

/*
 * leftBitCount - returns count of number of consective 1's in
 *                left-hand (most significant) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int leftBitCount(int x)
{
    int a0 = 0xFF | (0xFF << 8);
    int a1 = a0 ^ (a0 << 8);
    int a2 = a1 ^ (a1 << 4);
    int a3 = a2 ^ (a2 << 2);
    int a4 = a3 ^ (a3 << 1);

    x = ~x;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x = ~x;

    x = (x & a4) + ((x >> 1) & a4);
    x = (x & a3) + ((x >> 2) & a3);
    x = (x & a2) + ((x >> 4) & a2);
    x = (x & a1) + ((x >> 8) & a1);
    x = (x & a0) + ((x >> 16) & a0);
    return x;
}

/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x)
{
    int ans = (1 & (1 ^ ((x | (~x + 1)) >> 30 >> 1)));
    return ans;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *                Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n)
{
    return (x >> n) & ~(((1 << 30 << 1) >> n) << 1);
}

/*
 * maximumOfTwo - compute the maximum of two integers without branching
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int maximumOfTwo(int x, int y)
{
    int delta = x - y;
    int neg = delta >> 30 >> 1;
    int max = (~neg & x) | (neg & y);
    int alien = (x ^ y) >> 30 >> 1;
    int x_pos = ~(x >> 30 >> 1);
    return (~alien & max) | (alien & x_pos & x) | (alien & ~x_pos & y);
}

/*
 * minimumOfTwo - compute the minimum of two integers without branching
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int minimumOfTwo(int x, int y)
{
    int sign_x = x >> 30 >> 1;
    int sign_y = y >> 30 >> 1;
    int same = !(!(sign_x ^ sign_y)) + 1;
    int larger = ~((x - y) >> 30 >> 1);
    return (same & ((larger & y) | (~larger & x))) |
           (~same & ((sign_x & x) | (sign_y & y)));
}

/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void)
{
    return ~0;
}

/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *                   Should exactly duplicate effect of C expression (x*5/8),
 *                   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x)
{
    x = x + (x << 2);
    return (x + ((x >> 30 >> 1) & 7)) >> 3;
}

/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
    return ~x + 1;
}

/*
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void)
{
    int ans = 0xaaaa;
    ans |= ans << 16;
    return ans;
}

/*
 * remainderPower2 - Compute x%(2^n), for 0 <= n <= 30
 *                   Negative arguments should yield negative remainders
 *   Examples: remainderPower2(15, 2) = 3, remainderPower2(-35, 3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int remainderPower2(int x, int n)
{
    int sign = x >> 30 >> 1;
    int pos = x + (~((x >> n) << n) + 1);
    int neg;
    x = ~x + 1;
    neg = x + (~((x >> n) << n) + 1);
    neg = ~neg + 1;

    return (~sign & pos) | (sign & neg);
}

/*
 * replaceByte(x,n,c) - Replace byte n in x with c
 *                      Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678, 1, 0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c)
{
    int mask = 0xFF << (n << 3);
    return (mask & (c << (n << 3))) | (~mask & x);
}

/*
 * rotateLeft - Rotate x to the left by n
 *              Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321, 4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
int rotateLeft(int x, int n)
{
    return 42;
}

/*
 * rotateRight - Rotate x to the right by n
 *               Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321, 4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
int rotateRight(int x, int n)
{
    int mask = ((1 << 30 << 1) >> (31 - n));
    int r = (((((1 << 30 << 1) >> n) << 1) & x) >> (32 + (~n + 1)));
    return ((x << n) & mask) | (r & ~mask);
}

/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000, 0x40000000) = 0x7fffffff
 *             satAdd(0x80000000, 0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y)
{
    int sum = x + y;
    int sign = sum >> 30 >> 1;
    int overflow = (((!(x >> 30 >> 1) ^ (y >> 30 >> 1)) &
                     !!((sum >> 30 >> 1) ^ (x >> 30 >> 1)))
                    << 30 << 1) >>
                   30 >> 1;
    return (overflow & ((~sign & (1 << 30 << 1)) | (sign & ~(1 << 30 << 1)))) |
           (~overflow & sum);
}

/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x80000001) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x)
{
    int sign_x = x >> 30 >> 1;
    int sign_2x = (x << 1) >> 30 >> 1;
    int overflow = !(!(sign_x ^ sign_2x)) + 1;
    return (overflow & (x << 1)) | (~overflow & ((~sign_x & ~(1 << 30 << 1)) |
                                                 (sign_x & (1 << 30 << 1))));
}

/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *   Examples: satMul3(0x10000000) = 0x30000000
 *             satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *             satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *              satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *             satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int satMul3(int x)
{
    int x2 = x + x;
    int x3 = x + x2;
    int g = ((x ^ x2) | (x ^ x3)) >> 30 >> 1;
    return ((~g) & x3) + (g & ((1 << 30 << 1) + ~(x >> 30 >> 1)));
}

/*
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *   Examples: sign(130) = 1
 *             sign(-23) = -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 2
 */
int sign(int x)
{
    return (x >> 30 >> 1) | (!!x);
}

/*
 * signMag2TwosComp - Convert from sign-magnitude to two's complement
 *                    where the MSB is the sign bit
 *   Example: signMag2TwosComp(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int signMag2TwosComp(int x)
{
    int sign = x >> 30 >> 1;
    int mag = x & ~(1 << 30 << 1);
    return (sign & (~mag + 1)) | (~sign & mag);
}

/*
 * specialBits - return bit pattern 0xffca3fff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 3
 *   Rating: 1
 */
int specialBits(void)
{
    return ~(0xd7 << 14);
}

/*
 * subtractionOK - Determine if can compute x-y without overflow
 *   Example: subtractionOK(0x80000000, 0x80000000) = 1,
 *            subtractionOK(0x80000000, 0x70000000) = 0,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subtractionOK(int x, int y)
{
    int x_y_not_same_sign = !!((x >> 30 >> 1) ^ (y >> 30 >> 1));
    int y_sub_same_sign = !(((x - y) >> 30 >> 1) ^ (y >> 30 >> 1));
    return !(x_y_not_same_sign & y_sub_same_sign);
}

/*
 * thirdBits - return word with every third bit (starting from the LSB)
 *             set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void)
{
    int x = 0x49;
    x |= (x << 9);
    x |= (x << 18);
    return x;
}


/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void)
{
    return ~(1 << 30 << 1);
}

/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
    return 1 << 30 << 1;
}

/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *                   avoiding errors due to overflow
 *   Examples: trueFiveEighths(11) = 6
 *             trueFiveEighths(-9) = -5
 *             trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 4
 */
int trueFiveEighths(int x)
{
    int const eights = x >> 3;
    int const rem = x & 7;
    return eights + (eights << 2) +
           ((rem + (rem << 2) + (x >> 30 >> 1 & 7)) >> 3);
}

/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *                    avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
    int const four = x >> 2;
    int const rem = x & 3;
    return four + (four << 1) + ((rem + (rem << 1) + (x >> 30 >> 1 & 3)) >> 2);
}

/*
 * twosComp2SignMag - Convert from two's complement to sign-magnitude
 *                    where the MSB is the sign bit
 *                    You can assume that x > TMin
 *   Example: twosComp2SignMag(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int twosComp2SignMag(int x)
{
    int sign = x >> 30 >> 1;
    int mag = (sign & (~x + 1)) | (~sign & x);
    return (sign & (1 << 30 << 1)) | mag;
}

/*
 * upperBits - pads n upper bits with 1's
 *             You may assume 0 <= n <= 32
 *   Example: upperBits(4) = 0xF0000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 1
 */
int upperBits(int n)
{
    int not = !n;
    int zero = ~not + 1;
    return ~zero & ((1 << 30 << 1) >> (n + (~0)));
}
