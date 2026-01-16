#include <stdio.h>
// Emirkan Sahin
// 2420161039
// https://www.btkakademi.gov.tr/portal/certificates=zXztnLznpG

void dizi_yazdir(int dizi[], int bas_ind, int son_ind) {
    int i;
    for (i = bas_ind; i <= son_ind; i++) {
        printf(" %2d", dizi[i]);
    }
    printf("\n");
}

void arayaeklemeli_sirala(int dizi[], int BOYUT) {
    int i, j;
    int anahtar;

    for (i = 1; i <= BOYUT - 1; i++) {
        anahtar = dizi[i];

        for (j = i - 1; j >= 0 && anahtar < dizi[j]; j--) {
            dizi[j + 1] = dizi[j];
        }
        dizi[j + 1] = anahtar;

        printf("iter.%2d: ", i);
        dizi_yazdir(dizi, 0, BOYUT - 1);
    }
}

int ikili_arama(int dizi[], int BOYUT, int aranan) {
    int sol = 0;
    int sag = BOYUT - 1;
    int orta;

    while (sol <= sag) {
        orta = (sol + sag) / 2;

        if (dizi[orta] == aranan)
            return 1;
        else if (aranan < dizi[orta])
            sag = orta - 1;
        else
            sol = orta + 1;
    }
    return 0;
}

int main(void) {
    int A[] = {44, 78, 11, 89, 2, 34, 66, 9, 91, 30};
    int N = sizeof(A) / sizeof(A[0]);
    int sayi;

    printf("Orijinal dizi:\n");
    dizi_yazdir(A, 0, N - 1);

    printf("\nInsertion Sort islemleri:\n");
    arayaeklemeli_sirala(A, N);

    printf("\nSiralanmis dizi:\n");
    dizi_yazdir(A, 0, N - 1);

    printf("\nAranacak sayiyi giriniz: ");
    scanf("%d", &sayi);

    if (ikili_arama(A, N, sayi))
        printf("SONUC: %d dizide VAR.\n", sayi);
    else
        printf("SONUC: %d dizide YOK.\n", sayi);

    return 0;
}
