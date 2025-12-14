#include <stdio.h>

struct File {
    char fileName[50];
    int originalSize;
    float reductionRate;
};

int myCeil(float x) {
    int xi = (int)x;
    if (x > xi)
        return xi + 1;
    return xi;
}

int compress(int size, float rate, int k) {
    if (k == 0)
        return size;

    float reductionFloat = size * rate;
    int reduced = myCeil(reductionFloat);
    int newSize = size - reduced;

    printf("Pass %d --> Reduced: %d  | New Size: %d\n", k, reduced, newSize);

    return compress(newSize, rate, k - 1);
}

int main() {
    struct File f;
    int k;

    printf("Enter file name: ");
    scanf(" %[^\n]", f.fileName);

    printf("Enter original size: ");
    scanf("%d", &f.originalSize);

    printf("Enter reduction rate: ");
    scanf("%f", &f.reductionRate);

    printf("Enter number of compression passes: ");
    scanf("%d", &k);

    printf("\n--- Compression Simulation ---\n");

    int finalSize = compress(f.originalSize, f.reductionRate, k);

    printf("\nFinal Size after %d passes: %d\n", k, finalSize);

    return 0;
}