#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 250

char student[MAX_SIZE][8][50];

// Global variables
char courses[][6] = {"BSIS", "BSIT", "BSCS", "BSCE", "DCT", "BSME", "BSCK", "BSECE", "BSP", "BSA"};
char name[][10] = {"Liam","Alexander","Oliver","Elijah","Noah","Henry","James","Thomas","Charles","Matthew"};
char mid_name[][10]={"Alcott","Alfred","Andres","Allen","Alessio","Benito","Brady","Charlie","Chauncey","Clement"};
char las_name[][10]={"Levine","Raven","Bardot","Hansley","Cromwell","Monroe","West","Cassidy","Lopez","Lopez"};
char email[][15]={"@gmail.com","@hotmail.com","@yahoo.com"};

int num=10000000;

// Functions Desclation
int rendome_phoneNumber(int number);
char* rendome_year(int number);
void auto_insert(int number);
void insert(int number);
void print(int number);
void search(int number);
void update();
void delete(int number);
void clear_screen();

// Functions Definition

int rendome_phoneNumber(int number){
  srand(number+num++);
  int phone_number=(rand() % 10000000 +num++);
  if(phone_number < 10000000){
    phone_number+=10000000;
  }
  num++;
  int phone=(rand() % 10000000 +num++);
  return phone_number+num++;
}

char* rendome_year(int number){
  srand(number);
  int year=1+(rand()%6);
  if(year == 1){
    return "I";
  }
  else if(year == 2){
    return "II";
  }
  else if(year == 3){
    return "III";
  }
  else if(year == 4){
    return "IV";
  }
  return "II";
}

void auto_insert(int number){
  srand(number+num++);
  strcpy(student[number][0],name[rand()%10]);
  strcpy(student[number][1],mid_name[rand()%10]);
  strcpy(student[number][2],las_name[rand()%10]);
  strcpy(student[number][3],name[rand()%10]);
  strcat(student[number][3],las_name[rand()%10]);
  strcat(student[number][3],email[rand()%3]);
  sprintf(student[number][4],"%d",rendome_phoneNumber(number));
  strcpy(student[number][5],courses[rand()%10]);
  strcpy(student[number][6],rendome_year(number));
  sprintf(student[number][7], "%d", number+1);
}

void insert(int number){
  int input;
  char in[30];
  printf("\nEnter student first name: ");
  scanf("%s",in);
  strcpy(student[number][0],in);
  printf("Enter student middle name: ");
  scanf(" %s",in);
  strcpy(student[number][1],in);
  printf("Enter student last name: ");
  scanf(" %s",in);
  strcpy(student[number][2],in);
  printf("Enter student year: ");
  scanf("%s",in);
  strcpy(student[number][6],in);
  printf("Enter student phone number: ");
  scanf("%s",in);
  strcpy(student[number][4],in);
  printf("Enter student cource: ");
  scanf("%s",in);
  strcpy(student[number][5],in);
  printf("Enter studetn email: ");
  scanf("%s",in);
  strcpy(student[number][3],in);
  input=number;
  sprintf(student[input][7],"%d",number+1);
}

void print(int number){
  for(int i=0 ; i<number ; i++){
    printf("\nId number: %s\n",student[i][7]);
	  printf("Name: %s %s %s\n",student[i][0],student[i][1],student[i][2]);
	  printf("Year: %s\n",student[i][6]);
	  printf("Phone number: %s\n",student[i][4]);
	  printf("Cource: %s\n",student[i][5]);
	  printf("Email: %s\n",student[i][3]);
  }
}

void search(int number){
  int* id=(int*)malloc(sizeof(int));
  retry:
  printf("\nEnter id number: ");
  scanf("%d",&(*id));
  if(*id <= number && *id > 0){
   (*id)--;
   printf("\nId number: %s\n",student[*id][7]);
	 printf("Name: %s %s %s\n",student[*id][0],student[*id][1],student[*id][2]);
	 printf("Year: %s\n",student[*id][6]);
	 printf("Phone number: %s\n",student[*id][4]);
	 printf("Cource: %s\n",student[*id][5]);
	 printf("Email: %s\n",student[*id][3]);
  }
  else{
    printf("\nThere is no studenet with this id number please try again\n");
    goto retry;
  }
  free(id);
}

void update(){
  int* choice=(int*)malloc(sizeof(int));
  int* id=(int*)malloc(sizeof(int));
  printf("\nEnter id number: ");
  scanf("%d",&(*id));
  char again;
  new_update:
  printf("\nYou want to update:\n"
        "1) First name\n"
        "2) Middle name\n"
        "3) Last name\n"
        "4) Year\n"
        "5) Phone number\n"
        "6) Cource\n"
        "7) Email\n"
        "choice: ");
  scanf("%d",&(*choice));
  switch(*choice){
    case 1:
     printf("\nEnter new first name: ");
     scanf("%s",student[*id+1][0]);
    break;
    case 2:
     printf("\nEnter new middle name: ");
     scanf("%s",student[*id][1]);
    break;
    case 3:
     printf("\nEnter new last name: ");
     scanf("%s",student[*id][2]);
    break;
    case 4:
     printf("\nEnter new year: ");
     scanf("%s",student[*id][6]);
    break;
    case 5:
     printf("\nEnter new phone number: ");
     scanf("%s",student[*id][4]);
    break;
    case 6:
     printf("\nEnter new cource: ");
     scanf("%s",student[*id][5]);
    break;
    case 7:
     printf("\nEnter new email: ");
     scanf("%s",student[*id][3]);
    break;
  }
  printf("You want to update anothor information of this student[y/n]: ");
  scanf(" %c",&again);
  if(again == 'y'){
    goto new_update;
  }
  free(choice);
  free(id);
  return;
}

void delete(int number){
 int* id=(int*)malloc(sizeof(int));
 again:
 printf("\nEnter id number: ");
 scanf("%d",&(*id));
 if(*id <= number){
   for(int i=*id ; i<number ; i++){
     strcpy(student[i][0],student[i+1][0]);
     strcpy(student[i][1],student[i+1][1]);
     strcpy(student[i][2],student[i+1][2]);
     strcpy(student[i][3],student[i+1][3]);
     strcpy(student[i][4],student[i+1][4]);
     strcpy(student[i][5],student[i+1][5]);
     strcpy(student[i][6],student[i+1][6]);
     sprintf(student[i+1][7],"%d",i);
     strcpy(student[i][7],(student[i+1][7]));
   }
  }
  else{
    printf("\nThere is no studenet with this id number please try again\n");
    goto again;
  }
  free(id);
}

void clear_screen(){
  system("cls"); // this is a cmd command "clear" for terminal
}

int main(){
  int number=0;
  for(int i=0 ; i<200 ; i++){
    auto_insert(number);
    number++;
  }
  int choice;
  repeat:
  printf("\n1) Show student information\n"
         "2) Insert new student information\n"
         "3) Search student\n"
         "4) Update student information\n"
         "5) Delete student information\n"
         "6) clear screen\n"
         "0) exit\n");
  printf("choose: ");
  scanf("%d",&choice);
  if(choice == 0){
    exit(0);
  }
  else if(choice == 1){
    print(number);
  }
  else if(choice == 2){
    insert(number);
    number++;
  }
  else if(choice == 3){
    search(number);
  }
  else if(choice == 4){
    update();
  }
  else if(choice == 5){
    delete(number);
    number--;
  }
  else if(choice == 6){
    clear_screen();
  }
  goto repeat;
}