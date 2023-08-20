#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Product {
    char name[50];
    float rate;
    int quantity;
    float price;
};

struct Customer {
    char name[50];
    char address[100];
};

float calculatePrice(float rate, int quantity) {
    return rate * quantity;
}

void inputProductDetails(struct Product *product) {
    printf("Enter product name: ");
    scanf("%s", product->name);

    printf("Enter product rate: ");
    scanf("%f", &product->rate);

    printf("Enter product quantity: ");
    scanf("%d", &product->quantity);

    product->price = calculatePrice(product->rate, product->quantity);
}

void displayBill(struct Product *products, int numProducts, struct Customer customer) {
    printf("\n\n");
    printf("------------------------------\n");
    printf("        Grocery Bill\n");
    printf("------------------------------\n");
    printf("Customer Name: %s\n", customer.name);
    printf("Customer Address: %s\n", customer.address);
    printf("------------------------------\n");
    printf("Product Name   Rate   Quantity   Price\n");
    printf("------------------------------\n");

    float total = 0.0;

    for (int i = 0; i < numProducts; i++) {
        printf("%-15s %.2f    %d         %.2f\n", products[i].name, products[i].rate, products[i].quantity, products[i].price);
        total += products[i].price;
    }

    printf("------------------------------\n");
    printf("Total: %.2f\n", total);
    printf("------------------------------\n");
}

int main() {
    struct Customer customer;
    struct Product *products = NULL;  
    int numProducts;

    printf("Enter customer name: ");
    scanf("%s", customer.name);

    printf("Enter customer address: ");
    scanf(" %[^\n]s", customer.address);

    printf("Enter the number of products purchased: ");
    scanf("%d", &numProducts);

    products = (struct Product *)malloc(numProducts * sizeof(struct Product));
    if (products == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < numProducts; i++) {
        printf("\nEnter details for product %d:\n", i + 1);
        inputProductDetails(&products[i]);
    }

    displayBill(products, numProducts, customer);

    free(products);

    return 0;
}
