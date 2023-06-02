//1

//#include <stdio.h>
//#include <string.h>
//
//#define MAX_NAME_LEN 50
//#define NUM_STUDENTS 10
//
//// Structure definition for a student
//struct student {
//  char name[MAX_NAME_LEN];
//  int roll_number;
//  float marks;
//};
//
//// Function to read information of students
//void read_students(struct student students[]) {
//  for (int i = 0; i < NUM_STUDENTS; i++) {
//    printf("Enter name, roll number, and marks for student %d:\n", i+1);
//    scanf("%s %d %f", students[i].name, &students[i].roll_number, &students[i].marks);
//  }
//}
//
//// Function to display information of students
//void display_students(struct student students[]) {
//  printf("\nName\tRoll Number\tMarks\n");
//  for (int i = 0; i < NUM_STUDENTS; i++) {
//    printf("%s\t%d\t\t%.2f\n", students[i].name, students[i].roll_number, students[i].marks);
//  }
//}
//
//int main(void) {
//  struct student students[NUM_STUDENTS];
//
//  // Read information of students
//  read_students(students);
//
//  // Display information of students
//  display_students(students);
//
//  return 0;
//}

//2

//#include <stdio.h>
//#include <string.h>
//
//#define MAX_NAME_LEN 50
//#define NUM_EMPLOYEES 10
//
//// Structure definition for an employee
//struct employee {
//  char name[MAX_NAME_LEN];
//  char post[MAX_NAME_LEN];
//  float salary;
//};
//
//// Function to filter employees with salary greater than 10000
//int filter_employees(struct employee employees[], struct employee filtered_employees[]) {
//  int num_filtered_employees = 0;
//
//  for (int i = 0; i < NUM_EMPLOYEES; i++) {
//    if (employees[i].salary > 10000) {
//      filtered_employees[num_filtered_employees++] = employees[i];
//    }
//  }
//
//  return num_filtered_employees;
//}
//
//int main(void) {
//  struct employee employees[NUM_EMPLOYEES];
//  struct employee filtered_employees[NUM_EMPLOYEES];
//
//  // Read information of employees
//  printf("Enter name, post, and salary for %d employees:\n", NUM_EMPLOYEES);
//  for (int i = 0; i < NUM_EMPLOYEES; i++) {
//    printf("Employee %d:\n", i+1);
//    scanf("%s %s %f", employees[i].name, employees[i].post, &employees[i].salary);
//  }
//
//  // Filter employees with salary greater than 10000
//  int num_filtered_employees = filter_employees(employees, filtered_employees);
//
//  // Display filtered employees
//  printf("\nEmployees with salary greater than 10000:\n");
//  printf("Name\tPost\tSalary\n");
//  for (int i = 0; i < num_filtered_employees; i++) {
//    printf("%s\t%s\t%.2f\n", filtered_employees[i].name, filtered_employees[i].post, filtered_employees[i].salary);
//  }
//
//  return 0;
//}

//3

//#include <stdio.h>
//
//// Structure definition to store limits
//struct limits {
//  int lower;
//  int upper;
//};
//
//// Function to display numbers between limits
//void display(struct limits limits) {
//	printf("\nThe numbers between %d and %d are:\n", limits.lower,limits.upper);
//  for (int i = limits.lower; i <= limits.upper; i++) {
//    printf("%d ", i);
//  }
//  printf("\n");
//}
//
//int main(void) {
//  struct limits limits;
//
//  // Read lower and upper limits from user
//  printf("Enter lower and upper limits:\n");
//  scanf("%d %d", &limits.lower, &limits.upper);
//
//  // Display numbers between limits
//  display(limits);
//
//  return 0;
//}

//4

// #include <stdio.h>
// #include <string.h>

// #define MAX_NAME_LEN 50
// #define NUM_STUDENTS 3

// // Structure definition for student info
// struct student_info {
//   char name[MAX_NAME_LEN];
//   int age;
//   char date_of_birth[MAX_NAME_LEN];
// };

