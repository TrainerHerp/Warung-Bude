#include"../Controls/Menu.h"
#include<time.h>

const char* detectOS() {
  #ifdef _WIN32
  return "Windows 32-bit";
  #elif _WIN64
  return "Windows 64-bit";
  #elif __APPLE__ || __MACH__
  return "Mac OSX";
  #elif __linux__
  return "Linux";
  #elif __FreeBSD__
  return "FreeBSD";
  #elif __unix || __unix__
  return "Unix";
  #else
  return "Other";
  #endif
}

void splashScreen(){
    puts("                                                      ..`");
    puts("                  .//.                               /+++-   `    :/:");
    puts("                  /MM:                               -/+/` .hm/   dMd");
    puts("         :osso/`  /MM:   `+ss+:ss-  `/osso:   /so:sy: ss/ +yMMhs: dMd/sso:   +s+/sso-.+sso:");
    puts("        hMdo+dMm. /MM:  .NMNyyNMM/ .NMmsyNMh  yMMmss- MMy :oMMy/- dMMdshMMo  mMMdsdMMMdshMMs");
    puts("        .-:--+MM/ /MM:  +MM-  /MM/ sMM`  +MM- yMM`    MMy  -MM+   dMm   dMm  mMm   mMm   hMN ");
    puts("       `hMmhyhMM/ /MM:  +MM-  /MM/ sMM   /MM: yMM     MMy  -MM+   dMd   dMm  mMd   dMm   yMM");
    puts("       :MM+  +MM/ :MMo. .NMmsyNMM/ +MM+..yMM. yMM     MMy  -MMs`  dMd   dMm  mMd   dMm   yMM");
    puts("        sNMMNdMM/  smMM- `+syo+MM/  omMMMNh:  yMM     MMs   omMM: dMd   hMm  dMd   dMm   yMN");
    puts("         ``.` ``     `` .dds::hMm`  `..-..`````..`````...````....`...```...``...............");
    puts("                         -shhhyo`  `..............------------------------------------------");
    puts("                                   .+-/`   /::/    :::/`  .-o-`  `/::    -/    -o  :+   -/::");
    puts("                                   .s:s`  -+  /:  .o  :/    s    s`     `y+/   :++./s   //-+");
    puts("                                   .o-+.  `+--+`   +--/.    o    -/--   +.`+`  :-/+ o   :-`");
    puts("                                    ```     ``      ``      `     ```   `         ` `");
}

void printTime(){
    time_t t = time(&t);
    printf("%s\n", ctime(&t));
}

void printMainMenu(){
    printf("System: %s\n", detectOS());
    printTime();
    puts("1. Add Dish");
    puts("2. Remove Dish");
    puts("3. Add Customer");
    puts("4. Search Customer");
    puts("5. View Warteg");
    puts("6. Order");
    puts("7. Payment");
    puts("8. Exit Warteg");
}

void cls(){
    for(int i = 0; i<50; i++){
        puts("");
    }
}

int main(){
    int menu;
    do{
        cls();
        splashScreen();
        printMainMenu();
        do{
            printf(">> ");
            scanf("%d", &menu);
            getchar();
        }while(menu<1||menu>8);
        cls();
        if(menu==1){
            addDish();
        }
        else if(menu==2){
            removeDish();
        }
        else if(menu==3){
            addCustomer();
        }
        else if(menu==4){
            searchCustomer();
        }
        else if(menu==5){
            printCustomer();
        }
        else if(menu==6){
            order();
        }
        else if(menu==7){
            payment();
        }
    }while(menu!=8);
    return 0;
}