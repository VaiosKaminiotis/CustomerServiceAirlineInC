//basic CLI program for airline's customer service


#include <stdio.h>
#include <string.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

//a counter to help with user insert
int userCounter = 0;

struct passenger {
	char name[32];
	char lastName[32];
	struct address {
		char street[32];
		int streetNum;
		char city[32];
		int postalCode;
	}addr;
	
	char username[35];
	char password[128];


}psngr[20];
//^ at most 20 registrations

// function declarations

int signup_user();
int userOptions();

int main() {
	// variables
	char usertype[5];
	int state = 1;

	//start user prompt
	//welcome screen
	//! pick a decent name
	printf("Welcome to placeholder Airlines\n");

	//pick user or admin



	//loop that controls user input
	while(state == 1){

		printf("Please enter \"user\" if you are a client or \"admin\" if you are a system admin.\n");
		scanf("%s", usertype);

		if(strcmp(usertype, "user") == 0) {
			//we got a client
			state = userOptions();
		} 
		else if(strcmp(usertype, "admin") == 0) {
			//we got an admin
			state = 0;
		}
		else {
			printf("Please enter a correct option!\n");
		}
	}

	return 0;
}

// function definitions
//
int signup_user(){
	// ask name
	printf("Enter you name.\n> ");
	scanf("%s",psngr[userCounter].name);

	//ask last name
	printf("Enter your Last name.\n> ");
	scanf("%s",psngr[userCounter].lastName);

	//aks street
	printf("Enter your street.\n> ");
	scanf("%s",psngr[userCounter].street);

	//ask strret number
	printf("Enter your street number.\n> ");
	scanf("%d",&psngr[userCounter].streetNum);

	//ask city
	printf("Enter your city.\n> ");
	scanf("%s",psngr[userCounter].city);

	//ask postal code
	printf("Enter your postal code.\n> ");
	scanf("%s",psngr[userCounter].postalCode);

	//ask password
	printf("Enter a password.");
	scanf("%s",psngr[userCounter].password);


	//create username
	char pad[] = "456";
	char lowerLastName = tolower(psngr[userCounter].lastName);
	strcat(lowerLastName, pad);
	
	psngr[userCounter].username = lowerLastName;

	userCounter++;

	return 1;

}




int userOptions(){
	//variables
	int userChoice;
	int state = 1;


	while(state == 1){
	//clear the previous
		system("cls");
		printf("Welcome user!\nPick one of the options bellow by selecting their number\n\n");
		printf("1. Register\n");
		printf("2. Login\n");
		printf("3. Logout\n");
	
		scanf("%d", &userChoice);
		//run the following functions based on user option
		//make loop that controls user option
		if(userChoice == 1){
			//register

			//-r printf("RUN REGISTER FUNCTION TEST!\n");
			//

			state = signup_user();
			return 1;
		}
		else if(userChoice == 2) {
			//user Login

			printf("RUN LOGIN FUNCTION TEST\n");
			
			return 1;
		}
		else if(userChoice == 3) {
			return 0;
		}
		else {
		
			printf("Please enter a correct option!\n");
		}

	}
}






