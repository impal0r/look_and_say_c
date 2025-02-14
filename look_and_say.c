#include "stdio.h"
#include "stdlib.h"

// Compute the next term in the Look and Say Sequence
unsigned int step(const char* last, char** next, unsigned int last_length, unsigned int* next_capacity)
{
    unsigned int new_length = 0;
    // From the 11th term onwards, the length always increases by < x1.4
    // We conservatively double the buffer size when the last term is (1/1.4 == 5/7) its size
    // Compared to c++'s std::vector, this avoids checking the capacity each time we append
    //  to the buffer (efficiency!)
    // To make this work, the initial buffer sizes are set at 64, > the length of the 11th term
    if (7 * last_length > 5 * (*next_capacity))
    {
        free(*next);
        *next_capacity *= 2;
        *next = malloc(*next_capacity);
        if (*next == NULL) //check for failed allocation
        {
            return 0;
        }
    }
    //sequences will always be between 1 and 3 numbers long (can be proved mathematically)
    //making this counter a char type means we can easily convert it to a text character, by adding '0'
    char seq_length = 1;
    for (unsigned int i = 0; i < last_length - 1; ++i)
    {
        if (last[i] != last[i+1])
        {
            (*next)[new_length++] = seq_length+'0';
            (*next)[new_length++] = last[i];
            seq_length = 1;
        }
        else
        {
            seq_length++;
        }
    }
    (*next)[new_length++] = seq_length+'0';
    (*next)[new_length++] = last[last_length-1];
    return new_length;
}

int main()
{
    printf("1");
    getchar();

    // start the buffers at 64 digits long
    unsigned int capacity_1 = 64, capacity_2 = 64;
    // the first term is '1', which is 1 digit long. Second buffer remains uninitialized
    unsigned int number_length_1 = 1, number_length_2 = 0;
    char* buffer_1 = malloc(capacity_1);
    char* buffer_2 = malloc(capacity_1);
    if (buffer_1 == NULL || buffer_2 == NULL)
    {
        printf("Error allocating heap memory.\n");
        return 1;
    }
    // the first term is '1'
    buffer_1[0] = '1';

    while (1)
    {
        number_length_2 = step(buffer_1, &buffer_2, number_length_1, &capacity_2);
        if (number_length_2 == 0)
        {
            printf("Out of memory\n");
            free(buffer_1);
            return 1;
        }
        buffer_2[number_length_2] = '\0';
        printf("%s", buffer_2);
        // debug and instrumentation output
        // printf("%u %f", number_length_2, (float)number_length_2 / (float)number_length_1);
        // printf("%u / %u", number_length_2, capacity_2);
        getchar();

        number_length_1 = step(buffer_2, &buffer_1, number_length_2, &capacity_1);
        if (number_length_1 == 0)
        {
            printf("Out of memory\n");
            free(buffer_2);
            return 1;
        }
        buffer_1[number_length_1] = '\0';
        printf("%s", buffer_1);
        // debug and instrumentation output
        // printf("%u %f", number_length_1, (float)number_length_1 / (float)number_length_2);
        // printf("%u / %u", number_length_1, capacity_1);
        getchar();
    }
    return 0; //should be unreachable
}