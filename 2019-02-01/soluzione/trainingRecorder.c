#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trainingRecorder.h"

struct trainingRecorder *constructTrainingRecorder(char *trainingName) {
  struct trainingRecorder *this = malloc(sizeof(struct trainingRecorder));

  this->trainingName = trainingName;
  this->nRuns = 0; 
  this->totLength = 0;
  this->totTime = 0;

  return this;
}

void destructTrainingRecorder(struct trainingRecorder *this) {
  free(this);
}

void addRun(struct trainingRecorder *this, float length, float time) {
  this->nRuns++; 
  this->totLength += length;
  this->totTime += time;
}

float averageSpeed(struct trainingRecorder *this) {
  if (this->nRuns == 0)
    return 0.0f;
  else
    return (this->totLength / this->totTime)*60; // Km/min*60 -> Km/h
}

char *toString(struct trainingRecorder *this) {
  char *res = malloc(strlen(this->trainingName) + 100);
  *res = '\0';

  sprintf(res, "Training name: %s; average speed: %6.2f Km/h; number of runs: %d", this->trainingName, averageSpeed(this), this->nRuns);

  return res;
}

int compareAverageSpeeds(struct trainingRecorder *tr1, struct trainingRecorder *tr2) {
  if (averageSpeed(tr1) < averageSpeed(tr2))
    return -1;
  else
    if (averageSpeed(tr1) > averageSpeed(tr2))    
      return 1;
    else
      return 0;
}
