#ifndef __JUSER__
#define __JUSER__

/*
  A more abstract usage of User data, to handle user operations.
*/

struct user_struct {
    char *nickname;
    char *ip;
    char *password;
    time_t time_authorized;
};


void create_new_user(const char *nickname, const char *ip, const char *password);
void change_password_user(const char* current_password, const char* new_password);
void get_ip_user(const char* nickname);
void update_ip_user(const char* nickname, const char* ip);
    

#endif
