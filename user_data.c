#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_data.h"

USERDATA g_HeadNode = { 
    .age = 0,
    .name = "__Dummy_Node__",
    .phone = "\0",
    .pNext = NULL
};

void AddNewNode(int age, const char *pszName, const char *pszPhone)
{
    USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
    pNewNode->age = age;
    strncpy(pNewNode->name, pszName, sizeof(pNewNode->name) - 1);
    pNewNode->name[sizeof(pNewNode->name) - 1] = '\0';
    strncpy(pNewNode->phone, pszPhone, sizeof(pNewNode->phone) - 1);
    pNewNode->phone[sizeof(pNewNode->phone) - 1] = '\0';
    pNewNode->pNext = NULL;

    USERDATA* pTail = &g_HeadNode;
    while (pTail->pNext != NULL)
        pTail = pTail->pNext;

    pTail->pNext = pNewNode;
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

USERDATA* SearchToRemove(const char* pszName)
{
    USERDATA* pPrev = &g_HeadNode;
    while (pPrev->pNext != NULL)
    {
        if (strcmp(pPrev->pNext->name, pszName) == 0)
        {
            return pPrev;
        }
        pPrev = pPrev->pNext;
    }
    printf("\"%s\": Not found\n", pszName);
    return NULL;
}

void RemoveNode(USERDATA* pPrev)
{
    USERDATA* pRemove = NULL;

    pRemove = pPrev->pNext;
    pPrev->pNext = pRemove->pNext;
    printf("Remove: %s\n", pRemove->name);
    free(pRemove);
}

void ReleaseList(void)
{
    USERDATA* pTmp = g_HeadNode.pNext;
    USERDATA* pDelete;
    while (pTmp != NULL)
    {
        pDelete = pTmp;
        pTmp = pTmp->pNext;
        printf("Release: [%p] %d, %s, %s [%p]\n",
               pDelete, pDelete->age, pDelete->name, pDelete->phone, pDelete->pNext);

        free(pDelete);
    }
    
    g_HeadNode.pNext = NULL;
}

void PrintList(void)
{
    USERDATA* pTmp = g_HeadNode.pNext;
    while (pTmp != NULL)
    {
        printf("[%p] %d, %s, %s [%p]\n",
               pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
        pTmp = pTmp->pNext;
    }
    putchar('\n');
}

void InitDummyData(void)
{
    AddNewNode(25, "Myung", "010-1111-1111");
    AddNewNode(24, "Hee", "010-2222-2222");
    AddNewNode(27, "Min", "010-3333-3333");
}
