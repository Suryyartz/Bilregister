#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Add_vehicle 1
#define Remove_vehicle 2
#define Sort 3
#define Show_vehicle 4
#define Show_registry 5
#define Random_vehicle 6
#define Quit 0


int main() {
    printf("1. Add Vehicle\n"
           "2. Remove Vehicle\n"
           "3. Sort\n"
           "4. Show Vehicle\n"
           "5. Show Registry\n"
           "6. Random Vehicle\n"
           "0. Quit!\n");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case Add Vehicle: printf("Vehicle type:\n"); break;

        case Remove Vehicle: printf("Which vehicle would you like to remove (1-10) ?\n"); break;

        case Sort: printf("Wihch vehicle would you like see (1-10)?\n"); break;

        case Show_vehicle: printf("Coolant Failure\n"); break;

        case Show_registry: printf("Coolant Failure\n"); break;
        
        case Random_vehicle: printf("Coolant Failure\n"); break;
        
        case Quit: printf("The program is closing....\n"); break;
        
        default: printf("Unknown Status! \n");
    }

}



