#include <stdio.h>

int main() {
    int passengers, i;
    char name[50];
    int age;
    float distance, time;
    float baseFare, fare;
    float totalRevenue = 0;
    float highestFare = 0, lowestFare = 0;

    printf("========= SRM Smart Bus Fare Calculator =========\n\n");
    printf("Enter number of passengers: ");
    scanf("%d", &passengers);

    i = 1;
    while (i <= passengers) {
        printf("\n--- Passenger %d ---\n", i);

        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter age: ");
        scanf("%d", &age);

        printf("Enter distance (in km): ");
        scanf("%f", &distance);

        printf("Enter travel time (24-hour format): ");
        scanf("%f", &time);

        baseFare = distance * 10;
        fare = baseFare;

        int isPeak = 0;
        if ((time >= 8 && time <= 10) || (time >= 17 && time <= 20)) {
            isPeak = 1;
        }

        int discountApplied = 0;
        if (age < 12) {
            fare = fare * 0.5;
            discountApplied = 1;
            printf("Passenger: %s | Base Fare: ₹%.0f | Child Discount Applied", name, baseFare);
        } else if (age >= 60) {
            fare = fare * 0.7;
            discountApplied = 1;
            printf("Passenger: %s | Base Fare: ₹%.0f | Senior Citizen Discount Applied", name, baseFare);
        } else {
            printf("Passenger: %s | Base Fare: ₹%.0f", name, baseFare);
        }

        // Apply peak hour only if no discount applied
        if (!discountApplied && isPeak == 1) {
            fare = fare * 1.2;
            printf(" | Peak Hour Surcharge Applied");
        }

        // Minimum fare rule
        if (fare < 20)
            fare = 20;

        printf(" | Final Fare: ₹%.0f\n", fare);

        totalRevenue += fare;

        if (i == 1) {
            highestFare = fare;
            lowestFare = fare;
        } else {
            if (fare > highestFare)
                highestFare = fare;
            if (fare < lowestFare)
                lowestFare = fare;
        }

        i++;
    }

    printf("\n========= Daily Summary =========\n");
    printf("Total Passengers: %d\n", passengers);
    printf("Total Revenue Collected: ₹%.0f\n", totalRevenue);
    printf("Highest Fare: ₹%.0f\n", highestFare);
    printf("Lowest Fare: ₹%.0f\n", lowestFare);
    printf("=================================\n");

    return 0;
}