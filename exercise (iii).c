
#include <stdio.h>

struct Student {
    char name[50];
    int marks;
};

void writeStudentsUsingFwrite(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    struct Student students[5];
    for (int i = 0; i < 5; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);
    }

    fwrite(students, sizeof(struct Student), 5, file);
    fclose(file);
    printf("Data written to file using fwrite successfully.\n");
}

void readStudentsUsingFread(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    struct Student students[5];
    fread(students, sizeof(struct Student), 5, file);
    fclose(file);

    printf("Read data from file:\n");
    for (int i = 0; i < 5; i++) {
        printf("Name: %s, Marks: %d\n", students[i].name, students[i].marks);
    }
}

int main() {
    const char *filename = "students_data.bin";
    writeStudentsUsingFwrite(filename);
    readStudentsUsingFread(filename);
    return 0;
}