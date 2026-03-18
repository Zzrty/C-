#include <stdio.h>
#include <stdlib.h>

typedef int CyclicDataType;
typedef struct CyclicListNode {
    CyclicDataType data; // 结点数据域
    struct CyclicListNode* next; 
} CyclicListNode;

typedef struct Cyclic
{
    CyclicListNode* head; // 循环链表头指针
    CyclicListNode* tail; // 循环链表尾指针
    int size; // 循环链表的长度
}CyclicList;

CyclicList* createCyclicList() {
    CyclicList* list = (CyclicList*)malloc(sizeof(CyclicList));
    if (list == NULL) 
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

CyclicListNode* buyCyclicListNode(CyclicDataType x) {
    CyclicListNode* newNode = (CyclicListNode*)malloc(sizeof(CyclicListNode));
    if (newNode == NULL) 
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void printCyclicList(CyclicList* list) {
    if (list == NULL || list->head == NULL || list->size == 0) 
    {
        printf("Cyclic List is empty.\n");
        return;
    }
    CyclicListNode* current = list->head;
    do {
    printf("%d ", current->data);
    current = current->next;
    } while (current != list->head);
    printf("\n");
}

int TailInsertCyclicList(CyclicList* list, CyclicDataType x) {
    if (list == NULL)
    {
        fprintf(stderr, "List is NULL\n");
        return -1;
    }
    CyclicListNode* newNode = buyCyclicListNode(x);
    if (list->size == 0)
    {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode;
    } 
    else 
    {
        newNode->next = list->head; 
        list->tail->next = newNode; 
        list->tail = newNode; 
    }
    list->size++;
    return 0;
}

int HeadInsertCyclicList(CyclicList* list, CyclicDataType x) {
    if (list == NULL) {
        fprintf(stderr, "List is NULL\n");
        return -1;
    }
    CyclicListNode* newNode = buyCyclicListNode(x);
    if (list->size == 0) 
    {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode;
    } 
    else 
    {
        newNode->next = list->head;
        list->tail->next = newNode;
        list->head = newNode; 
    }
    list->size++;
    return 0;
}

int InsertCyclicList(CyclicList* list, int pos, CyclicDataType x) {
    if (list == NULL) 
    {
        fprintf(stderr, "List is NULL\n");
        return -1;
    }
    if (pos < 0 || pos > list->size) 
    {
        fprintf(stderr, "Position out of bounds\n");
        return -1;
    }
    if (pos == 0) 
    {
        return HeadInsertCyclicList(list, x);
    } 
    else if (pos == list->size) 
    {
        return TailInsertCyclicList(list, x);
    } 
    else 
    {
        CyclicListNode* newNode = buyCyclicListNode(x);
        CyclicListNode* current = list->head;
        for (int i = 0; i < pos - 1; i++) 
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        list->size++;
        return 0;
    }
}

int DeleteCyclicList(CyclicList* list, int pos) {
    if (list == NULL) 
    {
        fprintf(stderr, "List is NULL\n");
        return -1;
    }
    if (pos < 0 || pos >= list->size) 
    {
        fprintf(stderr, "Position out of bounds\n");
        return -1;
    }
    CyclicListNode* toDelete;
    if (pos == 0) 
    {
        toDelete = list->head;
        if (list->size == 1) 
        {
            list->head = NULL;
            list->tail = NULL;
        } 
        else 
        {
            list->head = toDelete->next;
            list->tail->next = list->head;
        }
    } 
    else 
    {
        CyclicListNode* current = list->head;
        for (int i = 0; i < pos - 1; i++) 
        {
            current = current->next;
        }
        toDelete = current->next;
        current->next = toDelete->next;
        if (toDelete == list->tail) 
        {
            list->tail = current;
        }
    }
    free(toDelete);
    list->size--;
    return 0;
}

int GetCyclicList(CyclicList* list, int pos, CyclicDataType* x) {
    if (list == NULL) 
    {
        fprintf(stderr, "List is NULL\n");
        return -1;
    }
    if (pos < 0 || pos >= list->size) 
    {
        fprintf(stderr, "Position out of bounds\n");
        return -1;
    }
    CyclicListNode* current = list->head;
    for (int i = 0; i < pos; i++) 
    {
        current = current->next;
    }
    *x = current->data;
    return 0;
}

int LocateCyclicList(CyclicList* list, CyclicDataType x) {
    if (list == NULL) 
    {
        fprintf(stderr, "List is NULL\n");
        return -1;
    }
    CyclicListNode* current = list->head;
    for (int i = 0; i < list->size; i++) 
    {
        if (current->data == x) 
        {
            return i;
        }
        current = current->next;
    }
    return -1; 
}

int DestroyCyclicList(CyclicList* list) {
    if (list == NULL) 
    {
        fprintf(stderr, "List is NULL\n");
        return -1;
    }
    CyclicListNode* current = list->head;
    for (int i = 0; i < list->size; i++) 
    {
        CyclicListNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
    return 0;
}