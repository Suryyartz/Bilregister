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





void Removevehicle(Vehicle *reg, int *position) {
    if (*position < 1) {
        printf("\nThe registry is empty.\n");
        return;
    }
    int selection = -1;
    printf("Enter a number between 1 and %d:\n", *position);
    while( scanf ("%d", &selection) != 1) {
        printf("Invalid, enter numbers only\n");
        while (getchar() != '\n') {
            continue;
        }
    }
    if(selection<1 || selection>*position ){
        printf("Invalid, please enter a valid car number\n");
    }
    
    else{
        int subselction = selection -1;
        for (int i = subselction; i < *position - 1; i++){
            reg[i] = reg[i + 1];
        }
        strcpy(reg[*position - 1].Brand, "");
        strcpy(reg[*position - 1].Model, "");
        strcpy(reg[*position - 1].Reg_number, "");
        strcpy(reg[*position - 1].Owner.name, "");
        reg[*position - 1].Owner.age = 0;
        (*position)--;
        printf(ANSI_COLOR_BLUE"\nVehicle #%d removed.\n" ANSI_COLOR_RESET, selection);
    }

}






void Showvehicle(Vehicle *reg, int position){
    if (position < 1) {
        printf("\nThe registry is empty.\n");
        return;
    }

    int selection = -1;
    printf("Enter a number between 1 and %d:\n", position);
    
    while (scanf("%d", &selection) != 1) {
        printf("Invalid, enter numbers only\n");
        while (getchar() != '\n') {
            continue;
        }
    }
    if(selection<1 || selection>position ){
        printf("Invalid, please enter a valid car number\n");
    }
    else{
        int subselction = selection -1;
        printf("\n" ANSI_COLOR_BLUE "=== VEHICLE #%d ===\n" ANSI_COLOR_RESET, selection);
        printf("  Brand: %s\n", reg[subselction].Brand);
        printf("  Model: %s\n", reg[subselction].Model);
        printf("  Registry Number: %s\n", reg[subselction].Reg_number);
        printf("  Owner: %s\n", reg[subselction].Owner.name);
        printf("  Owner Age: %d\n", reg[subselction].Owner.age);
    }
}

void Showreg(Vehicle *reg, int position){
    printf("\n" ANSI_COLOR_BLUE "=== VEHICLE REGISTRY ===\n" ANSI_COLOR_RESET);
    if (position < 1) {
        printf("The registry is empty.\n");
    }
        else {
            for (int i = 0; i < position; i++) {
                printf("\nVehicle #%d:\n", i + 1);
                printf("  Brand: %s\n", reg[i].Brand);
                printf("  Model: %s\n", reg[i].Model);
                printf("  Registry Number: %s\n", reg[i].Reg_number);
            }
            printf("\nTotal vehicles: %d\n", position);
        }
}

void Sort_vehicles(Vehicle *reg, int position) {
    if (position < 2) {
        printf("\nNot enough vehicles to sort. Need at least 2 vehicles.\n");
        return;
    }
    
    Vehicle temp;
    for (int i = 0; i < position - 1; i++) {
        for (int j = 0; j < position - i - 1; j++) {
            if (strcmp(reg[j].Brand, reg[j + 1].Brand) > 0) {
                temp = reg[j];
                reg[j] = reg[j + 1];
                reg[j + 1] = temp;
            }
        }
    }
    
    printf(ANSI_COLOR_BLUE "\nVehicles sorted by brand name.\n" ANSI_COLOR_RESET);
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

void Randomvehicle(Vehicle *reg, int *position) {
    if (*position >= Size) {
        printf("\nThe Vehicle slots are full !\n\n");
        return;
    }
    
    char *brands[] = {
        "Toyota", "Honda", "Ford", "BMW", "Mercedes-Benz",
        "Audi", "Volkswagen", "Tesla", "Nissan", "Chevrolet",
        "Volvo", "Hyundai", "Kia", "Mazda", "Subaru"
    };
    int num_brands = 15;
    
    char *models[] = {
        "Camry", "Civic", "F-150", "3 Series", "C-Class",
        "A4", "Golf", "Model 3", "Altima", "Silverado",
        "XC90", "Elantra", "Sorento", "CX-5", "Outback"
    };
    int num_models = 15;
    
    char *reg_prefixes[] = {
        "ABC", "DEF", "GHI", "JKL", "MNO",
        "PQR", "STU", "VWX", "YZA", "BCD",
        "EFG", "HIJ", "KLM", "NOP", "QRS"
    };
    int num_prefixes = 15;
    
    char *owner_names[] = {
        "John Smith", "Emma Johnson", "Michael Brown", "Sarah Davis", "David Wilson",
        "Lisa Anderson", "Robert Taylor", "Jennifer Martinez", "Christopher Lee", "Amanda White",
        "James Miller", "Maria Garcia", "William Jones", "Patricia Williams", "Richard Moore"
    };
    int num_names = 15;
    
    int age_min = 18;
    int age_max = 100;
    
    int brand_idx = rand() % num_brands;
    int model_idx = rand() % num_models;
    int reg_prefix_idx = rand() % num_prefixes;
    int name_idx = rand() % num_names;
    int reg_number = 100 + (rand() % 900); 
    int age = age_min + (rand() % (age_max - age_min + 1)); 
    
    char reg_number_str[Name];
    snprintf(reg_number_str, Name, "%s%d", reg_prefixes[reg_prefix_idx], reg_number);
    
    strcpy(reg[*position].Brand, brands[brand_idx]);
    strcpy(reg[*position].Model, models[model_idx]);
    strcpy(reg[*position].Reg_number, reg_number_str);
    strcpy(reg[*position].Owner.name, owner_names[name_idx]);
    reg[*position].Owner.age = age;
    
    (*position)++;
    printf(ANSI_COLOR_BLUE "\nRandom vehicle added: %s %s\n" ANSI_COLOR_RESET, 
           brands[brand_idx], models[model_idx]);
}
