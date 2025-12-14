#include <stdio.h>

struct Loan {
    char name[20];
    double amount;
    double rate;
    double months;
    double monthly;
};

double pay(struct Loan *l, int n) {
    if (n == 0)
        return l->amount;

    double prev = pay(l, n - 1);
    return prev - l->monthly + (prev * l->rate);
}

int main() {
    struct Loan l;

    printf("Enter Customer Name: ");
    scanf("%[^\n]", l.name);

    printf("Enter Loan Amount: ");
    scanf("%lf", &l.amount);

    printf("Enter Interest Rate (e.g. 0.05): ");
    scanf("%lf", &l.rate);

    printf("Enter Number of Months: ");
    scanf("%lf", &l.months);

    printf("Enter Monthly Installment: ");
    scanf("%lf", &l.monthly);

    double finalAmount = pay(&l, (int)l.months);

    printf("\nFinal Remaining Amount After %.0lf Months = %.2lf\n",
           l.months, finalAmount);

    return 0;
}