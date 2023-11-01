#include <stdio.h>
#include <stdlib.h>

int main() {
  int grade;

  printf("Enter your grade: ");
  scanf("%d", &grade);

  if (grade >= 80)
    printf("Congratulations!\n");
  else if (grade >= 60)
    printf("Not bad...\n");
  else
    printf("You failed, try again...");
  return 0;
}