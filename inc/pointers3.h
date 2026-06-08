#ifndef POINTERS3_H
#define POINTERS3_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

void pointerArrayBehavior(void);

void sensorTraversal(void);

void constVolatileDemo(void);

void mem_copy(void *dest,const void *src,size_t n);
void voidPointerDemo(void);

struct PeripheralRegs
{
    char status;
    int control;
    short error;
};

struct PackedPeripheralRegs
{
    char status;
    int control;
    short error;
} __attribute__((packed));

void structurePaddingDemo(void);

void init(void);
void start(void);
void stop(void);
void commandTableDemo(void);

int *allocate_buffer(void);
void danglingPointerDemo(void);

void dynamic2DAllocation(void);

typedef int (*CalibArrayPtr)[10];

CalibArrayPtr get_calibration_data(void);
void calibrationDemo(void);

struct Peripheral
{
    uint8_t status;
    uint8_t control;
    uint16_t data;
};

void structArrayPointerDemo(void);

#endif