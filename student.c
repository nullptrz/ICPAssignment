#include <stdio.h>
#include "struct.h"
#include "date.h"
#include "rooms.h"

void registerStudent() {
	FILE* fp;

	struct student s1;

	fp = fopen("students.dat", "ab");

	printf("\nEnter student ID: ");
	scanf("%d", &s1.studentID);
	printf("\nEnter first name:");
	scanf("%s", s1.firstName);
	printf("\nEnter last name: ");
	scanf("%s", s1.lastName);
	printf("\nSpecify your gender[Male|Female]: ");
	scanf("%s", s1.gender);
	printf("%s", s1.gender);
	printf("\nEnter your age: ");
	scanf("%d", &s1.age);
	getRoomType(&s1);
	assignRoom(&s1);
	s1.durationOfBooking = getNumberOfWeeks();
	date today = getDateToday();
	s1.bookingDate.day = today.day;
	s1.bookingDate.month = today.month;
	s1.bookingDate.year = today.year;
	displayPayment(s1.durationOfBooking, s1.roomType, &s1);
	makePayment(&s1);


	fwrite(&s1, sizeof(s1), 1, fp);

	fclose(fp);
} 

void displayAllStudents() {
	FILE* fp;
	struct student s;

	fp = fopen("students.dat", "rb");
	
	printf("\n========================================================================================================================\n\n");
	printf("\t\t\t\t\t\tSTUDENT RECORDS\n\n");
	printf("========================================================================================================================\n\n");
	
	printf("\t+--------------------------------------------------------------------------------------------------------+\n");
	printf("\t|Student ID\tFirst Name\tLast Name\tGender\t\tAge\t\tRoom Type\t\t |");
	printf("\n\t+--------------------------------------------------------------------------------------------------------+\n");
	int i = 1;
	while (fread(&s, sizeof(s), 1, fp) != NULL) {
		printf("\n\n\ %d\t%d\t\t%s\t\t%s\t\t%s\t\t%d\t\t%s\n\n",i ,s.studentID, s.firstName, s.lastName, s.gender, s.age, s.roomType);
		++i;
	}
	printf("========================================================================================================================\n\n");

	fclose(fp);
}

void searchStudent(int studentID) {

}

