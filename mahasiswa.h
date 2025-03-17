#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMA 100

typedef struct
{
    char nama[MAX_NAMA];
    int nim;
    float nilai;
} Mahasiswa;

typedef struct tElmtList *address;
typedef struct tElmtList
{
    Mahasiswa info;
    address next;
} ElmtList;

typedef struct
{
    address first;
} List;

/* 5 Fungsi Utama ADT */
List createList(); // Constructor
void deleteList(List *L); // Destructor
int isEmpty(List L); // Validator
Mahasiswa getElmt(List L, int idx); // Getter
void printList(List L); // PrintObject

/* 5 Fungsi Tambahan ADT */
void sortByNama(List *L, Mahasiswa mhs);
void sortByNilai(List *L);
int countElements(List L);
void copyHighScore(List L, List *L2);
void removeDuplicates(List *L);

#endif
