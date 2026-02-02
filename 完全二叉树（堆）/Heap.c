#include "heap.h"


// 初始化堆
void Heapinit(HP* php)
{
	assert(php); 
	php->a = NULL;	
	php->size = 0;
	php->capacity = 0;  
}

// 打印堆
void Heapprint(HP* php)
{
	assert(php);
	for (size_t i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

// 销毁堆
void Heapdestory(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

// 判断堆是否为空
bool Heapempty(HP* php)
{
	assert(php);
	return php->size == 0;  // 简化
}

// 交换两个元素
static void swap(HPdatatype* p1, HPdatatype* p2)
{
	HPdatatype tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 小堆向上调整
static void AdjustUpForSmallHeap(HPdatatype* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])  // 小堆：子节点小于父节点
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// 大堆向上调整
static void AdjustUpForBigHeap(HPdatatype* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])  // 大堆：子节点大于父节点
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// 小堆向下调整
static void AdjustDownForSmallHeap(HPdatatype* a, int size, int root)
{
	int parent = root;
	int child = parent * 2 + 1;  // 左子节点
	
	while (child < size)
	{
		// 选择左右子节点中较小的一个
		if (child + 1 < size && a[child + 1] < a[child])
		{
			++child;
		}
		
		// 如果子节点小于父节点，交换
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 大堆向下调整
static void AdjustDownForBigHeap(HPdatatype* a, int size, int root)
{
	int parent = root;
	int child = parent * 2 + 1;  // 左子节点
	
	while (child < size)
	{
		// 选择左右子节点中较大的一个
		if (child + 1 < size && a[child + 1] > a[child])
		{
			++child;
		}
		
		// 如果子节点大于父节点，交换
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 入堆操作
void Heappush(HP* php, HPdatatype x)
{
	assert(php);
	
	// 检查是否需要扩容
	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPdatatype* tmp = (HPdatatype*)realloc(php->a, sizeof(HPdatatype) * newCapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newCapacity;
	}
	
	// 插入新元素
	php->a[php->size] = x;
	php->size++;
	
	// 向上调整（默认构建小堆）
	AdjustUpForSmallHeap(php->a, php->size - 1);
	// 如果要构建大堆，使用：AdjustUpForBigHeap(php->a, php->size - 1);
}

// 出堆操作（删除堆顶元素）
void Heappop(HP* php)
{
	assert(php);
	assert(!Heapempty(php));
	
	// 将堆顶元素与最后一个元素交换
	swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	
	// 向下调整（默认小堆）
	AdjustDownForSmallHeap(php->a, php->size, 0);
	// 如果是大堆，使用：AdjustDownForBigHeap(php->a, php->size, 0);
}

// 获取堆顶元素
HPdatatype Heaptop(HP* php)
{
	assert(php);
	assert(!Heapempty(php));
	
	return php->a[0];
}

// 堆排序（使用堆的特性）
void Heapsort(HPdatatype* a, int n)
{
	// 方法1：建立大堆，然后依次取出堆顶元素
	// 方法2：直接在原数组上建立堆，然后进行排序
	
	// 这里演示方法2：升序排序使用大堆，降序排序使用小堆
	
	// 建立大堆（从最后一个非叶子节点开始向下调整）
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDownForBigHeap(a, n, i);
	}
	
	// 排序：每次将堆顶元素（最大值）与末尾元素交换，然后重新调整堆
	for (int i = n - 1; i > 0; i--)
	{
		swap(&a[0], &a[i]);
		AdjustDownForBigHeap(a, i, 0);
	}
}

// 获取堆的大小
int Heapsize(HP* php)
{
	assert(php);
	return php->size;
}