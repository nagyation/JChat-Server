#ifndef __JAUTH__
#define __JAUTH__

#include "jhelper.h"

/*
  This will handle authentication, including hashing, salting and authenticating user, I'm not going to use SSL, so I will work on a protocol between server and client to handle privacy.
 */


bool authorize(const *nickname, const *password);
bool check_session_timeout(const *nickname);


#endif
