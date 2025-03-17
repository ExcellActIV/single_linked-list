#include "mahasiswa.h"

List createList()
{
    List L;
    L.first = NULL;
    return L;
}

void deleteList(List *L)
{
    address P, Q;
    P = L->first;
    while (P != NULL)
    {
        Q = P;
        P = P->next;
        free(Q);
    }
    L->first = NULL;
}

int isEmpty(List L)
{
    return (L.first == NULL);
}

Mahasiswa getElmt(List L, int idx)
{
    address P = L.first;
    for (int i = 0; i < idx; i++)
    {
        P = P->next;
    }
    return P->info;
}

void printList(List L)
{
    address P = L.first;
    while (P != NULL)
    {
        printf("Nama: %s | NIM: %d | Nilai: %.2f\n", P->info.nama, P->info.nim, P->info.nilai);
        P = P->next;
    }
}

void sortByNama(List *L, Mahasiswa mhs)
{
    address newNode = (address)malloc(sizeof(ElmtList));
    newNode->info = mhs;
    newNode->next = NULL;

    if (isEmpty(*L) || strcmp(mhs.nama, L->first->info.nama) < 0)
    {
        newNode->next = L->first;
        L->first = newNode;
    }
    else
    {
        address current = L->first;
        while (current->next != NULL && strcmp(mhs.nama, current->next->info.nama) > 0)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void sortByNilai(List *L) 
{
    int swapped = 1;
    address ptr1, ptr2 = NULL;

    if (isEmpty(*L))
    {
        return;
    }

    while (swapped)
    {
        swapped = 0;
        ptr1 = L->first;
        while (ptr1->next != ptr2)
        {
            if (ptr1->info.nilai < ptr1->next->info.nilai)
            {
                Mahasiswa temp = ptr1->info;
                ptr1->info = ptr1->next->info;
                ptr1->next->info = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    }
}

int countElements(List L)
{
    int count = 0;
    address P = L.first;
    while (P != NULL)
    {
        count++;
        P = P->next;
    }
    return count;
}

void copyHighScore(List L, List *L2)
{
    address P = L.first;
    while (P != NULL)
    {
        if (P->info.nilai > 70)
        {
            sortByNama(L2, P->info);
        }
        P = P->next;
    }
}

void removeDuplicates(List *L)
{
    address current = L->first;
    while (current != NULL && current->next != NULL)
    {
        if (strcmp(current->info.nama, current->next->info.nama) == 0)
        {
            address temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
}