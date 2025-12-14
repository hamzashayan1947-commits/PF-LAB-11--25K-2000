#include <stdio.h>

struct Route {
    int routeID;
    int distance;
    float basePrice;
    char roadType;
};

float segmentCharge(char type) {
    if (type == 'H') return 5;
    if (type == 'C') return 8;
    return 12;
}

void calcCost(int dist, char type, float *cost) {
    if (dist <= 0)
        return;

    *cost += segmentCharge(type);
    calcCost(dist - 10, type, cost);
}

int main() {
    struct Route r;
    float totalCost = 0;  

    printf("Enter Route ID: ");
    scanf("%d", &r.routeID);

    printf("Enter total distance: ");
    scanf("%d", &r.distance);

    printf("Enter base price: ");
    scanf("%f", &r.basePrice);

    printf("Enter road type (H/C/R): ");
    scanf(" %c", &r.roadType);

    totalCost = r.basePrice; 

    calcCost(r.distance, r.roadType, &totalCost);

    printf("\nFinal Delivery Cost: %.2f\n", totalCost);

    return 0;
}
