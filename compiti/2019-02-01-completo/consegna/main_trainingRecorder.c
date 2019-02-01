#include <stdio.h>
#include <stdlib.h>
#include "trainingRecorder.h"

int main(void) {
	struct trainingRecorder *tr1 = constructTrainingRecorder("New York Marathon");
	struct trainingRecorder *tr2 = constructTrainingRecorder("Rome Marathon");
	char *s;

	addRun(tr1, 10, 51);
	addRun(tr1, 15, 79);
	addRun(tr1, 20, 120);

	addRun(tr2, 8, 40);
	addRun(tr2, 35, 180);
	addRun(tr2, 20, 115);
	addRun(tr2, 40, 195);


	printf("%s\n", s = toString(tr1));
	free(s);
	printf("%s\n", s = toString(tr2));
	free(s);
	printf("Comparison:  %d\n", compareAverageSpeeds(tr1, tr2));

	destructTrainingRecorder(tr1); destructTrainingRecorder(tr2);
	return 0;
}

// gcc main_trainingRecorder.c trainingRecorder.c -o trainingRecorder
// ./trainingRecorder

