#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

void lessThanRequired(int *lengthOfText) {
    printf("The length of your text is less than specified, please update your text\n");
    *lengthOfText = MIN_LENGTH;
}

void equalThanRequired() {
    printf("Thank you, Your text length is correct\n");
}

void moreThanRequired(int *lengthOfText) {
    printf("Your text is too long, please reduce the text\n");
    *lengthOfText = MIN_LENGTH;
}

int checkLengthRequirement(char* text) {
    int length = strlen(text);
    if (length < MIN_LENGTH)
        return 0;
    else if (length == MIN_LENGTH)
        return 1;
    else
        return 2;
}

int main() {
    int lengthOfText, selectOption;
    FILE *fptr = NULL;
    char text[MAX_LENGTH];

    fptr = fopen("file.txt", "r");

    if (fptr == NULL) {
        printf("Error");
        exit(1);
    }

    fgets(text, MAX_LENGTH, fptr);

    fclose(fptr);

    selectOption = checkLengthRequirement(text);

    void (*options[3])(int *) = {lessThanRequired, equalThanRequired, moreThanRequired};
    options[selectOption](&lengthOfText);

    printf("\nThe Length is updated to %d", lengthOfText);

    return 0;
}

// Program C ini memeriksa panjang file teks dan memperbaruinya untuk memenuhi persyaratan panjang minimum. 
// Dimulai dengan menentukan konstanta panjang maksimum dan minimum serta tiga fungsi yang akan dipanggil berdasarkan panjang teks.
// Fungsi ini lessThanRequiredmengatur panjang teks ke panjang minimum dan meminta pengguna untuk memperbarui teks. 
// Fungsi ini equalThanRequiredmenunjukkan bahwa panjang teks sudah benar. 
// Fungsi ini moreThanRequiredmengatur panjang teks ke panjang minimum dan meminta pengguna untuk memperkecil teks.
// Fungsi ini checkLengthRequirementmemeriksa panjang teks dan mengembalikan 0, 1, atau 2 berdasarkan apakah panjangnya kurang dari, sama dengan, atau lebih besar dari panjang minimum. 
// Dalam mainfungsinya, program membuka file, membaca isinya ke dalam array karakter, dan menutup file. Kemudian, ia memeriksa panjang teks dan memanggil salah satu dari tiga fungsi berdasarkan nilai yang dikembalikan.
// Terakhir, program mencetak panjang teks yang diperbarui.
// Tujuannya adalah untuk memastikan bahwa panjang teks dalam file memenuhi persyaratan panjang minimum yang ditentukan.
// Panjang maksimum ditetapkan pada tahun 2024 dan panjang minimum ditetapkan pada tahun 1945.