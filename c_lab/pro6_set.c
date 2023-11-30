#include <stdio.h>
#include <stdlib.h>
typedef struct {
    unsigned int *bits;
    size_t size;
} BitSet;
BitSet *createSet(size_t size) {
    BitSet *set = (BitSet *)malloc(sizeof(BitSet));
    set->size = size;
    set->bits = (unsigned int *)calloc((size + 31) / 32, sizeof(unsigned int));
    return set;
}
void addToSet(BitSet *set, size_t element) {
    if (element >= set->size) {
        printf("Error: Element index out of bounds.\n");
        return;
    }
    set->bits[element / 32] |= (1u << (element % 32));
}
int isInSet(BitSet *set, size_t element) {
    if (element >= set->size) {
        printf("Error: Element index out of bounds.\n");
        return 0;
    }
    return (set->bits[element / 32] & (1u << (element % 32))) != 0;
}

BitSet *unionSets(BitSet *set1, BitSet *set2) {
    if (set1->size != set2->size) {
        printf("Error: Sets must have the same size for union operation.\n");
        return NULL;
    }

    BitSet *result = createSet(set1->size);

    for (size_t i = 0; i < (set1->size + 31) / 32; i++) {
        result->bits[i] = set1->bits[i] | set2->bits[i];
    }

    return result;
}

BitSet *intersectSets(BitSet *set1, BitSet *set2) {
    if (set1->size != set2->size) {
        printf("Error: Sets must have the same size for intersection operation.\n");
        return NULL;
    }

    BitSet *result = createSet(set1->size);

    for (size_t i = 0; i < (set1->size + 31) / 32; i++) {
        result->bits[i] = set1->bits[i] & set2->bits[i];
    }

    return result;
}

BitSet *differenceSets(BitSet *set1, BitSet *set2) {
    if (set1->size != set2->size) {
        printf("Error: Sets must have the same size for difference operation.\n");
        return NULL;
    }

    BitSet *result = createSet(set1->size);

    for (size_t i = 0; i < (set1->size + 31) / 32; i++) {
        result->bits[i] = set1->bits[i] & ~set2->bits[i];
    }

    return result;
}

void displaySet(BitSet *set) {
    printf("{ ");
    for (size_t i = 0; i < set->size; i++) {
        if (isInSet(set, i)) {
            printf("%zu ", i);
        }
    }
    printf("}\n");
}

void freeSet(BitSet *set) {
    free(set->bits);
    free(set);
}
void dilpay_bit(BitSet *set) {

     printf("{ ");
    for (size_t i = 0; i < set->size; i++) {
        if (isInSet(set, i)) {
            printf(" 1 ");
        }
       else{
        printf(" 0 ");
}
    }
    printf("}\n");

}


int main() {
    size_t setSize;

    printf("Enter the size of the sets: ");
    scanf("%zu", &setSize);

    BitSet *setA = createSet(setSize);
    BitSet *setB = createSet(setSize);


    printf("Enter elements for set A (enter -1 to finish):\n");
    size_t elementA;
    while (1) {
        scanf("%zd", &elementA);
        if (elementA == -1) {
            break;
        }
        addToSet(setA, elementA);
    }
    printf("Enter elements for set B (enter -1 to finish):\n");
    size_t elementB;
    while (1) {
        scanf("%zd", &elementB);
        if (elementB == -1) {
            break;
        }
        addToSet(setB, elementB);
    }

    printf("Set A: ");
    displaySet(setA);

    printf("Set B: ");
    displaySet(setB);
   printf("set A :");
 dilpay_bit(setA);
printf("set B :");
 dilpay_bit(setB);

    BitSet *unionSet = unionSets(setA, setB);
    printf("Union of A and B: ");
    displaySet(unionSet);

    BitSet *intersectionSet = intersectSets(setA, setB);
    printf("Intersection of A and B: ");
    displaySet(intersectionSet);

    BitSet *differenceSet = differenceSets(setA, setB);
    printf("Difference of A and B: ");
    displaySet(differenceSet);

    freeSet(setA);
    freeSet(setB);
    freeSet(unionSet);
    freeSet(intersectionSet);
    freeSet(differenceSet);

    return 0;
}
