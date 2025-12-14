#include <stdio.h>

void checkExpiry(char names[][50], int expiry[], char cat[][50], char dept[][50],
                 int index, int total, int limit) {

    if (index == total)
        return;

    if (expiry[index] <= limit) {
        printf("ALERT: %s in %s (%s) expires in %d days\n",
               names[index], cat[index], dept[index], expiry[index]);
    }

    checkExpiry(names, expiry, cat, dept, index + 1, total, limit);
}

int main() {
    int n, i, limit;

    printf("How many products: ");
    scanf("%d", &n);

    char names[n][50];
    int expiry[n];
    char cat[n][50];
    char dept[n][50];

    for (i = 0; i < n; i++) {
        printf("Product name: ");
        scanf("%s", names[i]);

        printf("Expiry days: ");
        scanf("%d", &expiry[i]);

        printf("Category name: ");
        scanf("%s", cat[i]);

        printf("Department: ");
        scanf("%s", dept[i]);
    }

    printf("Enter N days limit: ");
    scanf("%d", &limit);

    checkExpiry(names, expiry, cat, dept, 0, n, limit);

    return 0;
}
