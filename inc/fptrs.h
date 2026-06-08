
#include <stdio.h>
#include <string.h>

int add(int x , int y)
{
    return x+y;
}
int sub(int x , int y)
{
    return x-y;
}
int div(int x , int y)
{
    return x/y;
}
int multiply(int x , int y)
{
    return x*y;
}

/**********fptr simple usage*************/
// int main() {
//     int(*fptr)(int , int);
//     fptr=add;
    
//     printf("the sum is %d \n",fptr(2,8));
//         fptr=sub;
    
//     printf("the difference is %d \n",fptr(2,8));
//         fptr=div;
    
//     printf("the quotient is %d \n",fptr(8,2));
//         fptr=multiply;
    
//     printf("the product is %d \n",fptr(2,8));
    
    

//     return 0;
// }


/**********fptr table*************/

/*
int main() {
    int(*fptr[3])(int , int);
    fptr[0]=add;
    fptr[1]=sub;
    fptr[2]=divi;
    fptr[3]=multiply;
    
    printf("the sum is %d \n",fptr[0](2,8));
        
    
    printf("the difference is %d \n",fptr[1](2,8));
        
    
    printf("the quotient is %d \n",fptr[2](8,2));
        
    
    printf("the product is %d \n",fptr[3](2,8));
    
    

    return 0;
}
*/

/*


/************************fptr into a structure***************************** */
/*
typedef struct
{
   int(*fptr[3])(int , int);
}calc;


int main() {
    
    calc c;
    c.fptr[0]=add;
    c.fptr[1]=sub;
    c.fptr[2]=divi;
    c.fptr[3]=multiply;
    
    printf("the sum is %d \n",c.fptr[0](2,8));
        
    
    printf("the difference is %d \n",c.fptr[1](2,8));
        
    
    printf("the quotient is %d \n",c.fptr[2](8,2));
        
    
    printf("the product is %d \n",c.fptr[3](2,8));
    
    

    return 0;
}
*/

/***************factorial fptr*****************/
/*

int(*fptr)(int);
int fact(int n)
{
    if(n==1)
    
        return 1;
    
    return n*fptr(n-1);
}
int main() {
    // Write C code here
    fptr=fact;
    printf("%d .",fptr(7));

    return 0;
}
*/




/******************chained fptrs***********************/
/*
int doubleValue(int x)
{
    return x * 2;
}

int increment(int x)
{
    return x + 1;
}

int square(int x)
{
    return x * x;
}

void chainedFunctions(void)
{
    int (*pipeline[3])(int) =
    {
        doubleValue,
        increment,
        square
    };

    int value = 5;

    for(int i=0;i<3;i++)
    {
        value = pipeline[i](value);
    }

    printf("%d\n",value);
}
*/

/**********************fptr returning fptr***************************/
/*
int add(int a,int b)
{
    return a+b;
}

int subtract(int a,int b)
{
    return a-b;
}

int multiply(int a,int b)
{
    return a*b;
}

int (*getOperation(char *name))(int,int)
{
    if(strcmp(name,"add")==0)
        return add;

    if(strcmp(name,"subtract")==0)
        return subtract;

    if(strcmp(name,"multiply")==0)
        return multiply;

    return NULL;
}
*/

void reverseString(char *str)
{
    int len = strlen(str);

    for(int i=0;i<len/2;i++)
    {
        char temp = str[i];

        str[i] = str[len-1-i];

        str[len-1-i] = temp;
    }
}

void toUpperCase(char *str)
{
    while(*str)
    {
        if(*str>='a' && *str<='z')
            *str -= 32;

        str++;
    }
}

void countVowels(char *str)
{
    int count = 0;

    while(*str)
    {
        char ch = *str;

        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
           ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
        {
            count++;
        }

        str++;
    }

    printf("Vowels=%d\n",count);
}

void (*stringOps[3])(char *) =
{
    reverseString,
    toUpperCase,
    countVowels
};

void consoleLog(char *msg)
{
    printf("%s\n",msg);
}

void fileLog(char *msg)
{
    FILE *fp = fopen("log.txt","a");

    fprintf(fp,"%s\n",msg);

    fclose(fp);
}

void networkLog(char *msg)
{
    printf("Sending: %s\n",msg);
}

// void (*logger)(char *);

// int main()
// {
// logger = consoleLog;

// logger("Hello");
// }

void buttonPressEvent(void)
{
    printf("Button Pressed\n");
}

void sensorTriggerEvent(void)
{
    printf("Sensor Triggered\n");
}

// int main()
// {
// void (*eventTable[2])(void) =
// {
//     buttonPressEvent,
//     sensorTriggerEvent
// };
// eventTable[0]();
// eventTable[1]();
// }

void timerInterrupt(void)
{
    printf("Timer Interrupt\n");
}

void keyboardInterrupt(void)
{
    printf("Keyboard Interrupt\n");
}

void errorInterrupt(void)
{
    printf("Error Interrupt\n");
}
// void (*ISR[3])(void)=
// {
//     timerInterrupt,
//     keyboardInterrupt,
//     errorInterrupt
// };