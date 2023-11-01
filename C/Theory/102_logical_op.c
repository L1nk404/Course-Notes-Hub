#include <stdio.h>
#include <stdlib.h>

int main() {

  // Logical Operators //

  int money, grade;
  printf("Enter money and grade: \n");
  scanf("%d%d", &money, &grade);

  // AND "&&"
  if (money > 50 && grade > 50)
    printf("Money AND grade greater than 50 \n");

  // OR "||"
  if (money < 50 || grade < 50)
    printf("Money OR grade lesser than 50 \n");

  // NOT IS <-> "!!"
  if (!(grade > 50))
    printf("Grade IS NOT greater than 50 \n");
  if (!(money > 50))
    printf("Money IS NOT greater than 50\n");

  return 0;
}