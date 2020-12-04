#include"../Models/Model.h"

void insertDish(Dish *temp){
    if(!head){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

void popDish(char *name){
    if(head==tail && strcmp(head->name, name)==0){
        head = tail = NULL;
        free(head);
    }
    else if(strcmp(head->name, name)==0){
        Dish *temp = head->next;
        head->next = NULL;
        free(head);
        head = temp;
    }
    else if(strcmp(tail->name, name)==0){
        Dish *temp = tail->prev;
        tail->prev = NULL;
        free(tail);
        tail = temp;
    }
    else{
        Dish *curr = head;
        while(curr && strcmp(curr->name, name)!=0){
            curr = curr->next;
        }
        if(curr==NULL){
            return;
        }
        else{
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
            curr = NULL;
            free(curr);
        }
    }
}

void printDish(){ //print menu
    puts("Bude's Menu");
    puts("=============================================");
    puts("No.   Name                Quantity    Price");
    Dish *curr = head;
    int i = 1;
    while(curr){
        printf("%-3d   %-19s %-8d    %-5d\n", i, curr->name, curr->qty, curr->price);
        i++;
        curr = curr->next;
    }
    puts("=============================================");
}

Dish *searchDish(char *name){ //validasi dish sudah ada atau belum
    Dish *curr = head;
    while(curr && strcmp(curr->name, name)!=0){
        curr = curr->next;
    }
    return curr;
}

int convertInput(char *dish, char *input){ //untuk mendapat nama makanan dan jumlah dari format input
    int j, qty = 0, kali = 1;
    for(j = 0; input[j+1]!='x'; j++){
        dish[j] = input[j];
    }
    dish[j] = '\0';
    for(j = strlen(input)-1; input[j]!='x'; j--){
        qty = qty + (input[j]-'0')*kali;
        kali*=10;
    }
    return qty;
}

unsigned long DJB2(char *str) {
  unsigned long hash = 5381;
  int c;
  while ((c = *str++))
    hash = ((hash << 5) + hash) + c;
  return hash % 26;
}

void insertCustomer(Customer *temp){ //untuk insert customer
    int index = DJB2(temp->name);
    if(!chead[index]){
        chead[index] = ctail[index] = temp;
    }
    else{
        ctail[index]->next = temp;
        ctail[index] = temp;
    }
}

void printCustomer(){ //untuk print seluruh customer yang ada
    puts("Customer's list");
    for(int i = 0; i<26; i++){
        if(chead[i]){
            printf("%d. ", i);
            Customer *curr = chead[i];
            while(curr){
                if(curr->next==NULL) printf("%s", curr->name);
                else printf("%s -> ", curr->name);
                curr = curr->next;
            }
            puts("");
        }
    }
    puts("Press enter to continue");
    getchar();
}

void popCustomer(int index){ //untuk menghapus customer yang ada di head hash chaining
    if(chead[index]==ctail[index]){
        chead[index] = ctail[index] = NULL;
        free(chead[index]);
    }
    else{
        Customer *temp = chead[index]->next;
        chead[index]->next = NULL;
        free(chead[index]);
        chead[index] = temp;
    }
}

Customer *search(char *name){ //validasi customer ada atau tidak
    for(int i = 0; i<26; i++){
        if(chead[i]){
            Customer *curr = chead[i];
            while(curr && strcmp(curr->name, name)!=0){
                curr = curr->next;
            }
            if(curr){
                return curr;
            }
        }
    } 
    return NULL;
}

void insertOrder(Customer *cust, Order *ord){
    if(!cust->ohead){
        cust->ohead = cust->otail = ord;
    }
    else{
        Order *curr = cust->ohead;
        while(curr){ //cek apakah sudah ada order dengan nama sama
            if(strcmp(curr->name, ord->name)==0){
                break;
            }
            curr = curr->next;
        }
        if(!curr){ //jika customer belum order menu dengan nama sama
            cust->otail->next = ord;
            cust->otail = ord;
        }
        else{ //kalau sudah ada tambah quantity
            curr->qty = curr->qty + ord->qty;
            curr->price = curr->price + ord->price;
        }
    }
}

void printOrder(Customer *cust){
    Order *curr = cust->ohead;
    int i = 1, total = 0; //total = harga total order
    printf("%s\n", cust->name);
    while(curr){
        printf("[%d]%s x%d\n", i, curr->name, curr->qty);
        total += curr->price;
        curr = curr->next;
        i++;
    }
    printf("Total: Rp%d\n", total);
    puts("Press enter to continue");
    getchar();
}

int isAlphabet(char *name){ //cek apakah ada karakter lain selain alphabet
    for(int i = 0; i<strlen(name); i++){
        if((name[i]<'a'||name[i]>'z') && (name[i]<'A'||name[i]>'Z')){ 
            return 1;
        }
    }
    return 0;
}

int isLowercase(char *name){ //cek apakah karkater bukan lowercase dan bukan spasi
    for(int i = 0; i<strlen(name); i++){
        if((name[i]<'a'||name[i]>'z') && name[i]!=' '){
            return 1;
        }
    }
    return 0;
}