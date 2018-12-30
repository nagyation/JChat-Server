#ifndef __JUSER_DB__
#define __JUSER_DB__

#include "juser.h"
#include "jhelper.h"

/*
  Handles writing and reading of user data to database.
  I will use a simple file as a database, hmm.. because that's what I want.
  And it will be highly coupled, since I won't ever support another type in the future.
 */


struct user_struct read_user_db(const char* nickname);
bool update_user_db(const struct user_struct user);
bool create_new_user_db(const struct user_struct user);

#endif
