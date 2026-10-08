#include<stdio.h>
#include<string.h>

#define MAX_USERS 10
#define CREDENTIAL_LENGTH 30

typedef struct {
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
}User;

User users[MAX_USERS];
int user_count = 0;

void register_user();
int login_user(); // returns the user index
void fix_fgets_input(char*);
void input_password(char*);

int main(){
    int option;
    int user_index;

    while(1){
    printf("\nWelcome To User Management");
    printf("\n1. Register");
    printf("\n2. Login");
    printf("\n3. Exit");
    printf("\nSelect an option: ");
    scanf("%d",&option);
    getchar();// Consumes extra enter
    
    switch (option)
    {
    case 1:
      register_user();
      break;
    case 2:
      user_index = login_user();
      if(user_index >= 0){
        printf("\nLogin Successful! Welcome, %s!\n",users[user_index].username);
      }else{
        printf("\nLogin Failed! Incorrect username or password\n");
      }
      break;
    case 3:
      printf("\nExiting Program.\n");
      return 0;
      break;
    
    default:
      printf("\nInvaild option! Please try again.\n");
      break;
    }
}

    return 0;
}
void register_user() {
   if(user_count == MAX_USERS){
    printf("\nMaximum %d users are allowed! No more registrations are Allowed!!!!!!!!\n");
    return;
   }

   int new_index = user_count;
   printf("\nRegister a new user");
   printf("\nEnter username: ");
   fgets(users[new_index].username, CREDENTIAL_LENGTH, stdin);
   fix_fgets_input(users[new_index].username);
   input_password(users[new_index].password);
   user_count++;
   printf("\nRegistration Successful!\n");
   
}

int login_user(){
   char username[CREDENTIAL_LENGTH];
   char password[CREDENTIAL_LENGTH];

   printf("\nEnter username: ");
   fgets(username, CREDENTIAL_LENGTH, stdin);
   fix_fgets_input(username);
   input_password(password);

   for(int i = 0;i < user_count; i++){
    if(strcmp(username, users[i].username) == 0 && strcmp(password, users[i].username) == 0){
        return i;
    }
   }
    return -1;
}

void input_password(char* password){
    printf("\nEnter password: ");
    fgets(password, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(password);

}

void fix_fgets_input(char* string){
   int index = strcspn(string,"\n");
   string[index] = '\0';
}