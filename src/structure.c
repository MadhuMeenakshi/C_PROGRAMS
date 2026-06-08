#include "structures.h"

void structureVsUnion(void)
{
    StructDemo s;
    UnionDemo u;

    printf("Structure Size = %zu\n",
           sizeof(StructDemo));

    printf("Union Size = %zu\n",
           sizeof(UnionDemo));

    s.c = 'A';
    s.i = 100;
    s.f = 3.14f;

    printf("%c %d %.2f\n",
           s.c,s.i,s.f);

    u.i = 100;

    printf("Union int = %d\n",
           u.i);

    u.f = 5.5f;

    printf("Union float = %.2f\n",
           u.f);

    printf("Union int after float write = %d\n",
           u.i);
}


void bitFieldDemo(void)
{
    StatusRegister reg = {0};

    reg.ready = 1;
    reg.error = 0;
    reg.mode = 3;

    printf("Ready = %u\n",
           reg.ready);

    printf("Error = %u\n",
           reg.error);

    printf("Mode = %u\n",
           reg.mode);
}


void structurePaddingDemo(void)
{
    printf("Size = %zu\n",
           sizeof(PaddingDemo));

    printf("Offset a = %zu\n",
           offsetof(PaddingDemo,a));

    printf("Offset b = %zu\n",
           offsetof(PaddingDemo,b));

    printf("Offset c = %zu\n",
           offsetof(PaddingDemo,c));

#pragma pack(push,1)

    struct Packed
    {
        char a;
        int b;
        short c;
    };

#pragma pack(pop)

    printf("Packed Size = %zu\n",
           sizeof(struct Packed));
}


void initDriver(void)
{
    printf("Driver Init\n");
}

void startDriver(void)
{
    printf("Driver Start\n");
}

void functionPointerStructureDemo(void)
{
    Driver drv;

    drv.init = initDriver;
    drv.start = startDriver;

    drv.init();
    drv.start();
}


void dynamicMemoryStructureDemo(void)
{
    Student *s;

    s = malloc(sizeof(Student));

    if(s == NULL)
    {
        printf("Allocation Failed\n");
        return;
    }

    s->id = 101;

    strcpy(s->name,
           "Madhu");

    printf("%d %s\n",
           s->id,
           s->name);

    free(s);
}


void structurePointerDemo(void)
{
    Student *s;

    s = malloc(sizeof(Student));

    if(s == NULL)
        return;

    s->id = 1;

    strcpy(s->name,
           "PointerDemo");

    printf("%d %s\n",
           s->id,
           s->name);

    free(s);
}


void nestedStructureDemo(void)
{
    Employee emp;

    emp.empId = 1001;

    emp.addr.pin = 560001;

    strcpy(emp.addr.city,
           "Bangalore");

    for(int i=0;i<5;i++)
    {
        emp.samples[i] = i+1;
    }

    printf("ID = %d\n",
           emp.empId);

    printf("PIN = %d\n",
           emp.addr.pin);

    printf("CITY = %s\n",
           emp.addr.city);

    for(int i=0;i<5;i++)
    {
        printf("%d ",
               emp.samples[i]);
    }

    printf("\n");
}


void passByValue(Student s)
{
    s.id = 500;

    printf("Inside Value = %d\n",
           s.id);
}

void passByReference(Student *s)
{
    s->id = 500;
}

Student createStudent(void)
{
    Student s;

    s.id = 10;

    strcpy(s.name,
           "Created");

    return s;
}

void structuresAndFunctionsDemo(void)
{
    Student s =
    {
        1,
        "Original"
    };

    passByValue(s);

    printf("After Value = %d\n",
           s.id);

    passByReference(&s);

    printf("After Reference = %d\n",
           s.id);

    Student temp =
    createStudent();

    printf("%d %s\n",
           temp.id,
           temp.name);
}


void introductionToStructuresDemo(void)
{
    Student s =
    {
        1,
        "Madhu"
    };

    printf("%d %s\n",
           s.id,
           s.name);
}


void structureInitializationDemo(void)
{
    Student local =
    {
        .id = 10,
        .name = "Local"
    };

    static Student stat =
    {
        .id = 20,
        .name = "Static"
    };

    printf("%d %s\n",
           local.id,
           local.name);

    printf("%d %s\n",
           stat.id,
           stat.name);
}


void memoryLayoutDemo(void)
{
    typedef struct
    {
        char a;
        int b;
        char c;
    } Layout;

    printf("Size = %zu\n",
           sizeof(Layout));

    printf("Offset a = %zu\n",
           offsetof(Layout,a));

    printf("Offset b = %zu\n",
           offsetof(Layout,b));

    printf("Offset c = %zu\n",
           offsetof(Layout,c));
}