#include<stdio.h>
#include<math.h>

void calc(float param1, float param2, char operator){

float resultat;
int resultat1;

switch (operator) {
case '+':       resultat1 = param1 + param2;
 printf("%d\n", resultat1);
 break;
case'-':        resultat1 = param1 - param2;
 printf("%d\n", resultat1);
 break;
case'*':        resultat1 = param1 * param2;
 printf("%d\n", resultat1);
 break;
case'/':       if(param2 == 0){
    printf("NaN\n"); break;
 } else{ resultat = param1 / param2;
    printf("%f\n", resultat); break;
 }
case'^':        resultat1= pow( param1,param2);
    printf("%d\n", resultat1);
 break;
}
}
int main(){
float a,b;
char operation;

scanf("%f", &a);

scanf(" %c", &operation);

scanf("%f", &b);

calc(a, b, operation);

return 0;
}

