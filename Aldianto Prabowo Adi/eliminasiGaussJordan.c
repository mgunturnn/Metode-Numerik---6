//Gauss Jordan
//Aldianto Prabowo Adi - 2106146 - Pendidikan Ilmu Komputer

#include <stdio.h>
#define size 5

// VARIABEL GLOBAL
int i, j, k;

// FUNGSI ELIMINASI GAUSS JORDAN
void gaussJordan(double arr[size][size], int ordo){
    double pembagi, v[size];

    printf("\t[Matriks A | B]\n");
    printMatrix(arr, ordo);

    // melakukan perulangan seluruh matriks
    for(i = 0; i < ordo; i++){
        pembagi = arr[i][i];

        // melakukan perulangan tiap-tiap baris pada matriks
        for(k = i; k < ordo + 1; k++){
            arr[i][k] /= pembagi;
        }

        // melakukan perulangan tiap-tiap kolom pada matriks
        // melakukan cek secara vertikal agar array selain x[i][i] bernilai 0
        for(j = i + 1; j < ordo + 1; j++){
            v[i] = arr[j][i];

            // melakukan perulangan tiap-tiap baris pada matriks kolom yang sama
            for(k = i; k < ordo + 1; k++){
                arr[j][k] = arr[j][k] - v[i] * arr[i][k];
            }
        }
    }

    for(i = 1; i < ordo; i++){
        for(j = 1; j < i + 1; j++){
            v[j] = arr[j - 1][i];
            for(k = i; k < ordo + 1; k++){
                arr[j - 1][k] -= v[j] * arr[i][k];
            }
        }
    }

    printf("\n\t[Matriks Identitas]\n");
    printMatrix(arr, ordo);
}

// Print
void printMatrix(double arr[size][size], int ordo){
    for (i = 0; i < ordo; i++){
        printf("|");
        for (j = 0; j < ordo; j++){
            printf("%.3f   ", arr[i][j]);

            // menuliskan vektor matriks B
            if (j == ordo - 1){
                printf("\t|   %.3lf", arr[i][j + 1]);
            }
        }
        printf("|\n");
    }
}


// Main Program
int main(){
    // Definisi tipe data
    double arr[size][size];
    int ordo;


    printf("\n\nSOLUSI PERSAMAAN SISTEM LINEAR METODE GAUSS JORDAN\n");
    printf("\nPress any key to continue.\n");
    getchar();

    printf("\nMasukkan Ordo Matriks : ");
    scanf("%d", &ordo);

    // jika inputan ordo kurang dari 2
    if(ordo < 2){
        printf("\nBentuk Matriks Minimal 2x2");
        return 0; // program akan terhenti
    }

    printf("\n[ Terkonfirmasi Matriks Ordo %dx%d ]\n\n", ordo, ordo);

    // Input User
    // Melakukan Perulangan Tiap Baris Matriks
    for(i = 0; i < ordo; i++) {
        printf("Input Matriks Baris ke-%d\n", (i + 1));

        // Melakukan input tiap item kedalam matriks
        printf("Matriks A\n");
        for(j = 0; j < ordo; j++){
            printf("[%d][%d] = ", (i+1), (j+1));
            scanf("%lf", &arr[i][j]);

            // Menyimpan vektor B ke dalam array dimensi kedua indeks terakhir
            // jika telah sampai pada ujung baris (ordo - 1), input vektor B ke array arr[i][j+1]
            if(j == ordo - 1){
                printf("Matriks B\n");
                printf("[%d][%d] = ", (i+1), (j+1));
                scanf("%lf", &arr[i][j + 1]);
            }
        }
        printf("\n");
    }

    // Operasi Gauss Jordan
    gaussJordan(arr, ordo);

    // menampilkan nilai x1, x2, x3
    for(i = 0; i < ordo; i++){
        printf("\nX%d = %.3lf", (i + 1), arr[i][ordo]);
    }
    return 0;
}