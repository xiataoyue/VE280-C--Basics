/*
 * This is VE280 Project 2, SU2020.
 * Written by Ziqiao Ma and Zhuoer Zhu.
 * Latest Update: 5/29/2020.
 * All rights reserved.
 */

#include "server_type.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <algorithm>



// TODO: Declare your functions in this header file.
// Hint: You may need these request handling functions.
void init_user(ifstream& file, Server_t& server/*, User_t *users[MAX_USERS]*/);
void init_post(Server_t& server, User_t *users[], Tag_t *tags[], int& tag_num, int& count);

User_t *get_user(const Server_t& server, const string& name);
void find_user(ifstream& file, Server_t& server, User_t *user[], unsigned int number);

int catch_tag(Tag_t *tags[], unsigned int num, string& name);
int add_tag(Tag_t *tags[], int& num, string& content, int score);
void remove_user(User_t *users[], int num, User_t *target);
string judge_rela(User_t *visitor, User_t *target);
/*
void visit(...);
void trending(...);
void refresh(...);
void follow(...);
void unfollow(...);
void like(...);
void unlike(...);
void comment(...);
void uncomment(...);
void post(...);
void unpost(...);
*/

/* Helper Functions */

// Printing
void printUser(User_t& user, const string& relationship);
void printPost(Post_t& post);
void printTag(const Tag_t& tag, unsigned int rank);

