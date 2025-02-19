#include "quiz_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void askQuestion(Question* q) {
    printf("\n%s\n", q->question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q->options[i]);
    }
}

int getAnswer() {
    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    return answer - 1; 
}

int playQuiz(Question questions[], int numQuestions) {
    int score = 0;

    for (int i = 0; i < numQuestions; i++) {
        askQuestion(&questions[i]);

        // Set the start time for the question
        time_t start_time = time(NULL);

        int userAnswer = -1;
        while (difftime(time(NULL), start_time) < TIME_LIMIT) {
            if (userAnswer == -1) {
                userAnswer = getAnswer();
            }
            if (userAnswer >= 0 && userAnswer < 4) {
                break; 
              
            }
            printf("Invalid input. Please enter a number between 1 and 4.\n");
        }

        // If time limit exceeded, give the correct answer automatically
        if (userAnswer == -1) {
            printf("Time's up! The correct answer was option %d.\n", questions[i].correctOption + 1);
        } else {
            if (userAnswer == questions[i].correctOption) {
                score++;
            }
        }
    }

    return score;
}

void displayQuizResults(int score, int totalQuestions) {
    printf("\nQuiz Completed!\n");
    printf("Your score: %d/%d\n", score, totalQuestions);
}
