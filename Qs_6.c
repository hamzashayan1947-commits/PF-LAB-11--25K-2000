#include <stdio.h>

struct Patient {
    char name[50];
    int age;
    float healthScore;
};
struct DailyReport {
    int day;
    float scoreChange;
};
float updateHealth(float currentScore, struct DailyReport reports[], int index, int totalDays) {
    if (index == totalDays)  
        return currentScore;
    
    currentScore += reports[index].scoreChange;
    
    printf("Day %d: Score change = %.2f | Current health = %.2f\n",
           reports[index].day, reports[index].scoreChange, currentScore);
    
    return updateHealth(currentScore, reports, index + 1, totalDays);
}

int main() {
    struct Patient p;
    int n;

    printf("Enter patient name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter patient age: ");
    scanf("%d", &p.age);
    printf("Enter initial health score: ");
    scanf("%f", &p.healthScore);
    printf("Enter number of days: ");
    scanf("%d", &n);

    struct DailyReport reports[n];
    for (int i = 0; i < n; i++) {
        reports[i].day = i + 1;
        printf("Enter health score change for day %d: ", i + 1);
        scanf("%f", &reports[i].scoreChange);
    }

    printf("\n============Final Report============\n");
    float finalScore = updateHealth(p.healthScore, reports, 0, n);
    printf("\nFinal health score after %d days for %s: %.2f\n", n, p.name, finalScore);

    return 0;
}