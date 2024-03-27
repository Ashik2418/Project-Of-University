#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char question[200];
    char options[4][100];
    int answer;
} Question;

void saveQuestions(Question questions[], int numQuestions, const char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < numQuestions; i++) {
        fprintf(file, "Question: %s\n", questions[i].question);
        fprintf(file, "Answer: %s\n\n", questions[i].options[questions[i].answer - 1]);
    }

    fclose(file);
    printf("Questions saved to '%s' successfully.\n", fileName);
}

int main() {
    Question easyQuestions[5] = {
        {
            "What is the size of 'int' data type in bytes?",
            {"2", "4", "8", "Depends on the system"},
            2
        },
        {
            "Which operator is used to access the value at the address stored in a pointer variable?",
            {"*", "&", "/", "->"},
            1
        },
        {
            "What is the output of the following code?\n\n#include <stdio.h>\n\nint main() {\n    int x = 10;\n    printf(\"%d\", ++x);\n    return 0;\n}",
            {"10", "11", "12", "Compiler Error"},
            2
        },
        {
            "Which keyword is used to declare a function that does not return any value?",
            {"int", "void", "float", "none of the above"},
            2
        },
        {
            "Which of the following is an invalid identifier in C?",
            {"my_variable", "123abc", "_value", "variable2"},
            2
        }
    };

    Question mediumQuestions[5] = {
        {
            "What is the output of the following code?\n\n#include <stdio.h>\n\nint main() {\n    char str[] = \"Hello World\";\n    printf(\"%c\", str[11]);\n    return 0;\n}",
            {"H", "d", "l", "Compiler Error"},
            4
        },
        {
            "Which keyword is used to dynamically allocate memory in C?",
            {"new", "malloc", "alloc", "dynamic"},
            2
        },
        {
            "What is the result of the expression 'sizeof(char)'?",
            {"1", "2", "4", "Depends on the system"},
            1
        },
        {
            "What is the scope of a local variable in C?",
            {"Global", "Local to the function", "Local to the block", "Local to the file"},
            3
        },
        {
            "What is the output of the following code?\n\n#include <stdio.h>\n\nint main() {\n    int x = 10;\n    int y = (x > 5) ? 1 : 0;\n    printf(\"%d\", y);\n    return 0;\n}",
            {"10", "1", "0", "Compiler Error"},
            2
        }
    };

    Question hardQuestions[10] = {
        {
            "What is the output of the following code?\n\n#include <stdio.h>\n\nint main() {\n    char *str = \"Hello World\";\n    printf(\"%c\", *str++);\n    return 0;\n}",
            {"H", "e", "o", "Compiler Error"},
            1
        },
        {
            "Which of the following statements is true regarding the 'const' qualifier in C?",
            {"It can be used to declare read-only variables", "It can be used to declare write-only variables", "It can be used to declare constants of any data type", "It cannot be used with pointers"},
            1
        },
        {
            "What is the output of the following code?\n\n#include <stdio.h>\n\nint main() {\n    char str[] = \"Hello World\";\n    printf(\"%c\", *(str+6));\n    return 0;\n}",
            {"H", "W", "o", "Compiler Error"},
            3
        },
        {
            "Which of the following is not a valid pointer arithmetic operation in C?",
            {"Adding two pointers", "Subtracting two pointers", "Multiplying a pointer by a scalar value", "Dividing a pointer by a scalar value"},
            4
        },
        {
            "What is the scope of a variable declared as 'extern'?",
            {"Global scope", "Local scope", "Block scope", "Function scope"},
            1
        },
        {
            "What is the output of the following code?\n\n#include <stdio.h>\n\nint main() {\n    int x = 5;\n    printf(\"%d\", x++ * ++x);\n    return 0;\n}",
            {"25", "36", "42", "Compiler Error"},
            4
        },
        {
            "Which of the following is not a valid type of function parameter passing in C?",
            {"Pass by value", "Pass by reference", "Pass by pointer", "Pass by array"},
            4
        },
        {
            "What is the output of the following code?\n\n#include <stdio.h>\n\nint main() {\n    int x = 5;\n    int y = ++x + ++x;\n    printf(\"%d\", y);\n    return 0;\n}",
            {"10", "11", "12", "Compiler Error"},
            3
        },
        {
            "What is the purpose of the 'volatile' qualifier in C?",
            {"To declare variables that can be modified by multiple threads", "To declare variables that can be modified by an interrupt service routine", "To declare variables that are stored in cache memory", "To declare variables that are passed as function arguments"},
            2
        },
        {
            "What is the output of the following code?\n\n#include <stdio.h>\n\nint main() {\n    int x = 10;\n    printf(\"%d\", x++ * x++);\n    return 0;\n}",
            {"90", "110", "121", "Compiler Error"},
            3
        }
    };

    int numEasyQuestions = sizeof(easyQuestions) / sizeof(easyQuestions[0]);
    int numMediumQuestions = sizeof(mediumQuestions) / sizeof(mediumQuestions[0]);
    int numHardQuestions = sizeof(hardQuestions) / sizeof(hardQuestions[0]);

    int numQuestions;
    Question *questions;

    printf("\n--- Welcome to the Quiz Game ---\n\n");

    int difficulty;
    printf("Select difficulty level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("Enter your choice: ");
    scanf("%d", &difficulty);

    switch (difficulty) {
        case 1:
            numQuestions = numEasyQuestions;
            questions = easyQuestions;
            break;
        case 2:
            numQuestions = numMediumQuestions;
            questions = mediumQuestions;
            break;
        case 3:
            numQuestions = numHardQuestions;
            questions = hardQuestions;
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    printf("\n--- Quiz Start ---\n\n");
    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        printf("Question %d:\n", i + 1);
        printf("%s\n", questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }

        int userAnswer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &userAnswer);

         if (userAnswer == questions[i].answer) {
            score++;
            printf("Correct answer!\n");
        } else {
            printf("Wrong answer! The correct answer is: %s\n", questions[i].options[questions[i].answer - 1]);
        }

        printf("\n");
    }

    printf("--- Quiz End ---\n");
    printf("Your score: %d/%d\n", score, numQuestions);

    char fileName[100];
    printf("Enter the file name to save the questions and answers: ");
    scanf("%s", fileName);

    saveQuestions(questions, numQuestions, fileName);

    return 0;
}


