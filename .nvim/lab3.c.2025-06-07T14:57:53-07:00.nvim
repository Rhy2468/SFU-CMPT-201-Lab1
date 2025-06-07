#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Variables
  // Buffer to store input lines in an array
  char *chat[5] = {0};
  // Variables to track current and also length
  int current = 0;
  size_t len = 0;
  // Temp pointer to store reach line
  char *temp = NULL;

  // Loop
  while (1) {
    printf("Enter input: ");
    // Read line
    ssize_t read = getline(&temp, &len, stdin);

    temp[read - 1] = '\0';

    // Assign it to the array
    free(chat[current]);
    // strdup copies the line into new memory to ensure overwriting does not
    // happen
    chat[current] = strdup(temp);
    // move to next position in array/wrap around if needed
    current = (current + 1) % 5;

    // if print is entered print the last 5 lines
    if (strcmp(temp, "print") == 0) {
      for (int i = 0; i < 5; ++i) {

        int currentIndex = (current + i) % 5;

        if (chat[currentIndex]) {
          printf("%s\n", chat[currentIndex]);
        }
      }
    }
  }

  // Free all memory
  for (int i = 0; i < 5; i++) {
    free(chat[i]);
  }
  free(temp);

  return 0;
}
