#ifndef FIL_H
#define FIL_H

//Define
#define Add_vehicle 1
#define Remove_vehicle 2
#define Sort 3
#define Show_vehicle 4
#define Show_registry 5
#define Random_vehicle 6
#define Quit 0
#define Size 10
#define Name 256
#define Max_line 60
#define ANSI_COLOR_BLUE  "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define Object 1

//lista
typedef struct{
 char name [Name];
 int age;
} Person;

typedef struct{
    char Brand[Name];
    char Model[Name];
    char Reg_number[Name];
    Person Owner;
} Vehicle;

void init_reg (Vehicle *reg, int size);

//Add/Remove
void Addvehicle (Vehicle *reg, int *position);

//registry and Show vehicle
void Showvehicle (Vehicle *reg, int position);
void Showreg (Vehicle *reg, int position);

//Svae/Load
void Save_file (Vehicle *reg, int position);
void Load_file (Vehicle *reg, int *position);


#endif
