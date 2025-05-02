/*
* Author : Oshini Jayaweera (2757043)
* Date: 02/05/2025
* Description : Setting up "queue" data structure using a singly linked list
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lab1_QueueList_Template_Lib.h"


int main() {
	sElement* head = NULL;

	int choice = 0;
	int number = 0;

	printf("Welcome to our queue program!\n\n");

	while (1) {
		printf("What would you like to do next?\n");
		printf("\t1: Enqueue new student\n");
		printf("\t2: Dequeue student\n");
		printf("\t3: Count students in the waiting list\n");
		printf("\t4: Print waiting list\n");
		printf("Press any other key to exit this program.\n");

		choice = getInt();

		switch (choice) {
		case 1:
			head = enqueue(head);
			break;
		case 2:
			head = dequeue(head);
			break;
		case 3:
			number = countElements(head);
			printf("The queue has %d elements.\n\n", number);
			break;
		case 4:
			printQueue(head);
			break;
		default:
			return 0;
		}
	}
	return 0;
}


