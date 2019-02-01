#ifndef TRAINING_RECORDER_H
#define TRAINING_RECORDER_H

struct trainingRecorder {
  char* trainingName;
  int nRuns;
  float totLength;
  float totTime;
};

struct trainingRecorder *constructTrainingRecorder(char *trainingName);
void destructTrainingRecorder(struct trainingRecorder *this);
void addRun(struct trainingRecorder *this, float length, float time);
float averageSpeed(struct trainingRecorder *this);
char *toString(struct trainingRecorder *this);
int compareAverageSpeeds(struct trainingRecorder *tr1,struct trainingRecorder *tr2);

#endif
