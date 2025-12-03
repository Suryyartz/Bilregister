
#include "fil.h"
#include "fil.c"

void menu(){
    int choice = -1;
    int position = 0;
    Vehicle registry[Size];

    while(choice != Quit){
    printf("\n1. Add Vehicle\n"
        "2. Remove Vehicle\n"
        "3. Sort\n"
        "4. Show Vehicle\n"
        "5. Show Registry\n"
        "6. Random Vehicle\n"
        "0. Quit!\n");
 
 scanf("%d", &choice);
 getchar();

 

 switch(choice) {
     
    case Add_vehicle:
     if (position >= Size) {
         printf("\nThe Vehicle slots are full !\n\n");break;
         
     }
        printf("\nVehicle Brand:\n");
        fgets(registry[position].Brand, Name, stdin);
        registry[position].Brand[strcspn(registry[position].Brand, "\n")] = 0;

        printf("\nVehicle Model:\n");
        fgets(registry[position].Model, Name, stdin);
        registry[position].Model[strcspn(registry[position].Model, "\n")] = 0;

        printf("\nVehicle Registry Number:\n");
        fgets(registry[position].Reg_number, Name, stdin);
        registry[position].Reg_number[strcspn(registry[position].Reg_number, "\n")] = 0;

        printf("\nVehicle Owner:\n");
        fgets(registry[position].Owner, Name, stdin);
        registry[position].Owner[strcspn(registry[position].Owner, "\n")] = 0;

        printf("\nOwner Age:\n");
        scanf("%d", &registry[position].Ow_age);
        getchar();  

         position++;
         printf(ANSI_COLOR_BLUE"\nVehicle added.\n" ANSI_COLOR_RESET ); break;

     case Remove_vehicle: printf("\nWhich vehicle would you like to remove (1-10) ?\n"); break; 

     case Sort: printf("\nWihch vehicle would you like see (1-10)?\n"); break; 

     case Show_vehicle: printf("\nCoolant Failure\n"); break; 

     case Show_registry: printf("\nCoolant Failure\n"); break; 
     
     case Random_vehicle: printf("\nCoolant Failure\n"); break; 
     
     case Quit: printf("\nThe program is closing....\n");break; 
      }
    }
}

int main() {
menu();

}



