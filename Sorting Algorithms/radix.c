#include <stdio.h>

#define MAX_DIGITS 10
#define MAX_STUDENTS 5

typedef struct {
    int matnum;
    float gpa;
    int age;
} Student;

void SortArray(Student studentarray[], int n, int exp) {
    Student output[n];
    int count[10] = {0};
    int i;

    for (i = 0; i < n; i++) {
        count[(studentarray[i].matnum / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(studentarray[i].matnum / exp) % 10] - 1] = studentarray[i];
        count[(studentarray[i].matnum / exp) % 10]--;
    }

    for (i = 0; i < n; i++) {
        studentarray[i] = output[i];
    }
}

void radixSort(Student studentarray[], int n) {
    int max_num = studentarray[0].matnum;
    int exp;

    for (int i = 1; i < n; i++) {
        if (studentarray[i].matnum > max_num) {
            max_num = studentarray[i].matnum;
        } 
    }

    for (exp = 1; max_num / exp > 0; exp *= 10) {
        SortArray(studentarray, n, exp);
    }
}

void displayStudents(Student studentarray[], int n) {
    printf("Student info:\n");
    printf("MatNum\t\tGPA\t\tAge\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%.2f\t\t%d\n", studentarray[i].matnum, studentarray[i].gpa, studentarray[i].age);
    }
}

int main() {
    Student studentarray[MAX_STUDENTS] = {
        {1101, 2.5, 18},
        {1012, 3.5, 18},
        {1011, 3.1, 12},
        {1040, 2.9, 19},
        {1013, 3.1, 17}
    };

    printf("Before sorting:\n");
    displayStudents(studentarray, MAX_STUDENTS);

    radixSort(studentarray, MAX_STUDENTS);

    printf("After sorting:\n");
    displayStudents(studentarray, MAX_STUDENTS);

    return 0;
}
#include <stdio.h>

#define MAX_DIGITS 10
#define MAX_STUDENTS 5

typedef struct {
    int matnum;
    float gpa;
    int age;
} Student;

void SortArray(Student studentarray[], int n, int exp) {
    Student output[n];
    int count[10] = {0};
    int i;

    for (i = 0; i < n; i++) {
        count[(studentarray[i].matnum / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(studentarray[i].matnum / exp) % 10] - 1] = studentarray[i];
        count[(studentarray[i].matnum / exp) % 10]--;
    }

    for (i = 0; i < n; i++) {
        studentarray[i] = output[i];
    }
}

void radixSort(Student studentarray[], int n) {
    int max_num = studentarray[0].matnum;
    int exp;

    for (int i = 1; i < n; i++) {
        if (studentarray[i].matnum > max_num) {
            max_num = studentarray[i].matnum;
        }
    }

    for (exp = 1; max_num / exp > 0; exp *= 10) {
        SortArray(studentarray, n, exp);
    }
}

void displayStudents(Student studentarray[], int n) {
    printf("Student info:\n");
    printf("MatNum\t\tGPA\t\tAge\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%.1f\t\t%d\n", studentarray[i].matnum, studentarray[i].gpa, studentarray[i].age);
    }
}

int main() {
    Student studentarray[MAX_STUDENTS] = {
        {1101, 2.5, 18},
        {1012, 3.5, 18},
        {1011, 3.1, 12},
        {1040, 2.9, 19},
        {1013, 3.1, 17}
    };

    printf("Before sorting:\n");
    displayStudents(studentarray, MAX_STUDENTS);

    radixSort(studentarray, MAX_STUDENTS);

    printf("After sorting:\n");
    displayStudents(studentarray, MAX_STUDENTS);

    return 0;
}
 