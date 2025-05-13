#ifndef USER_DATA_H
#define USER_DATA_H

typedef struct USERDATA
{
    int age;
    char name[32];
    char phone[32];
    struct USERDATA* pNext;
} USERDATA;

extern USERDATA* g_pHeadNode;

void AddNewNode(int age, const char* pszName, const char* pszPhone);
USERDATA* SearchByName(const char* pszName);
USERDATA* SearchToRemove(USERDATA** ppPrev, const char* pszName);
void RemoveNode(USERDATA* pPrev);
void ReleaseList(void);
void PrintList(void);
void InitDummyData(void);

#endif
