/*
* Author : Oshini Jayaweera (2757043)
* Date: 02/05/2025
* Description : Setting up "queue" data structure using an array
*/

#include "Lab1_QueueArray_Template_Lib.h"

/*
This function inserts a new student in the waiting line.
If the queue is already full, the function prints a message to the console
that informs the user that no more students can be inserted in the queue.
If the queue is not full, the function asks the user for the first name, the last name, and the matriculation number.
Then, it adds this student as last element to the queue.

Parameters:
   waitingLine -> Array storing the students

Returns: None
*/
void enqueue(sStudent waitingLine[]) {
	int index = countElements(waitingLine);

	//To avoid garbage values or unexpected results
	if (index >= MAXARRAY) {
		printf("Queue is full. Cannot enqueue more students.\n");
		return;
	}

	sStudent newStudent;
	printf("Enter first name: ");
	scanf("%s", newStudent.firstName);

	printf("Enter last name: ");
	scanf("%s", newStudent.lastName);

	printf("Enter matriculation number: ");
	scanf("%d", &newStudent.matNo);

	waitingLine[index] = newStudent;

	printf("Student enqueued successfully!\n\n");

}


/*
This function removes the first student from the waiting line.
If the queue is empty, the function prints a message to the console
that informs the user that the waiting list does not contain any students.
If the queue is not full, the function first prints the full name and matriculation number of the first student of the waiting line to the console.
Second, it removes the student from the queue by moving all students forward one place in the array.

Parameters:
   waitingLine -> Array storing the students

Returns: None
*/
void dequeue(sStudent waitingLine[]) {

	if (isEmpty(waitingLine) == 0) {
		printf("Queue is empty. Cannot dequeue.\n");
		return;
	}

	printf("Dequeued student: %s %s, Matriculation Number: %ld\n",
		waitingLine[0].firstName, waitingLine[0].lastName, waitingLine[0].matNo);

	// Shift all students one position to the left to make sure no gaps
	for (int i = 0; i < countElements(waitingLine) - 1; i++) {
		waitingLine[i] = waitingLine[i + 1];
	}

	// Removing last element
	waitingLine[countElements(waitingLine) - 1].firstName[0] = '\0';
	waitingLine[countElements(waitingLine) - 1].lastName[0] = '\0';
	waitingLine[countElements(waitingLine) - 1].matNo = 0;

}


/*
This function checks if the waiting line is empty.

Parameters:
   waitingLine -> Array storing the students

Returns:
 - If the waiting line is empty, the function returns 0.
 - If there are students in the waiting line, the function returns 1.

*/
int isEmpty(sStudent waitingLine[]) {
	//matNo not being 0 indicated valid entry
	if (waitingLine[0].matNo == 0) {
		return 0;
	}
	return 1;

}


/*
This function counts the number of students in the waiting line and returns this number.

Parameters:
   waitingLine -> Array storing the students

Returns:
 - Number of students in the waiting line.
 - If the waiting line is empty the function returns 0.
*/
int countElements(sStudent waitingLine[]) {
	int counter = 0;
	for (counter = 0; counter < MAXARRAY; counter++) {
		if (waitingLine[counter].matNo == 0)
			break;
	}
	return counter;
}


/*
This function prints the full names and matriculation number of all students in the waiting list to the console.
The printing starts with the first student in the waiting line and prints the other students in the order of insertion.

Parameters:
   waitingLine -> Array storing the students

Returns: None
*/
void printQueue(sStudent waitingLine[]) {
	int numberStudents = countElements(waitingLine);
	for (int i = 0; i < numberStudents; i++) {
		printf("Student %3d:\t%s\t%s\t%ld\n", i + 1, waitingLine[i].firstName, waitingLine[i].lastName, waitingLine[i].matNo);
	}
	return;
}


/* ***** HELPER FUNCTIONS ***** */

/*
* Function reads a positive integer safely from the keyboard.
*
* Parameters: None.
*
* Returns: A positive integer read from the keyboard.
*/
int getInt() {
	int val = 0;
	while (1) {
		if ((scanf("%d", &val) != 1) || (val < 0)) {
			while (getchar() != '\n');
			printf("Not a valid integer.\n");
		}
		else {
			while (getchar() != '\n');
			break;
		}
	}
	return val;
}


/*
* Function reads a string safely from the keyboard.
*
* Parameters: A string in which the string read from the keyboard is stored.
*
* Returns: None
*/
void getString(char string[MAXNAME]) {
	int val = 0;
	while (1) {
		if (scanf("%s", string) != 1) {
			while (getchar() != '\n');
			printf("Not a valid string.\n");
		}
		else {
			while (getchar() != '\n');
			break;
		}
	}
	return;
}