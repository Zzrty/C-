#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int HPdatatype;

typedef struct Heap {
    HPdatatype* a;
    int size;
    int capacity;
} HP;

// 基本操作
void Heapinit(HP* php);
void Heapdestory(HP* php);
void Heappush(HP* php, HPdatatype x);
void Heappop(HP* php);
HPdatatype Heaptop(HP* php);
bool Heapempty(HP* php);
int Heapsize(HP* php);
void Heapprint(HP* php);

// 堆排序
void Heapsort(HPdatatype* a, int n);

#endif // __HEAP_H__