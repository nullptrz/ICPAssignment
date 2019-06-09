#pragma once

typedef struct date{
	int day;
	int month;
	int year;
} date;

struct student{
	int studentID;
	char firstName[50];
	char lastName[50];
	char gender[10];
	int age;
	int roomNumber[2];
	char roomType[3];
	//char Block[2];
	double paymentDue;
	double paymentMade;
	double amountReceivable;
	struct date bookingDate;
	int durationOfBooking; //in weeks
	char services[50];
};

