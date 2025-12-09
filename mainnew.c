#include "fil.h"
//Library
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void menu(){
    int choice = -1;
    int position = 0;
    Vehicle reg[Size];
    Load_file(reg, &position);
    
while(choice != Quit){
    printf("\n1. Add Vehicle\n"
        "2. Remove Vehicle\n"
        "3. Sort\n"
        "4. Show Vehicle\n"
        "5. Show Registry\n"
        "6. Random Vehicle\n"
        "0. Quit!\n");

        scanf("%d", &choice);
        while (getchar() != '\n');  
        
    switch(choice) {
    case Add_vehicle: 
    Addvehicle(reg,&position);
    break;

    case Remove_vehicle: printf("\nWhich vehicle would you like to remove (1-10) ?\n"); break; 

    case Sort: printf("\nSorting..\n"); break; 

    case Show_vehicle:{ 
        printf("\nWihch vehicle would you like see (1-10)?\n"); 
        break; 
    }

    case Show_registry: {
    Showreg(reg, position);
    break;
    }
    
    case Random_vehicle: printf("\nrandom\n"); 
    break; 
     
    case Quit:{
    Save_file(reg, position);
    printf("\nThe program is closing....\n");
    break; 
    }
    
    default:
    printf("\nerorr\n");
      }
}
}

int main() {
menu();

}


// hur ska vi skrivs ut en viss position
//när vi skriver en bokstav koden funnkar, hur fixar vi det.


