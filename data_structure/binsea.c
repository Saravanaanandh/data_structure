#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;      // Coefficient
    int exp;       // Exponent
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coef, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the polynomial linked list
void insertNode(Node** poly, int coef, int exp) {
    Node* newNode = createNode(coef, exp);
    if (!*poly || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        Node* current = *poly;
        while (current->next && current->next->exp > exp) {
            current = current->next;
        }
        if (current->exp == exp) {
            current->coef += coef; // Combine coefficients if exponent matches
            free(newNode);
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

// Function to multiply two polynomials
Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    for (Node* p1 = poly1; p1; p1 = p1->next) {
        for (Node* p2 = poly2; p2; p2 = p2->next) {
            int coef = p1->coef * p2->coef;
            int exp = p1->exp + p2->exp;
            insertNode(&result, coef, exp);
        }
    }
    return result;
}

// Function to print the polynomial
void printPolynomial(Node* poly) {
    if (!poly) {
        printf("0\n");
        return;
    }
    Node* current = poly;
    while (current) {
        printf("%d x^%d", current->coef, current->exp);
        if (current->next) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

// Main function to demonstrate the multiplication
int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    // Creating first polynomial: 3x^2 + 5x + 2
    insertNode(&poly1, 3, 2);
    insertNode(&poly1, 5, 1);
    insertNode(&poly1, 2, 0);

    // Creating second polynomial: 4x^1 + 1
    insertNode(&poly2, 4, 1);
    insertNode(&poly2, 1, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    Node* result = multiplyPolynomials(poly1, poly2);

    printf("Result of multiplication: ");
    printPolynomial(result);

    // Free allocated memory (not shown here, but recommended)

    return 0;
}

