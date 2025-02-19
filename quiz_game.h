#ifndef QUIZ_GAME_H
#define QUIZ_GAME_H

#include <stdio.h>
#include <time.h>

#define MAX_QUESTIONS 5
#define TIME_LIMIT 10  // Time limit for each question in seconds

typedef struct {
    char question[256];
    char options[4][100];
    int correctOption; 
} Question;

void askQuestion(Question *q);
int playQuiz(Question questions[], int numQuestions);
void displayQuizResults(int score, int totalQuestions);
int getAnswer();

#endif