// // Structure definition for a student
// struct Student {
//   int roll_no;
//   float marks;
//   struct student_info info;
// };

// int main(void) {
//   struct Student students[NUM_STUDENTS];

//   // Read information for students
//   for (int i = 0; i < NUM_STUDENTS; i++) {
//     printf("Enter roll number, marks, name, age, and date of birth for student %d:\n", i+1);
//     scanf("%d %f %s %d %s", &students[i].roll_no, &students[i].marks, students[i].info.name, &students[i].info.age, students[i].info.date_of_birth);
//   }

//   // Print information for students
//   printf("\nStudent Information:\n");
//   printf("Roll Number\tMarks\tName\tAge\tDate of Birth\n");
//   for (int i = 0; i < NUM_STUDENTS; i++) {
//     printf("%d\t\t%.2f\t%s\t%d\t%s\n", students[i].roll_no, students[i].marks, students[i].info.name, students[i].info.age, students[i].info.date_of_birth);
//   }

//   return 0;
// }

//5

//#include <stdio.h>
//#include <string.h>
//
//#define MAX_NAME_LEN 50
//#define NUM_EMPLOYEES 5
//
//// Structure definition for an employee
//struct employee {
//  char name[MAX_NAME_LEN];
//  float salary;
//  int hours_per_day;
//};
//
//int main(void) {
//  struct employee employees[NUM_EMPLOYEES];
//
//  // Read information for employees
//  for (int i = 0; i < NUM_EMPLOYEES; i++) {
//    printf("Enter name, salary, and hours per day for employee %d:\n", i+1);
//    scanf("%s %f %d", employees[i].name, &employees[i].salary, &employees[i].hours_per_day);
//  }
//
//  // Increase salary based on hours of work per day
//  for (int i = 0; i < NUM_EMPLOYEES; i++) {
//    if (employees[i].hours_per_day == 8) {
//      employees[i].salary += 50;
//    } else if (employees[i].hours_per_day == 10) {
//      employees[i].salary += 100;
//    } else if (employees[i].hours_per_day >= 12) {
//      employees[i].salary += 150;
//    }
//  }
//
//  // Print name and final salary for each employee
//  printf("\nEmployee Information:\n");
//  printf("NAME\tSALARY\n");
//  for (int i = 0; i < NUM_EMPLOYEES; i++) {
//    printf("%s\t%.2f\n", employees[i].name, employees[i].salary);
//  }
//
//  return 0;
//}

//6

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//#define MAX_NAME_LEN 50
//
//// Structure definition for an employee
//struct Employee {
//  char name[MAX_NAME_LEN];
//  float salary;
//  int hours_per_day;
//};
//
//// Function to find the highest salary
//void find_highest_salary(struct Employee* employees, int num_employees) {
//  float highest_salary = employees[0].salary;
//  for (int i = 1; i < num_employees; i++) {
//    if (employees[i].salary > highest_salary) {
//      highest_salary = employees[i].salary;
//    }
//  }
//  printf("\nThe highest salary from the list of employees is: %.2f\n", highest_salary);
//}
//
//int main(void) {
//  int num_employees;
//
//  // Read number of employees from user
//  printf("Enter number of employees: ");
//  scanf("%d", &num_employees);
//
//  // Allocate memory for array of employees
//  struct Employee* employees = (struct Employee*)malloc(num_employees * sizeof(struct Employee));
//
//  // Read information for employees
//  for (int i = 0; i < num_employees; i++) {
//    printf("Enter name, salary, and hours per day for employee %d:\n", i+1);
//    scanf("%s %f %d", employees[i].name, &employees[i].salary, &employees[i].hours_per_day);
//  }
//
//  // Find and print the highest salary
//  find_highest_salary(employees, num_employees);
//
//  // Free memory for array of employees
//  free(employees);
//
//  return 0;
//}

