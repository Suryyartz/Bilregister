#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "file.h"



void meny(){
    int choice = -1;
    while(choice != Quit){
    printf("1. Add Vehicle\n"
        "2. Remove Vehicle\n"
        "3. Sort\n"
        "4. Show Vehicle\n"
        "5. Show Registry\n"
        "6. Random Vehicle\n"
        "0. Quit!\n");
 
 scanf("%d", &choice);
 
 char Brand[Size][Name]= {0};
 char Model[Size][Name] = {0};
 char Reg_number[Size]= {0};
 char Owner[Size]= {0};
 int Ow_age[Size]= {0};
 
 int position = 0;

 switch(choice) {
     
    case Add_vehicle: printf("Vehicle type:\n"); 
     if (position >= Size) {
         printf("The car slots are full !\n");
         
     }
     
         scanf("%s", Brand[position]);
     
         position++;
         printf("Vehicle added.\n\n");
         
     


     case Remove_vehicle: printf("Which vehicle would you like to remove (1-10) ?\n"); break; 

     case Sort: printf("Wihch vehicle would you like see (1-10)?\n"); break; 

     case Show_vehicle: printf("Coolant Failure\n"); break; 

     case Show_registry: printf("Coolant Failure\n"); break; 
     
     case Random_vehicle: printf("Coolant Failure\n"); break; 
     
     case Quit: printf("The program is closing....\n");break; 
      }
    }
}
int main() {


meny();
}



