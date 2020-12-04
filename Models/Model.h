#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Dish{
    char name[255];
    int price, qty;
    Dish *next, *prev;
}*head, *tail;

Dish *createDish(char *name, int price, int qty){
    Dish *temp = (Dish*)malloc(sizeof(Dish));
    strcpy(temp->name, name);
    temp->price = price;
    temp->qty = qty;
    temp->next = temp->prev = NULL;
    return temp;
}

struct Order{
    char name[255];
    int qty, price;
    Order *next, *prev;
};

Order *createOrder(char *name, int price, int qty){
    Order *temp = (Order*)malloc(sizeof(Order));
    strcpy(temp->name, name);
    temp->price = price*qty;
    temp->qty = qty;
    return temp;
}

struct Customer{
    char name[255];
    Order *ohead, *otail;
    Customer *next;
}*chead[26], *ctail[26];

Customer *createCustomer(char *name) {
  Customer *temp = (Customer*)malloc(sizeof(Customer));
  strcpy(temp->name, name);
  temp->ohead = temp->otail = NULL;
  temp->next = NULL;
  return temp;
}