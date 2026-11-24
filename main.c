/*
 * Bus Ticket Booking System
 * Team 1
 * Concepts: Structures, Arrays, File Handling
 */
#include <stdio.h>

#define TOTAL_SEATS 20

int seats[TOTAL_SEATS] = {0}; // 0 = Available, 1 = Booked

void showBusLayout() {
    printf("\n=========== BUS SEATING LAYOUT ===========\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i] == 0) printf("[Seat %02d: OPEN]   ", i + 1);
        else               printf("[Seat %02d: BOOKED] ", i + 1);
        if ((i + 1) % 2 == 0) printf("   "); // aisle
        if ((i + 1) % 4 == 0) printf("\n");
    }
    printf("==========================================\n");
}

int main() {
    int choice, seatNum;
    printf("=== INTERCITY EXPRESS BUS BOOKING ===\n");
    while (1) {
        printf("\n1. View Seating Chart\n2. Reserve Seat\n3. Cancel Seat\n4. Exit\nOption: ");
        if (scanf("%d", &choice) != 1 || choice == 4) break;

        switch (choice) {
            case 1:
                showBusLayout();
                break;
            case 2:
                showBusLayout();
                printf("Enter seat number to reserve (1-%d): ", TOTAL_SEATS);
                scanf("%d", &seatNum);
                if (seatNum < 1 || seatNum > TOTAL_SEATS) {
                    printf("Invalid seat number!\n");
                } else if (seats[seatNum - 1] == 1) {
                    printf("Seat %d is already reserved!\n", seatNum);
                } else {
                    seats[seatNum - 1] = 1;
                    printf(">> Seat %d successfully confirmed!\n", seatNum);
                }
                break;
            case 3:
                printf("Enter seat number to cancel: ");
                scanf("%d", &seatNum);
                if (seatNum < 1 || seatNum > TOTAL_SEATS) {
                    printf("Invalid seat number!\n");
                } else if (seats[seatNum - 1] == 0) {
                    printf("Seat %d was not booked.\n", seatNum);
                } else {
                    seats[seatNum - 1] = 0;
                    printf(">> Seat %d has been cancelled.\n", seatNum);
                }
                break;
            default:
                printf("Invalid selection.\n");
        }
    }
    printf("Thank you for using Bus Booking.\n");
    return 0;
}
