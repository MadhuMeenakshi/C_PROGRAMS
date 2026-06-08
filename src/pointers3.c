#include "pointers3.h"

#define REG_BASE 0x40000000


void pointerArrayBehavior(void)
{
    int arr[5] = {10,20,30,40,50};

    int *ptr = arr;

    printf("arr      = %p\n",(void*)arr);
    printf("ptr      = %p\n",(void*)ptr);
    printf("&arr     = %p\n",(void*)&arr);

    printf("sizeof(arr) = %zu\n",sizeof(arr));
    printf("sizeof(ptr) = %zu\n",sizeof(ptr));

    for(int i=0;i<5;i++)
    {
        printf("%d %d\n",
               arr[i],
               *(ptr+i));
    }
}


void sensorTraversal(void)
{
    int sensors[3][3] =
    {
        {100,101,102},
        {110,111,112},
        {120,121,122}
    };

    int *p = &sensors[0][0];

    for(int i=0;i<9;i++)
    {
        printf("%d ",*(p+i));
    }

    printf("\n");
}


void constVolatileDemo(void)
{
    volatile uint32_t *reg_modifiable =
    (volatile uint32_t *)REG_BASE;

    const uint32_t *reg_readonly =
    (const uint32_t *)REG_BASE;

    const volatile uint32_t *reg_const_volatile =
    (const volatile uint32_t *)REG_BASE;

    printf("%p\n",(void*)reg_modifiable);
    printf("%p\n",(void*)reg_readonly);
    printf("%p\n",(void*)reg_const_volatile);

    /*
    *reg_modifiable = 10;

    *reg_readonly = 20;     // error

    *reg_const_volatile=30; // error
    */
}


void mem_copy(void *dest,const void *src,size_t n)
{
    char *d = (char *)dest;

    const char *s = (const char *)src;

    while(n--)
    {
        *d++ = *s++;
    }
}


void voidPointerDemo(void)
{
    int a[5] = {1,2,3,4,5};
    int b[5];

    mem_copy(b,a,sizeof(a));

    for(int i=0;i<5;i++)
    {
        printf("%d ",b[i]);
    }

    printf("\n");

    float x[3] = {1.1,2.2,3.3};
    float y[3];

    mem_copy(y,x,sizeof(x));

    for(int i=0;i<3;i++)
    {
        printf("%.1f ",y[i]);
    }

    printf("\n");
}


void structurePaddingDemo(void)
{
    printf("Normal Struct Size = %zu\n",
           sizeof(struct PeripheralRegs));

    printf("status offset = %zu\n",
           offsetof(struct PeripheralRegs,status));

    printf("control offset = %zu\n",
           offsetof(struct PeripheralRegs,control));

    printf("error offset = %zu\n",
           offsetof(struct PeripheralRegs,error));

    printf("Packed Struct Size = %zu\n",
           sizeof(struct PackedPeripheralRegs));
}


void init(void)
{
    printf("Init\n");
}

void start(void)
{
    printf("Start\n");
}

void stop(void)
{
    printf("Stop\n");
}


void commandTableDemo(void)
{
    void (*cmd_table[])(void) =
    {
        init,
        start,
        stop
    };

    cmd_table[0]();
    cmd_table[1]();
    cmd_table[2]();
}


int *allocate_buffer(void)
{
    int *buf =
    malloc(10*sizeof(int));

    return buf;
}


void danglingPointerDemo(void)
{
    int *ptr = allocate_buffer();

    free(ptr);

    printf("Memory Freed\n");

    /*
    printf("%d",ptr[0]);
    */

    ptr = NULL;
}


void dynamic2DAllocation(void)
{
    int rows = 4;
    int cols = 4;

    uint32_t **reg_block;

    reg_block =
    malloc(rows*sizeof(uint32_t *));

    for(int i=0;i<rows;i++)
    {
        reg_block[i] =
        malloc(cols*sizeof(uint32_t));
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            reg_block[i][j] =
            i*10+j;
        }
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%u ",
                   reg_block[i][j]);
        }

        printf("\n");
    }

    for(int i=0;i<rows;i++)
    {
        free(reg_block[i]);
    }

    free(reg_block);
}


CalibArrayPtr get_calibration_data(void)
{
    static int calib[10] =
    {
        10,20,30,40,50,
        60,70,80,90,100
    };

    return &calib;
}


void calibrationDemo(void)
{
    CalibArrayPtr p =
    get_calibration_data();

    for(int i=0;i<10;i++)
    {
        printf("%d ",(*p)[i]);
    }

    printf("\n");
}


void structArrayPointerDemo(void)
{
    struct Peripheral dev[5];

    struct Peripheral *ptr = dev;

    for(int i=0;i<5;i++)
    {
        ptr->status = i;
        ptr->control = i+1;
        ptr->data = i+100;

        ptr++;
    }

    ptr = dev;

    for(int i=0;i<5;i++)
    {
        printf("%u %u %u\n",
               ptr->status,
               ptr->control,
               ptr->data);

        ptr++;
    }
}