#include "unions.h"


/* 1. Union Declaration and Initialization */

union Data
{
    int i;
    float f;
    char str[20];
};

void unionDeclarationDemo(void)
{
    union Data d;

    d.i = 100;
    printf("Int = %d\n", d.i);

    d.f = 3.14f;
    printf("Float = %.2f\n", d.f);

    strcpy(d.str,"Hello");
    printf("String = %s\n", d.str);
}


/* 2. Size of Union */

union SizeUnion
{
    int i;
    double d;
    char c;
};

struct SizeStruct
{
    int i;
    double d;
    char c;
};

void unionSizeDemo(void)
{
    printf("Union Size = %zu\n",
           sizeof(union SizeUnion));

    printf("Struct Size = %zu\n",
           sizeof(struct SizeStruct));
}


/* 3. Accessing Union Members */

void accessingUnionMembersDemo(void)
{
    union Data d;

    d.i = 100;

    printf("i = %d\n", d.i);

    d.f = 5.5f;

    printf("f = %.2f\n", d.f);

    printf("i after writing float = %d\n",
           d.i);
}


/* 4. Nested Union */

union Number
{
    int i;

    union
    {
        float f;
        char c;
    }inner;
};

void nestedUnionDemo(void)
{
    union Number n;

    n.i = 50;

    printf("Outer Int = %d\n", n.i);

    n.inner.f = 3.14f;

    printf("Inner Float = %.2f\n",
           n.inner.f);

    n.inner.c = 'A';

    printf("Inner Char = %c\n",
           n.inner.c);
}


/* 5. Anonymous Union */

struct Device
{
    int id;

    union
    {
        int value;
        float voltage;
    };
};

void anonymousUnionDemo(void)
{
    struct Device d;

    d.id = 1;

    d.value = 100;

    printf("ID = %d\n", d.id);

    printf("Value = %d\n", d.value);

    d.voltage = 5.5f;

    printf("Voltage = %.2f\n",
           d.voltage);
}


/* 6. Pointer to Union */

union Sample
{
    int i;
    float f;
};

void pointerToUnionDemo(void)
{
    union Sample s;

    union Sample *ptr = &s;

    ptr->i = 200;

    printf("Int = %d\n",
           ptr->i);

    ptr->f = 6.25f;

    printf("Float = %.2f\n",
           ptr->f);
}


/* 7. Union Inside Structure */

struct Student
{
    char type;

    union
    {
        int roll_number;
        char id[10];
    }data;
};

void unionsInStructuresDemo(void)
{
    struct Student s1;

    s1.type = 'R';

    s1.data.roll_number = 101;

    printf("Roll = %d\n",
           s1.data.roll_number);

    struct Student s2;

    s2.type = 'I';

    strcpy(s2.data.id,
           "EMP001");

    printf("ID = %s\n",
           s2.data.id);
}


/* 8. Structure Inside Union */

union StructUnion
{
    struct
    {
        int x;
        int y;
    }point;

    int value;
};

void structureInsideUnionDemo(void)
{
    union StructUnion u;

    u.point.x = 10;
    u.point.y = 20;

    printf("x = %d\n",
           u.point.x);

    printf("y = %d\n",
           u.point.y);
}


/* 9. Union Array */

union Mixed
{
    int i;
    float f;
    char c;
};

void unionArrayDemo(void)
{
    union Mixed arr[3];

    arr[0].i = 100;

    arr[1].f = 5.5f;

    arr[2].c = 'A';

    printf("%d\n",
           arr[0].i);

    printf("%.2f\n",
           arr[1].f);

    printf("%c\n",
           arr[2].c);
}


/* 10. Variant Data Storage */

struct Employee
{
    char name[20];

    char type;

    union
    {
        float salary;
        float hourlyWage;
    }pay;
};

void variantDataStorageDemo(void)
{
    struct Employee emp[2];

    strcpy(emp[0].name,
           "John");

    emp[0].type = 'S';

    emp[0].pay.salary =
    50000.0f;

    strcpy(emp[1].name,
           "Alice");

    emp[1].type = 'H';

    emp[1].pay.hourlyWage =
    450.0f;

    for(int i=0;i<2;i++)
    {
        printf("Name: %s\n",
               emp[i].name);

        if(emp[i].type == 'S')
        {
            printf("Salary: %.2f\n",
                   emp[i].pay.salary);
        }
        else
        {
            printf("Hourly Wage: %.2f\n",
                   emp[i].pay.hourlyWage);
        }
    }
}