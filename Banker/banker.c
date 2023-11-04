#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>

#define NUMBER_OF_CUSTOMERS 5
#define NUMBER_OF_RESOURCES 4

/* the available amount of each resource */
int available[NUMBER_OF_RESOURCES];

/*the maximum demand of each customer */
int maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

/* the amount currently allocated to each customer */
int allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

/* the remaining need of each customer */
int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

// Funtion prototypes
int request_resources(int customer_num, int request[]); 
void release_resources(int customer_num, int release[]);

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void print_matrix(int matrix[][NUMBER_OF_RESOURCES], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        print_array(matrix[i], columns);
    }
}

// Implementation
int request_resources(int customer_num, int request[]) {
    // Check if request is valid
    for (int resource = 0; resource < NUMBER_OF_RESOURCES; resource++) {
        if (request[resource] > need[customer_num][resource]) {
            printf("Request is greater than need\n");
            return -1;
        }

        if (request[resource] > available[resource]) {
            printf("Request is greater than available\n");
            return -1;
        }
    }

    // Try to allocate resources
    for (int resource = 0; resource < NUMBER_OF_RESOURCES; resource++) {
        available[resource] -= request[resource];
        allocation[customer_num][resource] += request[resource];
        need[customer_num][resource] -= request[resource];
    }

    // Check if state is safe
    int work[NUMBER_OF_RESOURCES];
    int finish[NUMBER_OF_CUSTOMERS];

    // Initialize work
    for (int resource = 0; resource < NUMBER_OF_RESOURCES; resource++) {
        work[resource] = available[resource];
    }

    // Initialize finish
    memset(finish, 0, sizeof(finish));

    // Find a customer that can be finished
    int customer = 0;
    int found = 0;
    while (found == 0) {
        // Check if customer can be finished
        int can_be_finished = 1;
        for (int resource = 0; resource < NUMBER_OF_RESOURCES; resource++) {
            if (need[customer][resource] > work[resource]) {
                can_be_finished = 0;
                break;
            }
        }

        if (can_be_finished == 1 && finish[customer] == 0) {
            found = 1;
            finish[customer] = 1;

            // Add allocated resources to work
            for (int resource = 0; resource < NUMBER_OF_RESOURCES; resource++) {
                work[resource] += allocation[customer][resource];
            }
        }

        customer = (customer + 1) % NUMBER_OF_CUSTOMERS;
    }

    // Check if all customers can be finished
    bool all_finished = true;
    for (int customer = 0; customer < NUMBER_OF_CUSTOMERS; customer++) {
        if (finish[customer] == 0) {
            all_finished = 0;
            break;
        }
    }

    if (!all_finished) {
        // Restore resources
        for (int resource = 0; resource < NUMBER_OF_RESOURCES; resource++) {
            available[resource] += request[resource];
            allocation[customer_num][resource] -= request[resource];
            need[customer_num][resource] += request[resource];
        }

        printf("State is unsafe\n");
        return -1;
    }

    printf("State is safe\n");
    return 0;
}

void release_resources(int customer_num, int release[]) {
    // Check if release is valid
    for (int resource = 0; resource < NUMBER_OF_RESOURCES; resource++) {
        if (release[resource] > allocation[customer_num][resource]) {
            printf("Release is greater than allocation\n");
            return;
        }
    }

    // Release resources
    for (int resource = 0; resource < NUMBER_OF_RESOURCES; resource++) {
        available[resource] += release[resource];
        allocation[customer_num][resource] -= release[resource];
        need[customer_num][resource] += release[resource];
    }

    printf("Resources released\n");

    return;
}

int main() {

    char max_request_file_path[100];
    scanf("%s", max_request_file_path);

    FILE *max_request_file = fopen(max_request_file_path, "r");
    
    /**
     * Get maximum demand of each customer
     * Each line in the file represents a customer
     * Each number in a line represents the maximum demand of a resource seperated by a comma
    */
    for (int customer = 0; customer < NUMBER_OF_CUSTOMERS; customer++) {
       for (int resource = 0; resource < NUMBER_OF_RESOURCES; resource++) {
           fscanf(max_request_file, "%d,", &maximum[customer][resource]);
       }
    }

    fclose(max_request_file);

    // print_matrix(maximum, NUMBER_OF_CUSTOMERS, NUMBER_OF_RESOURCES);

    // Get Resources capacity
    for(int resource = 0; resource < NUMBER_OF_RESOURCES; resource++) {
        scanf("%d", &available[resource]);
    }

    /**
     * Calulate need
     * Need = Maximum - Allocation
    */
    for (int customer = 0; customer < NUMBER_OF_CUSTOMERS; customer++) {
        for (int resource = 0; resource < NUMBER_OF_RESOURCES; resource++) {
            need[customer][resource] = maximum[customer][resource] - allocation[customer][resource];
        }
    }

    /**
     * Command input
     * RQ - Request resources
     * RL - Release resources
     * * - Print current state
    */

    char command[2];
    int customer_num;
    int request[NUMBER_OF_RESOURCES];
    int release[NUMBER_OF_RESOURCES];

    while(1) {
        scanf("%s", command);

        if (command[0] == '*') {
            printf("Available:\n");
            print_array(available, NUMBER_OF_RESOURCES);

            printf("Maximum:\n");
            print_matrix(maximum, NUMBER_OF_CUSTOMERS, NUMBER_OF_RESOURCES);

            printf("Allocation:\n");
            print_matrix(allocation, NUMBER_OF_CUSTOMERS, NUMBER_OF_RESOURCES);

            printf("Need:\n");
            print_matrix(need, NUMBER_OF_CUSTOMERS, NUMBER_OF_RESOURCES);
        } else if (command[0] == 'R' && command[1] == 'Q') {
            scanf("%d", &customer_num);
            for (int resource = 0; resource < NUMBER_OF_RESOURCES; resource++) {
                scanf("%d", &request[resource]);
            }

            printf("Requesting resources\n");
            request_resources(customer_num, request);
        } else if (command[0] == 'R' && command[1] == 'L') {
            scanf("%d", &customer_num);
            for (int resource = 0; resource < NUMBER_OF_RESOURCES; resource++) {
                scanf("%d", &release[resource]);
            }

            printf("Releasing resources\n");
            release_resources(customer_num, release);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}