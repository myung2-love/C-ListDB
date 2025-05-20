#include <stdio.h>
#include "user_data.h"

void TestDeleteNodeByName(const char* pszName)
{
    InitDummyData();
    PrintList();

    USERDATA* pPrev = SearchToRemove(pszName);
    if (pPrev != NULL)
        RemoveNode(pPrev);
    ReleaseList();
    putchar('\n');
}

void TestStep01(void)
{
    puts("---------------- TestStep01() ----------------");
    TestDeleteNodeByName("Myung");
}

void TestStep02(void)
{
    puts("---------------- TestStep02() ----------------");
    TestDeleteNodeByName("Hee");
}

void TestStep03(void)
{
    puts("---------------- TestStep03() ----------------");
    TestDeleteNodeByName("Min");
}

void TestStep04(void)
{
    puts("---------------- TestStep04() ----------------");
    TestDeleteNodeByName("NULL");
}

int main(void)
{
    TestStep01();
    TestStep02();
    TestStep03();
    TestStep04();

    return 0;
}


