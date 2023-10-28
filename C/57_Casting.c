#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int num1 = 5;  
    double num2 = 3;  // In a impllicit casting you just have to modify the type of one element to change result type.
    double result;
    result = num1/num2; // assuming n2 !=0
    printf("result = %lf \n", result);    

    // We can explict cast changing the type on result var:
    int num3 = 5, num4 =3;
    double result2;
    result2 = num3/(double)num4; // Note that num4 is still int, but changed just for that var
    printf("result2 = %lf \n", result2);

}