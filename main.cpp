#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quiz_game.h"

int main() {
    Question questions[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"Paris", "London", "Berlin", "Madrid"}, 0},
        {"Which language is primarily used for web development?", {"Python", "C", "JavaScript", "Java"}, 2},
        {"Who wrote 'Romeo and Juliet'?", {"Shakespeare", "Dickens", "Hemingway", "Austen"}, 0},
        {"What is the largest planet in our solar system?", {"Earth", "Jupiter", "Saturn", "Mars"}, 1},
        {"What is the chemical symbol for water?", {"H2O", "O2", "CO2", "H2"}, 0}
    };

    int playAgain;
    do {
        int score = playQuiz(questions, MAX_QUESTIONS);
        displayQuizResults(score, MAX_QUESTIONS);

        printf("\nDo you want to try again? (1 for Yes, 0 for No): ");
        scanf("%d", &playAgain);
    } while (playAgain == 1);

    printf("Thanks for playing!\n");
    return 0;
}

