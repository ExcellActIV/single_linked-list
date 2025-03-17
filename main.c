#include <stdio.h>
#include "mahasiswa.c"

int main() 
{
    // Langkah 2: Buat list L1 dan L2
    List L1 = createList();
    List L2 = createList();
    
    // Langkah 3: Isi list L1 dengan data terurut
    Mahasiswa mhs[] = 
    {
        {"Sieg", 1, 75},
        {"Veritas", 2, 100},
        {"Dummy", 3, 40},
        {"Atek", 4, 80},
        {"Zayid", 5, 90},
        {"Dummy", 6, 50}
    };

    for (int i = 0; i < 5; i++)
    {
        sortByNama(&L1, mhs[i]);
    }

    // Langkah 4: Tampilkan L1 (ascending nama)
    printf("L1 (ascending nama):\n");
    printList(L1);

    // Langkah 5: Tampilkan L1 (descending nilai)
    sortByNilai(&L1);
    printf("\nL1 (descending nilai):\n");
    printList(L1);

    // Langkah 7-8: Salin ke L2 dan tampilkan
    copyHighScore(L1, &L2);
    printf("\nL2 (Setelah Copy):\n");
    printList(L2);

    // Langkah 9-10: Hapus duplikat dari L2 dan tampilkan
    removeDuplicates(&L2);
    printf("\nL2 (Setelah Hapus Duplikat):\n");
    printList(L2);

    // Langkah 11: Hapus L1 dan L2
    deleteList(&L1);
    deleteList(&L2);

    return 0;
}