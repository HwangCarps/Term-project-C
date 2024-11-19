//Made & design by DCU HwangYoungung, 24117248 Term Project C
//2024.NOV 19 Tue, 14:22PM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생의 학번, 이메일, 이름을 저장하는 미니 데이터 베이스 프로그램
typedef struct {
    int id;
    char name[50];
    char email[50];
}Student;

void addStudent(Student students[], int *count) { //학생의 정보를 추가하는 함수
    printf("Enter ID : ");
    scanf("%d", &students[*count].id);
    printf("Enter name : ");
    scanf("%s", students[*count].name);
    printf("Enter Email : ");
    scanf("%s", students[*count].email);
    (*count)++;
}
void displayStudents(Student students[], int count) { //화면에 학생의 정보를 띄우는 함수
    for (int i = 0; i < count; i++) {
        printf(" ID: %d, Name: %s, Email: %s\n", students[i].id, students[i].name, students[i].email);
    }
}

void updateStudents(Student students[], int count) { //수정해야할 정보가 생길때 수정할 수 있는 함수
    int id;
    printf("Enter ID to update : ");
    scanf("%d", &id);
    for(int i = 0; i < count; i++) {
        if(students[i].id == id) {
            printf("Enter New Name : \n");
            scanf("%s", students[i].name);
            printf("Enter New Email : ");
            scanf("%s", students[i].email);
            break;
        }
    }
}

void deleteStudents(Student students[], int *count) { // 삭제해야할 학생이 있을경우 삭제하기위한 함수
    int id;
    printf("Enter ID to delete : ");
    scanf("%d", &id);
    for(int i = 0; i < *count; i++){
        if(students[i].id == id) {
            for(int j = i; j < *count-1; j++){
                students[j] = students[j+1];
            }
            (*count)--;
            break;
        }
    }
}

int main() {
    Student students[100];
    int count = 0;
    int choice;
    
    while(1) {
        printf("1. Add Student\n2. DisplayStudents\n3. UpdateStudents\n4. DeleteStudents\n5. Exit\n");
        printf("Choose an option : ");
        scanf("%d", &choice);
        //위의 함수들 역할에 맞는 선택옵션 제시
        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                updateStudents(students, count);
                break;
            case 4:
                deleteStudents(students, &count);
                break;
            case 5:
                return 0;
            default:
                printf("invalid option. Try again\n");
        }
    }
}
