#ifndef PASCALS_TRIANGLE_USERINPUT_H
#define PASCALS_TRIANGLE_USERINPUT_H
#ifdef __cplusplus
extern "C" {
#endif
    namespace userInput {
    #define MAX_LINE 100

        enum _bool {
            false = 0,
            true = 1
        };

        enum _inputType {
            number = 0,
            letter = 1
        };

        typedef enum _bool Bool;
        typedef enum _inputType inputType;
        char *readUserInput(inputType type)
        {
            static char s[MAX_LINE];
            Bool valid = false;
            while (!valid) {
                fgets(s, sizeof(s), stdin);
                int len = strlen(s);
                while (len > 0 && isspace(s[len - 1]))
                    --len;
                if (len > 0) {
                    valid = true;
                    for (int i = 0; i < len; ++i) {
                        if (type == number) {
                            if (!isdigit(s[i])) {
                                valid = false;
                                break;
                            }
                        } else if (type == letter) {
                            if (isdigit(s[i])) {
                                valid = false;
                                break;
                            }
                        }
                    }
                }
                if (!valid && type == number)
                    printf("Enter an positive integer: ");
                else if (!valid && type == letter)
                    printf("Enter a character: ");
            }
            return s;
        }

        int convertUserInput(char *s)
        {
            int num;
            sscanf(s, "%d", &num);
            return num;
        }

        Bool userMenu(void)
        {
            Bool validInput = false;
            while (!validInput) {
                printf("Enter 'f' to calculate another factorial.\nEnter 'q' to quit.\n");
                inputType text = letter;
                char *input = readUserInput(text);
                if (input[0] == 'f' && input[1] == '\n') {
                    validInput = true;
                    return true;
                } else if (input[0] == 'q' && input[1] == '\n') {
                    validInput = true;
                    return false;
                } else {
                    printf("Invalid input.\n");
                }
            }
        }
    }
#ifdef __cplusplus
}
#endif
#endif //PASCALS_TRIANGLE_USERINPUT_H
