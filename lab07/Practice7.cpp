#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include "SLList.h"

void printSLList(const SLList *list)
{
    if (!list) return;
    std::cout << list->getData() << std::endl;
    SLList* next = list->next();
    while (next != nullptr)
    {
        std::cout << next->getData() << std::endl;
        next = next->next();
    }
}

int randMinMax(const int min, const int max)
{
    return min + (rand() % (max - min + 1));
}

bool containsElement(int* set, int* len, int e)
{
    for (int i = 0; i < *len; i++)
    {
        if (set[i] == e)
            return true;
    }
    set[*len] = e;
    (*len)++;
    return false;
}

void removeRepeated(SLList* list)
{
    int* array = new int[10];
    int len = 0;
    SLList *prev = list;
    containsElement(array, &len, prev->getData());
    SLList *next = list->next();
    while (next != nullptr)
    {
        if (containsElement(array, &len, next->getData()))
        {
            next = next->next();
            prev->removeNext();
            continue;
        }
        prev = next;
        next = next->next();            
    }
    delete array;
}

int findKthElement(int k, const SLList* list)
{
    int count = 1;
    SLList* next = list->next();
    while (next != nullptr)
    {
        count++;
        next = next->next();
    }

    next = list->next();
    while (count != k + 1)
    {
        count--;
        next = next->next();
    }
    return next->getData();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));



    SLList* l1 = SLList::beginList(randMinMax(0, 5));
   
    for (int i = 1; i < 10; i++)
        l1->addElement(randMinMax(0, 5));

    std::cout << "Лист до удаления повторяющихся элементов" << std::endl;
    printSLList(l1);
    std::cout << std::endl;


    removeRepeated(l1);
    std::cout << "Лист после удаления повторяющихся элементов" << std::endl;
    printSLList(l1);
    std::cout << std::endl;


    std::cout << "3 с конца элемент (в новом листе): " << std::endl;
    std::cout << findKthElement(3, l1);
}
