#include <stdio.h>

int main() {
    int n, age, time, i;
    float distance, fare, totalRevenue = 0;
    int totalPassengers = 0;
    float highestFare = 0, lowestFare = 999999;

    printf("========== SKC Smart Bus Fare Calculator ==========\n");

    printf("Enter number of passengers: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("\nEnter Age: ");
        scanf("%d", &age);

        printf("Enter Distance (in km): ");
        scanf("%f", &distance);

        printf("Enter Time (in 24-hour format): ");
        scanf("%d", &time);

        // Base fare
        fare = distance * 10;

        // Discounts
        if (age < 12) {
            fare = fare * 0.5; // 50% off
            printf("Child Discount Applied | ");
        } else if (age > 60) {
            fare = fare * 0.7; // 30% off
            printf("Senior Citizen Discount Applied | ");
        }

        // Peak hour surcharge
        if ((time >= 8 && time <= 10) || (time >= 17 && time <= 20)) {
            fare = fare * 1.2; // 20% surcharge
            printf("Peak Hour Surcharge Applied | ");
        } else {
            printf("No Peak Hour Surcharge Applied | ");
        }

        printf("Final Fare: ₹%.0f\n", fare);

        // Track totals
        totalRevenue += fare;
        totalPassengers++;
        if (fare > highestFare) highestFare = fare;
        if (fare < lowestFare) lowestFare = fare;
    }

    printf("\n========== Fare Summary ==========\n");
    printf("Total Passengers: %d\n", totalPassengers);
    printf("Total Revenue Collected: ₹%.0f\n", totalRevenue);
    printf("Highest Fare of the Day: ₹%.0f\n", highestFare);
    printf("Lowest Fare of the Day: ₹%.0f\n", lowestFare);

    return 0;
}