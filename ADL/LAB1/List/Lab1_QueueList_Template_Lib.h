#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 25

typedef struct sStudent {
	char firstName[MAXNAME];
	char lastName[MAXNAME];
	unsigned long matNo;
} sStudent;

typedef struct sElement {
	sStudent student;
	struct sElement* next;
} sElement;

int countElements(sElement* head);
sElement* enqueue(sElement* head);
sElement* dequeue(sElement* head);
int isEmpty(sElement* head);
void printQueue(sElement* head);

/* ***** HELPER FUNCTIONS ***** */
int getInt();
void getString(char string[MAXNAME]);
