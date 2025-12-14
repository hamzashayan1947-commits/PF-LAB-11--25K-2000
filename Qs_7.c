#include <stdio.h>

struct WeatherData {
    char cityName[50];
    float baseTemp;
    float coolingFactor;
};

float simulateTemp(float currentTemp, float coolingFactor, float variations[], int day, int totalDays) {
    if (day > totalDays)  
        return currentTemp;

    float newTemp = currentTemp + variations[day - 1] - coolingFactor;

    printf("Day %d: Variation = %.2f | Temperature = %.2f\n", day, variations[day - 1], newTemp);

    return simulateTemp(newTemp, coolingFactor, variations, day + 1, totalDays);
}

int main() {
    struct WeatherData w;
    int n;

    printf("Enter city name: ");
    scanf(" %[^\n]", w.cityName);
    printf("Enter base temperature: ");
    scanf("%f", &w.baseTemp);
    printf("Enter cooling factor: ");
    scanf("%f", &w.coolingFactor);
    printf("Enter number of days to simulate: ");
    scanf("%d", &n);

    float variations[n];
    for (int i = 0; i < n; i++) {
        printf("Enter temperature variation for day %d: ", i + 1);
        scanf("%f", &variations[i]);
    }

    printf("\nWeather Forecast for %s \n", w.cityName);
    float finalTemp = simulateTemp(w.baseTemp, w.coolingFactor, variations, 1, n);
    printf("\nPredicted temperature on day %d in %s: %.2f\n", n, w.cityName, finalTemp);

    return 0;
}