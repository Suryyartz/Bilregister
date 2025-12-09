#include "fil.h"
//Library
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void init_reg (Vehicle *reg, int size){
    for (int i = 0; i < size; i ++){
        strcpy(reg[i].Brand, "");
        strcpy(reg[i].Model, "");
        strcpy(reg[i].Reg_number, "");
        strcpy(reg[i].Owner.name, "");
        reg[i].Owner.age = 0;
    }
}


void Addvehicle (Vehicle *reg, int *position) {
    if (*position >= Size) {
        printf("\nThe Vehicle slots are full !\n\n");
        
       }
    else{

       printf("\nVehicle Brand:\n");
       fgets(reg[*position].Brand, Name, stdin);
       strtok(reg[*position].Brand,"\n");

       printf("\nVehicle Model:\n");
       fgets(reg[*position].Model, Name, stdin);
       strtok(reg[*position].Model,"\n");

       printf("\nVehicle Registry Number:\n");
       fgets(reg[*position].Reg_number, Name, stdin);
       strtok(reg[*position].Reg_number,"\n");


       printf("\nVehicle Owner:\n");
       fgets(reg[*position].Owner.name, Name, stdin);
       strtok(reg[*position].Owner.name,"\n");
       

       printf("\nOwner Age:\n");        
       while (scanf("%d", &reg[*position].Owner.age) != 1) {
       printf("Invalid input! Numbers only:\n");

       while (getchar() != '\n');  
       }

       (*position)++;
       printf(ANSI_COLOR_BLUE"\nVehicle added.\n" ANSI_COLOR_RESET );
       }
}

void Showreg(Vehicle *reg, int position){
    printf("\n" ANSI_COLOR_BLUE "=== VEHICLE REGISTRY ===\n" ANSI_COLOR_RESET);
    if (position < 1) {
        printf("The registry is empty.\n");
    } else {
        for (int i = 0; i < position; i++) {
            printf("\nVehicle #%d:\n", i + 1);
            printf("  Brand: %s\n", reg[i].Brand);
            printf("  Model: %s\n", reg[i].Model);
            printf("  Registry Number: %s\n", reg[i].Reg_number);
        }
        printf("\nTotal vehicles: %d\n", position);
    }
}

void Load_file(Vehicle *reg, int *position){
   FILE *fp = fopen("reg.dat", "rb");
   if (fp == NULL) {
       *position = 0;
       return;
   }

   int count = 0;
   if (fread(&count, sizeof(int), Object, fp) != Object) {
       fclose(fp);
       *position = 0;
       return;
   }

   if (count < 0 || count > Size) {
       fclose(fp);
       *position = 0;
       return;
   }

   if (fread(reg, sizeof(Vehicle), count, fp) != (size_t)count) {
       fclose(fp);
       *position = 0;
       return;
   }

   *position = count;
   fclose(fp);
}

void Save_file(Vehicle *reg, int position){
   FILE *fp = fopen("reg.dat", "wb");
   if (fp == NULL) {
       printf("File could not be opened");
       return;
   }
   if (fwrite(&position, sizeof(int), Object, fp) != Object) {
       printf("Error when writing the number of vehicles");
       fclose(fp);
       
   }

   if (fwrite(reg, sizeof(Vehicle), position, fp) != (size_t)position) {
       printf("Error when writing the data of vehicles");
       fclose(fp);
       
   }

   fclose(fp);
}
