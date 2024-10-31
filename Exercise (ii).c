
#include <stdio.h>

struct Student {
    char name[100];
    int marks;
};

int main() {
    struct Student student;
    FILE *file;
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    file = fopen("students.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", student.name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &student.marks);
        fprintf(file, "%s %d\n", student.name, student.marks);
    }

    fclose(file);
    printf("Data appended to file successfully.\n");
    return 0;
}
