#include "simulation.h"

int main(int argc, char *argv[]){
    Server_t twitter{};
    Tag_t *tags[1000];
    int usernum = 0;
    int tagnum = 0;
    int count = 0;
    string name;
    int i;
    twitter.user_num = 0;

    string path = R"(C:\Users\James Xia\Desktop\Ve280\p2\p2_starters\username)";
    ifstream file(path);
    if(!file.is_open()) return 0;
    //init_user(file, twitter);
    //init_post(twitter, users, tags, tagnum, count);
    getline(file, name);
    while(getline(file, name)){
        twitter.users[usernum].username = name;
        usernum++;
        for(i = 0; i < usernum; i++){
            cout << twitter.users[i].username << endl;
        }

    }
    twitter.user_num = usernum;
    file.close();

    cout << usernum << endl;
    return 0;

}
