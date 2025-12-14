#include <stdio.h>

struct Customer {
    char name[50];
    int meterID;
    int units;
    float bill;
};

float calcTax(int units) {
    float tax = 0;

    if (units > 0) {
        if (units <= 100) {
            tax = units * 0.05;
        }
        else if (units <= 300) {
            tax = (100 * 0.05) + (units - 100) * 0.12;
        }
        else {
            tax = (100 * 0.05) + (200 * 0.12) + (units - 300) * 0.18;
        }
    }

    return tax;
}

int main() {
    struct Customer c;
    float tax_calc; 
    int unit_price = 10 ;

    printf("Enter customer name: ");
    fgets(c.name , 50 , stdin);

    printf("Enter meter ID: ");
    scanf("%d", &c.meterID);

    printf("Enter consumed units: ");
    scanf("%d", &c.units);

    tax_calc = calcTax(c.units);
    c.bill = (c.units * unit_price) + tax_calc;

    printf("\n----Bill Details----\n");
    printf("Name: %s", c.name);
    printf("Meter ID: %d\n", c.meterID);
    printf("Units: %d\n", c.units);
    printf("Total Payable Bill: %.2f$\n", c.bill);

    return 0;
}
