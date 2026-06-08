#include "bitwise.h"

void bitOps(uint16_t a , int n)
{
    a|=(1<<0);
    a&=~(1<<0);
    a^=(1<<0);

    a|=(1<<15);
    a&=~(1<<15);
    a^+(1<<15);

    a|=(1<<n);
    a&=~(1<<n);
    a^=(1<<n);
}

void byteOps(uint16_t REG , int n)
{
    REG|=(0x00FF<<0);
    REG|=(0xFF00<<0);
    REG|=(0x000F<<0);
    REG|=(0xF000<<0);

    REG|=(1<<n)-1;
    REG&=~(1<<n)-1;
    REG^=(1<<n)-1;
}

void bitCheck(uint8_t x , int n)
{
  if(x&(1<<0))
  {
    printf("the bit is set\n");
  }
  if(x&(1<<7))
  {
    printf("the msb is set\n");
  }
  if(x&(1<<n))
  {
    printf("the %dth bit is set\n",n);
  }

}

void setBits(uint16_t n)
{
  
   int count=0;
   
   while(n!=0)
   {
       n=n&(n-1);
       count++;
       
   }
   printf("%d\n",count);
}

void powOf2(uint16_t n)
{
     if(!(n&(n-1)))
   {
       printf("power of 2 \n");
   }
}

void flipBits(int a, int b)
{
    int x = a ^ b;

    int count = 0;

    while(x)
    {
        count += x & 1;

        x >>= 1;
    }

    printf("%d", count);
}

unsigned int swapOddEven(unsigned int n)
{
    unsigned int even =
    n & 0xAAAAAAAA;

    unsigned int odd =
    n & 0x55555555;

    even >>= 1;

    odd <<= 1;

    return (even | odd);
}

unsigned int reverseBits(unsigned int n)
{
    unsigned int rev = 0;

    for(int i = 0; i < 32; i++)
    {
        rev <<= 1;

        rev |= (n & 1);

        n >>= 1;
    }

    return rev;
}

int multiply9(int n)
{
    return (n<<3) + n;
}

void intSize()
{
    unsigned int x = ~0;

    int count = 0;

    while(x)
    {
        count++;

        x >>= 1;
    }

    printf("%d bits", count);
}

unsigned int endian(unsigned int n)
{
    return ((n>>24)&0x000000FF) |
           ((n>>8 )&0x0000FF00) |
           ((n<<8 )&0x00FF0000) |
           ((n<<24)&0xFF000000);
}

void checkLSB(uint8_t n)
{
    if(n & 1)
        printf("LSB is set\n");
    else
        printf("LSB is not set\n");
}

void checkMSB(uint8_t n)
{
    if(n & (1<<7))
        printf("MSB is set\n");
    else
        printf("MSB is not set\n");
}

void getNthBit(uint16_t n , int pos)
{
    if(n & (1<<pos))
        printf("Bit is 1\n");
    else
        printf("Bit is 0\n");
}

void setNthBit(uint16_t n , int pos)
{
    n |= (1<<pos);

    printf("%u\n", n);
}

void clearNthBit(uint16_t n , int pos)
{
    n &= ~(1<<pos);

    printf("%u\n", n);
}

void toggleNthBit(uint16_t n , int pos)
{
    n ^= (1<<pos);

    printf("%u\n", n);
}

void highestSetBit(uint16_t n)
{
    int pos = -1;

    while(n)
    {
        pos++;

        n >>= 1;
    }

    printf("%d\n", pos);
}

void lowestSetBit(uint16_t n)
{
    int pos = 0;

    while((n & 1) == 0)
    {
        pos++;

        n >>= 1;
    }

    printf("%d\n", pos);
}

void trailingZeros(uint16_t n)
{
    int count = 0;

    while((n & 1) == 0)
    {
        count++;

        n >>= 1;
    }

    printf("%d\n", count);
}

void leadingZeros(uint32_t n)
{
    int count = 0;

    for(int i = 31; i >= 0; i--)
    {
        if(n & (1<<i))
            break;

        count++;
    }

    printf("%d\n", count);
}

void flipAllBits(uint8_t n)
{
    n = ~n;

    printf("%u\n", n);
}

void countZerosOnes(uint8_t n)
{
    int ones = 0;
    int zeros = 0;

    for(int i = 0; i < 8; i++)
    {
        if(n & (1<<i))
            ones++;
        else
            zeros++;
    }

    printf("Ones = %d\n", ones);

    printf("Zeros = %d\n", zeros);
}

void leftRotate(uint8_t n , int rot)
{
    uint8_t result =
    (n << rot) | (n >> (8-rot));

    printf("%u\n", result);
}

void rightRotate(uint8_t n , int rot)
{
    uint8_t result =
    (n >> rot) | (n << (8-rot));

    printf("%u\n", result);
}

void decToBinary(uint16_t n)
{
    int started = 0;

    for(int i = 15; i >= 0; i--)
    {
        if(n & (1<<i))
        {
            printf("1");

            started = 1;
        }
        else if(started)
        {
            printf("0");
        }
    }

    printf("\n");
}

void swapXOR(int a , int b)
{
    a = a ^ b;

    b = a ^ b;

    a = a ^ b;

    printf("a = %d\n", a);

    printf("b = %d\n", b);
}

void oddEven(uint16_t n)
{
    if(n & 1)
        printf("Odd\n");
    else
        printf("Even\n");
}

