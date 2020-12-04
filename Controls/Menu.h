#include"Control.h"

void addDish(){
    char name[255];
    int qty, price, flag = 0;
    do{
        flag = 0;
        printf("Insert the name of the dish [Lowercase letters]: ");
        scanf("%[^\n]", name);
        getchar();
        isLowercase(name);
        Dish *temp = searchDish(name);
        if(temp) flag++; //cek apakah dish sudah ada
    }while(flag>0);
    do{
        printf("Insert the price of the dish [1000..50000]: ");
        scanf("%d", &price);
        getchar();
    }while(price<1000||price>50000);
    do{
        printf("Insert the quantity of the dish [1..999]: ");
        scanf("%d", &qty);
        getchar();
    }while(qty<1||qty>999);
    insertDish(createDish(name, price, qty));
    puts("The dish has been added!");
    puts("Press enter to continue...");
    getchar();
}

void removeDish(){
    if(!head){
        puts("There is no dish!");
        puts("Press enter to continue");
        getchar();
        return;
    }
    printDish();
    char name[255];
    printf("Insert dish's name to be deleted: ");
    scanf("%[^\n]", name);
    getchar();
    if(!searchDish(name)){
        puts("Dish not found!");
        puts("Press enter to continue");
        getchar();
        return;
    }
    popDish(name);
    puts("The dish has been removed!");
    puts("Press enter to continue");
    getchar();
}

void addCustomer(){
    char name[255];
    int flag = 0;
    do{
        flag = 0;
        printf("Insert customer's name [Without space]: ");
        scanf("%[^\n]", name);
        getchar();
        flag = isAlphabet(name);
    }while(flag>0);
    insertCustomer(createCustomer(name));
    puts("Customer has been added!");
    puts("Press enter to continue");
    getchar();
}

void searchCustomer(){
    char name[255];
    int flag = 0;
    do{
        flag = 0;
        printf("Insert the customer's name to be searched: ");
        scanf("%[^\n]", name);
        getchar();
        flag = isAlphabet(name);
    }while(flag > 0);
    if(search(name)) printf("%s is present\n", name);
    else printf("%s is not present\n", name);
    puts("Press enter to continue");
    getchar();
}

void order(){
    char name[255];
    int flag = 0;
    Customer *cust;
    do{
        flag = 0;
        printf("Insert the customer's name: ");
        scanf("%[^\n]", name);
        getchar();
        cust = search(name);
        if(!cust) flag++;
    }while(flag>0);
    int num;
    do{
        printf("Insert the ammount of dish: ");
        scanf("%d", &num);
        getchar();
    }while(num < 1);
    for(int i = 1; i<=num; i++){
        int qty;
        char ordered[255];
        Dish *temp;
        do{
            char dish[255], input[255];
            flag = 0;
            printf("[%d] Insert the dish's name and quantity: ", i);
            scanf("%[^\n]", input);
            getchar();
            qty = convertInput(dish, input);
            temp = searchDish(dish);
            if(!temp){ //jika makanan tidak ada di menu
                puts("Dish not found!");
                flag++;
            }
            else{
                if(temp->qty < qty || qty < 1) flag++; //jika jumlah pesanan melebihi stock
                else{
                    temp->qty = temp->qty - qty;
                    strcpy(ordered, dish);
                    if(temp->qty==0) popDish(dish); //jika stock makanan habis maka diremove
                }
            }
        }while(flag>0);
        insertOrder(cust, createOrder(ordered, temp->price, qty));
    }
    puts("Order success!");
    puts("Press enter to continue");
    getchar();
}

void payment(){
    int index;
    printf("Input the customer's index: ");
    scanf("%d", &index);
    getchar();
    if(!chead[index]){
        puts("Customer not found");
        puts("Press enter to continue");
        getchar();
        return;
    }
    if(!chead[index]->ohead){
        puts("Customer hasn't ordered yet");
        puts("Press enter to continue");
        getchar();
        return;
    }
    printOrder(chead[index]);
    popCustomer(index); //delete customer setelah payment
}