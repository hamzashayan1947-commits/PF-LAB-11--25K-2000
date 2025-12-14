#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

struct Student {
    struct Person person;
    int creditHours[20];
    int perCreditFee;
};

int calc_fee(int credits[], int fee, int n) {
    if (n == 0)
        return 0;

    return calc_fee(credits, fee, n - 1) + credits[n - 1] * fee;
}

int main() {
    struct Student s;
    int n;

    printf("Enter student name: ");
    scanf(" %[^\n]", s.person.name);

    printf("Enter age: ");
    scanf("%d", &s.person.age);

    printf("Enter number of subjects: ");
    scanf("%d", &n);

    printf("Enter per credit fee: ");
    scanf("%d", &s.perCreditFee);

    for (int i = 0; i < n; i++) {
        printf("Enter credit hours of subject %d: ", i + 1);
        scanf("%d", &s.creditHours[i]);
    }

    int totalFee = calc_fee(s.creditHours, s.perCreditFee, n);

    printf("\nTotal Semester Fee = %d\n", totalFee);

    return 0;
}