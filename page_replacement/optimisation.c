#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int pointer;
int faults, hits;
int frame_size, i, number_of_references;
int frame[1000], references[1000];
void print()
{
    int i;
    for (int i = 0; i < frame_size; i++)
    {
        if (frame[i] == -1)
        {
            printf("-");
        }
        else
        {
            printf("%d ", frame[i]);
        }
    }
    printf("\n");
}

int predict(int reference_length, int page_no, int start)
{
    int pos = -1, farthest = start, i;
    for (i = 0; i < frame_size; i++)
    {
        int j;
        for (j = start; j < reference_length; j++)
        {
            if (frame[i] == references[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    pos = i;
                }
                }
        }
        if (j == page_no)
        {
            return i;
        }
    }
    if (pos == -1)
    {
        return 0;
    }
    else
    {
        return pos;
    }
}

void add_reference(int reference, int current_position, int reference_length)
{
    int i;
    bool allocated = false;
    for (i = 0; i < frame_size; i++)
    {
        if (frame[i] == reference)
        {
            printf("  hit for %d |", reference);
            hits++;
            allocated = true;
            break;
        }
        else if (frame[i] == -1)
        {
            frame[i] = reference;
            printf("Fault for %d |", reference);
            faults++;
            allocated = true;
            break;
        }
    }
    if (allocated == false)
    {
        int j = predict(reference_length, current_position, current_position + 1);
        frame[j] = reference;
        printf("Fault for %d|", reference);
        faults++;
    }
    print();
}

int main()
{

    printf("Enter frame size: ");
    scanf("%d", &frame_size);
    for (i = 0; i < frame_size; i++)
    {
        frame[i] = -1;
    }

    print(frame_size, frame);

    printf("Enter the number of references: ");
    scanf("%d", &number_of_references);

    for (i = 0; i < number_of_references; i++)
    {
        scanf("%d", &references[i]);
        add_reference(references[i], i, number_of_references);
    }
    printf("\nNumber of faults: %d \nNumber of hits: %d\n", faults, hits);
    return 0;
}
