/*
* Author : Oshini Jayaweera (2757043)
* Date: 02/05/2025
* Description : Setting up "queue" data structure using a singly linked list
*/

#include "Lab1_QueueList_Template_Lib.h"

/*
This function inserts a new student in the waiting line.
If the queue is already full, the function prints a message on the console
that informs the user that no more students can be inserted in the queue.
If the queue is not full, the function asks the user for the first name, the last name, and the matriculation number.
Then, it adds this student as the last element to the queue.

Parameters:
   head -> pointer to the first student of the waiting line

Returns:
   The functions returns the first student of the waiting line.
*/

sElement* enqueue(sElement* head) {

	sStudent *newStudent;
	newStudent = (sStudent*)malloc(sizeof(sStudent));
	if (newStudent == NULL) {
		printf("No memory\n");
		exit(1);
	}

	printf("Enter first name: ");
	scanf("%s", newStudent->firstName);

	printf("Enter last name: ");
	scanf("%s", newStudent->lastName);

	printf("Enter matriculation number: ");
	scanf("%d", &(newStudent->matNo));

	sElement* newElement;
	newElement = (sElement*)malloc(sizeof(sElement));
	if (newElement == NULL) {
		printf("No memory\n");
		exit(1);
	}

	newElement->student = *newStudent;
	newElement->next = NULL;

	free(newStudent);

	if (head == NULL) {
		// Queue is empty — this becomes the first element
		return newElement;
	}
	else {
		// Traverse to the end and append
		sElement* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newElement;
		return head;
	}
}


/*
This function removes the first student from the waiting line.
If the queue is empty, the function prints a message to the console
that informs the user that the waiting list does not contain any students.
If the queue is not full, the function prints the full name and matriculation number of the first student of the waiting line to the console.
Second, it removes the student from the queue and frees the memory.

Parameters:
   head -> pointer to the first student of the waiting line

Returns:
   The functions returns the first student of the waiting line.
*/

sElement* dequeue(sElement* head) {
	if (isEmpty(head)) {
		printf("Queue is empty. Nothing to dequeue.\n\n");
		return NULL;
	}

	// Save pointer to the first node (to be removed)
	sElement* temp = head;

	// Print the student being removed
	printf("Dequeued student: %s %s, Matriculation Number: %lu\n\n",
		temp->student.firstName, temp->student.lastName, temp->student.matNo);

	// Move head to the next node
	head = head->next;

	// Free the removed node
	free(temp);

	return head;
}


/*
This function checks if the waiting line is empty.

Parameters:
   head -> pointer to the first student of the waiting line

Returns:
 - If the waiting line is empty, the function returns 0.
 - If there are students in the waiting line, the function returns 1.

*/
int isEmpty(sElement* head) {
	return (head == NULL); 
}


/*
This function counts the number of students in the waiting line and returns this number.

Parameters:
   head -> pointer to the first student of the waiting line

Returns:
 - Number of students in the waiting line.
 - If the waiting line is empty the function returns 0.
*/
int countElements(sElement* head) {
	int counter = 0;
	sElement* temp = head;
	while (temp != NULL) {
		counter++;
		temp = temp->next;
	}
	return counter;
}


/*
This function prints the full names and matriculation number of all students in the waiting line to the console.
The printing starts with the first student in the waiting line and prints the other students in the order of insertion.

Parameters:
   head -> pointer to the first student of the waiting line

Returns: None
*/
void printQueue(sElement* head) {
	if (head == NULL) {
		printf("Queue is empty.\n\n");
		return;
	}

	int numberStudent = countElements(head);
	sElement* temp = head;
	for (int i = 0; i < numberStudent; i++) {
		printf("Student %3d:\t%s\t%s\t%d\n", i + 1, temp->student.firstName, temp->student.lastName, temp->student.matNo);
		temp = temp->next;
	}
	printf("\n");
	return;
}


/* ***** HELPER FUNCTIONS ***** */

/*
* Function reads a positive integer safely from the keyboard.
*
* Parameters: None.
*
* Returns: A positive integer read from the keyboard.*/

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
 Function reads a string safely from the keyboard.

 Parameters: A string in which the string read from the keyboard is stored.

 Returns: None*/

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