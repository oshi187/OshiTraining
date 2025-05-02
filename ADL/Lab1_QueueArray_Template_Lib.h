#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 25
#define MAXARRAY 50

typedef struct sStudent {
	char firstName[MAXNAME];
	char lastName[MAXNAME];
	unsigned long matNo;
} sStudent;

void enqueue(sStudent waitingLine[]);
void dequeue(sStudent waitingLine[]);
int isEmpty(sStudent waitingLine[]);
int countElements(sStudent waitingLine[]);
void printQueue(sStudent waitingLine[]);

/* ***** HELPER FUNCTIONS ***** */
int getInt();
void getString(char string[MAXNAME]);
