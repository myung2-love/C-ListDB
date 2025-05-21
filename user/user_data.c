#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_data.h"

USERDATA g_HeadNode = { 
    .age = 0,
    .name = "__Dummy Head__",
    .phone = "\0",
    .pNext = NULL
};

USERDATA g_TailNode = {
    .age = 0,
    .name = "__Dummy Tail__",
    .phone = "\0",
    .pNext = NULL
};

void InitList(void)
{
    g_HeadNode.pNext = &g_TailNode;
    g_TailNode.pPrev = &g_HeadNode;
}

void AddNewNodeAtTail(int age, const char *pszName, const char *pszPhone)
{
    USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
    pNewNode->age = age;
    strncpy(pNewNode->name, pszName, sizeof(pNewNode->name) - 1);
    pNewNode->name[sizeof(pNewNode->name) - 1] = '\0';
    strncpy(pNewNode->phone, pszPhone, sizeof(pNewNode->phone) - 1);
    pNewNode->phone[sizeof(pNewNode->phone) - 1] = '\0';
    pNewNode->pPrev = NULL;
    pNewNode->pNext = NULL;

    USERDATA* pPrevNode = g_TailNode.pPrev;
    pNewNode->pPrev = pPrevNode;
    pNewNode->pNext = &g_TailNode;

    pPrevNode->pNext = pNewNode;
    g_TailNode.pPrev = pNewNode;
}

USERDATA* SearchByName(const char* pszName)
{
    USERDATA* pTmp = g_HeadNode.pNext;

    while (pTmp != NULL) 
    {
        if (strcmp(pTmp->name, pszName) == 0)
        {
            printf("\"%s\": Found\n", pszName);
            return pTmp;
        }
        pTmp = pTmp->pNext;
    }

    printf("\"%s\": Not found\n", pszName);
    return NULL;
}

void RemoveNode(USERDATA* pRemove)
{
    USERDATA* pPrev = pRemove->pPrev;
    USERDATA* pNext = pRemove->pNext;

    pPrev->pNext = pRemove->pNext;
    pNext->pPrev = pRemove->pPrev;

    printf("RemoveNode(): %s\n", pRemove->name);
    free(pRemove);
}

void ReleaseList(void)
{
    USERDATA* pTmp = g_HeadNode.pNext;
    USERDATA* pDelete;
    while (pTmp != NULL && pTmp != &g_TailNode)
    {
        pDelete = pTmp;
        pTmp = pTmp->pNext;
        printf("Release: [%p] %d, %s, %s [%p]\n",
               pDelete, pDelete->age, pDelete->name, pDelete->phone, pDelete->pNext);

        free(pDelete);
    }
    
    InitList();
}

void PrintList(void)
{
    USERDATA* pTmp = g_HeadNode.pNext;
    while (pTmp != NULL && pTmp != &g_TailNode)
    {
        printf("[%p] %d, %s, %s [%p]\n",
               pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
        pTmp = pTmp->pNext;
    }
    putchar('\n');
}

void PrintListReverse(void)
{
    USERDATA* pTmp = &g_TailNode;
    while (pTmp != NULL)
    {
        printf("[%p] %d, %s, %s [%p]\n",
               pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
        pTmp = pTmp->pPrev;
    }
    putchar('\n');
}

void InitDummyData(void)
{
    InitList();
    AddNewNodeAtTail(25, "Myung", "010-1111-1111");
    AddNewNodeAtTail(24, "Hee", "010-2222-2222");
    AddNewNodeAtTail(27, "Min", "010-3333-3333");
}
