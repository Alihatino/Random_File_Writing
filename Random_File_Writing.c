#include <stdio.h>

struct clientData {
   unsigned int acctNum; //hesap numarası
   char lastName[15]; //hesap sahibi soyadı
   char firstName[10]; //hesap sahibi adı
   double balance; //bakiye 
};

int main( void ){

  FILE *cfPtr; //cretid.dat dosya işaretçisi...

  struct clientData client = {0 , "","",0}
  if((cfPtr=fopen("credit.dat","rb+")) == NULL ) {puts("File could not be opened");}
else{
  printf("%s" , "Enter account number"
    "(1 to 100 , 0 to end input )\n?");

    scanf("%d",&client.acctNum);

  while (client.acctNum! = 0){
    printf("%s","Enter lastname,firstname,balance\n?");
    fscanf( stdin, "%14s%9s%1f",client.lastName,client.firstName,&client.balance);


      fseek(cfPtr,(client.acctNum-1)*
          sizeof(struct clientData), SEEK_SET);

      fwrite (&client , sizeof(struct clientData) , 1 , cfPtr);
      printf("%s","enter account number\n?");
      scanf("%d",&client.acctNum);
  }

fclose(cfPtr);

}
}
