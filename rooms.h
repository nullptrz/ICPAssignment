#pragma once
#include "struct.h"

void makeRoomFile();
char* getRoomType(struct student* s1);
void assignRoom(struct student* s1);
int checkdRoom(char* fileName, struct student* s1);
int checkqRoom(char* fileName, struct student* s1);
int checksRoom(char* fileName, struct student* s1);