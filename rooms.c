#include <stdio.h>
#include "struct.h"
#include <string.h>


#define MAX_ROOMS 100

int checkdRoom(char* fileName, struct student* s1);
int checksRoom(char* fileName, struct student* s1);
int checkqRoom(char* fileName, struct student* s1);


int getNumberOfWeeks() {
	int weeks = 0;
	printf("\n\nEnter the number of weeks you want to book the room for: ");
	scanf("%d", &weeks);
	return weeks;
}

void makeRoomFile() {
	FILE* as;
	FILE* ad;
	FILE* aq;
	FILE* bd;

	
	as = fopen("asrooms.dat", "ab");
	ad = fopen("adrooms.dat", "ab");
	aq = fopen("aqrooms.dat", "ab");
	bd = fopen("bdrooms.dat", "ab");

	int asrooms[MAX_ROOMS];
	int adrooms[MAX_ROOMS][2];
	int aqrooms[MAX_ROOMS][4];
	int bdrooms[MAX_ROOMS][2];


	for (int i = 0; i < MAX_ROOMS; ++i) {
		asrooms[i] = 0;
	}

	for (int i = 0; i < MAX_ROOMS; ++i) {
		for (int j = 0; j < 2; ++j) {
			adrooms[i][j] = 0;
		}
	}

	for (int i = 0; i < MAX_ROOMS; ++i) {
		for (int j = 0; j < 4; ++j) {
			aqrooms[i][j] = 0;
		}
	}

	for (int i = 0; i < MAX_ROOMS; ++i) {
		for (int j = 0; j < 2; ++j) {
			bdrooms[i][j] = 0;
		}
	}

	fwrite(asrooms, sizeof(asrooms), 1, as);
	fwrite(adrooms, sizeof(adrooms), 1, ad);
	fwrite(aqrooms, sizeof(aqrooms), 1, aq);
	fwrite(bdrooms, sizeof(bdrooms), 1, bd);

	fclose(as);
	fclose(ad);
	fclose(aq);
	fclose(bd);
}

void getRoomType(struct student* s1) {
	char choice;
	char roomType[3];

	if (strcmp(s1->gender, "male") == 0){
		printf("\nPlease choose the option for which type of room you want: ");
		printf("\na. Single\nb. Double\nc. Quad\n\n >> ");
		scanf(" %c", &choice);

		roomType[0] = 'A';
		
		switch (choice) {
		case 'a':
			roomType[1] = '1';
			roomType[2] = '\0';
			break;

		case 'b':
			roomType[1] = '2';
			roomType[2] = '\0';
			break;
		case 'c':
			roomType[1] = '4';
			roomType[2] = '\0';
			break;
		default:
			printf("Please enter a valid option");
		}
	}
	else {
		roomType[0] = 'B';
		roomType[1] = '2';
		roomType[2] = '\0';
	}
	*s1->roomType = roomType[0];
	*(s1->roomType + 1) = roomType[1];
	*(s1->roomType + 2) = roomType[2];
}

void assignRoom(struct student* s1) {
	if (strcmp(s1->roomType, "A1") == 0) {
		char* fileName = "asrooms.dat";
		if (checksRoom(fileName, &s1) == 0) {
			printf("\nRoom Assigned Successfully");
		}
	}
	else if (strcmp(s1->roomType, "A2") == 0) {
		char* fileName = "adrooms.dat";
		if (checkdRoom(fileName, &s1) == 0) {
			printf("\nRoom Assigned Successfully");
		}
	}
	else if (strcmp(s1->roomType, "A4") == 0) {
		char* fileName = "aqrooms.dat";
		if (checkqRoom(fileName, &s1) == 0) {
			printf("\nRoom Assigned Successfully");
		}
	}
	else {
		char* fileName = "bdrooms.dat";
		if (checkdRoom(fileName, &s1) == 0) {
			printf("\nRoom Assigned Successfully");
		}
	}
}

int checkdRoom(char* fileName, struct student* s1) {
	int rooms[MAX_ROOMS][2];

	FILE* fp;

	fp = fopen(fileName, "rb");

	while (!feof(fp)) {
		fread(rooms, sizeof(rooms), 1, fp);
	}

	for (int i = 0; i < MAX_ROOMS; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (rooms[i][j] == 0) {
				rooms[i][j] = 1;
				*s1->roomNumber = i;
				*(s1->roomNumber+1) = j;
				return 0;
			}
			else if (rooms[MAX_ROOMS-1][1] == 1) {
				return 1;
			}
		}
	}
}

int checkqRoom(char* fileName, struct student* s1) {
	int rooms[MAX_ROOMS][4];

	FILE* fp;

	fp = fopen(fileName, "rb");

	while (!feof(fp)) {
		fread(rooms, sizeof(rooms), 1, fp);
	}

	for (int i = 0; i < MAX_ROOMS; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (rooms[i][j] == 0) {
				rooms[i][j] = 1;
				*s1->roomNumber = i;
				*(s1->roomNumber+1) = j;
				return 0;
			}
			else if (rooms[MAX_ROOMS-1][3] == 1) {
				return 1;
			}
		}
	}
}

int checksRoom(char* fileName, struct student* s1) {
	int rooms[MAX_ROOMS];

	FILE* fp;

	fp = fopen(fileName, "rb");

	while (!feof(fp)) {
		fread(rooms, sizeof(rooms), 1, fp);
	}

	for (int i = 0; i < MAX_ROOMS; ++i) {
		if (rooms[i] == 0) {
			rooms[i] = 1;
			*s1->roomNumber = i;
			return 0;
		}
		else if (rooms[MAX_ROOMS-1] == 1) {
			return 1;
		}
	}
}

void changeRoomType() {

}

void cancelRoom() {

}

void roomAvailability() {

}

void updateRoomFile() {

}

