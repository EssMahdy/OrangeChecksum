#include <stdio.h>
#include <string.h>

#define MAX_IDS 50
#define MAX_LENGHT 100

// Function to count the occurrences of a character in a string 
int countOccurrences (const char *id, int length, char character) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (id[i] == character) {
            count++;
        }
    }
    return count;
}

// Function that take a 2D character array and caluclate the checksum of the box IDs
int calculateChecksum (const char ids[MAX_IDS][MAX_LENGHT], int IDs) {
    int towsCount = 0;
    int threesCount = 0;

    for (int j = 0; j < IDs; j++) {
        int length = strlen (ids[j]);
        int foundTwo = 0;
        int foundThree = 0;

        for (int k = 0; k < length; k++) {
            int occurences = countOccurrences (ids[j], length, ids[j][k]);
            if (occurences == 2 && foundTwo == 0) {
                towsCount++;
                foundTwo = 1;
            } else if (occurences == 3 && foundThree == 0) {
                threesCount++;
                foundThree = 1;
            }
        }
    }
    
    return towsCount * threesCount;

}

int main() {
    char ids[MAX_IDS][MAX_LENGHT];
    int IDs = 0;

    // Input
    printf("Quickly!! Use your fancy scanner and scan the boxs\n");
    while (IDs < MAX_IDS) {
        if (fgets(ids[IDs], MAX_LENGHT, stdin) == NULL || ids[IDs][0] == '\n') {
            break; // Break reading if line is empty
        }

        ids[IDs][strcspn(ids[IDs], "\n")] = '\0';
        IDs++;
    }
    // Print checksum
    int checksum = calculateChecksum(ids, IDs);
    printf("You're lucky the count is complete, the checksum is: %d\n", checksum);
    printf("Now run!\n");
    return 0;
}