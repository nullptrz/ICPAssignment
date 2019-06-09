#include "struct.h"

double getServices(struct student* s1);

double calculatePayment(int numberOfWeeks,struct student* s1) {
	double rate = 0;

	if (strcmp(s1->roomType,"A1") == 0){
		rate = 400;
	}
	else if (strcmp(s1->roomType, "A2") == 0 || strcmp(s1->roomType, "B2") == 0) {
		rate = 200;
	}
	else if (strcmp(s1->roomType, "A4") == 0){
		rate = 100;
	}
	
	double serviceRate = getServices(&s1);
	
	double total = numberOfWeeks * (rate + serviceRate);

	s1->amountReceivable = total;

	return total;
}

void makePayment(struct student* s1) {
	double payment = 0.0;

	printf("\nPlease enter the amount you want to pay: ");
	scanf("%lf", &payment);

	s1->paymentMade = payment;
	s1->paymentDue = s1->amountReceivable - s1->paymentMade;
	
}

double getPaymentDue(struct student* s1) {
	return s1->paymentDue;
}

double getServices(struct student* s1) {
	char gym = 'N';
	char laundry = 'N';
	double serviceRate = 0.0;

	printf("\nWould you like to use Gym service[Y/N]: ");
	scanf(" %c", &gym);
	
	printf("\nWould you like to use the laundry service[Y/N]: ");
	scanf(" %c", &laundry);

	if (gym == 'Y' && laundry == 'Y') {
		s1->services[0] = 'g';
		s1->services[1] = 'y';
		s1->services[2] = 'm';
		s1->services[3] = ' ';
		s1->services[4] = 'l';
		s1->services[5] = 'a';
		s1->services[6] = 'u';
		s1->services[7] = 'n';
		s1->services[8] = 'd';
		s1->services[9] = 'r';
		s1->services[10] = 'y';
		s1->services[11] = '\0';
		serviceRate = 20 + 10;
	}
	else if (gym == 'Y' && laundry == 'N') {
		s1->services[0] = 'g';
		s1->services[1] = 'y';
		s1->services[2] = 'm';
		s1->services[3] = '\0';
		serviceRate = 20;
	}
	else if (gym == 'N' && laundry == 'Y') {
		s1->services[0] = 'l';
		s1->services[1] = 'a';
		s1->services[2] = 'u';
		s1->services[3] = 'n';
		s1->services[4] = 'd';
		s1->services[5] = 'r';
		s1->services[6] = 'y';
		s1->services[7] = '\0';
		serviceRate = 10;
	}
	else {
		serviceRate = 0;
	}
	
	return serviceRate;
}

void displayPayment(int numberOfWeeks, char roomType[], struct student* s1) {
	printf("\nTotal amount to be paid: %lf", calculatePayment(numberOfWeeks, s1));
}

void displayTotalReceivable() {

}

void displayTotalPayments() {

}

void displayReceivable(struct student* s1) {

}

