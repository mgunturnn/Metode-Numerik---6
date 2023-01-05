//Interpolasi Titik
//Fiqal Hanif Al Daris
//2106146
//Pendidikan Ilmu Komputer

#include <stdio.h>

// Direct to Main Program
int main() {
    int input; // Inisialisasi input
    printf("Jumlah titik : "); // Cetak
    scanf("%d", &input); // Memasukan Data
    float x[input];
    float y[input];

    int i, j; // Inisialisasi Perulangan
    for ( i = 0; i < input; i++) {
        printf("\nx[%d] y[%d] : ", i, i);
        scanf("%f", &x[i]);
        scanf("%f", &y[i]);
    }
    
    // Menyimpan Data
    float L[input];
    float Ly = 0;
    float Lx = 0;

    printf("\nTitik interpolasi : ");
    scanf("%f", &Lx);

    // Proses Interpolasi
    for ( i = 0; i < Lx; i++) {
        L[i] = 1;
        for ( j = 0; j < Lx; j++) {
            if(i != j) { L[i] *= (Lx - x[j])/(x[i] - x[j]); }
        }
        Ly += L[i] * y[i];
    }
    
    //Cetak Hasil
    printf("\np2(%.4f) : %.4f", Lx, Ly);
    return 0;
}