#ifndef USER_DATA_H
#define USER_DATA_H

typedef struct USERDATA
{
    int age;
    char name[32];
    char phone[32];
    struct USERDATA* pPrev;
    struct USERDATA* pNext;
} USERDATA;

void AddNewNodeAtTail(int age, const char* pszName, const char* pszPhone);
USERDATA* SearchByName(const char* pszName);
void RemoveNode(USERDATA* pPrev);
void ReleaseList(void);
void PrintList(void);
void PrintListReverse(void);
void InitDummyData(void);

#endif
