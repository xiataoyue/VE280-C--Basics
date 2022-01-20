/*
 * This is VE280 Project 2, SU2020.
 * Written by Ziqiao Ma and Zhuoer Zhu.
 * Latest Update: 5/29/2020.
 * All rights reserved.
 */

#include "simulation.h"

// TODO: Define your functions in this header file.

/* Helper Functions */
/*void init_user(ifstream& file, Server_t& server){
    string name;
    int num = 0;
    getline(file, name);
    while(getline(file, name)){
        server.users[num]->username = name;
        num++;
        server.user_num++;
    }
}

void init_post(Server_t& server, User_t *users[], Tag_t *tags[], int& tag_num, int& count){
    int i, j, k;
    int postsnum, likenum, commentnum;
    int followingnum, followernum;
    string str;
    char ch;
    for(i = 0; i < server.user_num; i++){
        str = "users/" + server.users[i]->username +"/user_info";
        ifstream file(str);

        file >> postsnum;
        server.users[i]->num_posts = postsnum;
        file.get(ch);

        for(j = 1; j <= server.users[i]->num_posts; j++){
            server.users[i]->posts[j].owner = server.users[i];

            str = "users/" + server.users[i]->username + "/posts/" + to_string(j);
            ifstream post(str);

            getline(post, server.users[i]->posts[j].title);

            while(getline(post, str) && str[0] == '#'){

                server.users[i]->posts[j].tags[tag_num] = str.substr(1, str.length() - 2);
                tag_num ++;
                if(count == 0){
                    server.tags[count]->tag_content = str.substr(1, str.length() - 2);
                    server.tags[count]->tag_score = 5;
                    count ++;
                }
                add_tag(server.tags, count, server.users[i]->posts[j].tags[tag_num], 5);
                server.users[i]->posts[j].num_tags = tag_num;
            }

            server.users[i]->posts[j].text = str;

            post >> likenum;
            server.users[i]->posts[j].num_likes = likenum;
            post.get(ch);

            find_user(post, server, server.users[i]->posts[j].like_users, server.users[i]->posts[j].num_likes);

            post >> commentnum;
            server.users[i]->posts[j].num_comments = commentnum;
            post.get(ch);

            for(k = 0; k < commentnum; k++){
                getline(post, str);
                server.users[i]->posts[j].comments[k].user = get_user(server, str);
                getline(post, str);
                server.users[i]->posts[j].comments[k].text = str;
            }

            for(k = 0; k < tag_num; k++){
                add_tag(server.tags, count, server.tags[k]->tag_content, 3*commentnum + likenum);
            }
            post.close();
        }
        file >> followingnum;
        server.users[i]->num_following = followingnum;
        file.get(ch);
        find_user(file, server, server.users[i]->following, server.users[i]->num_following);

        file >> followernum;
        server.users[i]->num_followers = followernum;
        file.get(ch);
        if(followernum == 0) file.close();
        find_user(file, server, server.users[i]->follower, server.users[i]->num_followers);
        file.close();
    }
}

User_t *get_user(const Server_t& server, const string& name){
    int i;
    for(i = 0; i < server.user_num; i++){
        if(name.compare(server.users[i]->username) == 0){
            return server.users[i];
        }
    }
    return nullptr;
}

void find_user(ifstream& file, Server_t& server, User_t *users[], unsigned int number){
    string temp;
    int i;
    for(i = 0; i < number; i++){
        getline(file, temp);
        users[i] = get_user(server, temp);
    }
}

int catch_user(User_t *users[], unsigned int num, string& name){
    int i;
    for(i = 0; i < num; i++){
        if(name.compare(users[i]->username) == 0) return i;
    }
    return -1;
}

int catch_tag(Tag_t *tags[], unsigned int num, string& name){
    int i;
    for(i = 0; i < num; i++){
        if(name.compare(tags[i]->tag_content) == 0) return i;
    }
    return -1;
}

int add_tag(Tag_t *tags[], int& num, string& content, int score){
    if(catch_tag(tags, num, content) == -1){
        tags[num]->tag_content = content;
        tags[num]->tag_score = score;
        num++;
        return 1;
    }
    tags[catch_tag(tags, num, content)]->tag_score += score;
    return 0;
}

void follow(User_t *follower, User_t *target){
    follower->following[follower->num_following] = target;
    follower->num_following ++;

    target->follower[target->num_followers] = follower;
    target->num_followers ++;
}

void unfollow(User_t *unfollower, User_t *target){
    unfollower->num_following --;
    remove_user(unfollower->following, unfollower->num_following, target);
    target->num_followers --;
    remove_user(target->follower, target->num_followers, unfollower);
}

void remove_user(User_t *users[], int num, User_t *target){
    int i, n;
    n = catch_user(users, num, target->username);
    if(n != -1){
        for(i = n; i < num; i++) users[n] = users[n+1];
    }
}

string judge_rela(User_t *visitor, User_t *target){
    if(visitor->username.compare(target->username)==0) return "";
    int a = 0, b = 0;  //to judge the relationship, ranging 0 or 1;
    int i;

    for(i = 0; i < target->num_followers; i++){
        if(visitor == target->follower[i]) a = 1;
    }

    for(i = 0; i < visitor->num_followers; i++){
        if(target == visitor->follower[i]) b = 1;
    }

    if(a == 1 && b == 1) return "friend";
    else if(a == 1 && b == 0) return "following";
    else return "stranger";
}


// Printing

void printUser(User_t& user, const string& relationship){
    cout << user.username << endl;
    cout << relationship << endl;
    cout << "Followers: " << user.num_followers
         << "\nFollowing: " << user.num_following << endl;
}


void printPost(Post_t& post){
    cout << post.owner->username << endl;
    cout << post.title << endl;
    cout << post.text << endl;
    cout << "Tags: ";
    for(unsigned int i = 0; i<post.num_tags; ++i){
        cout << post.tags[i] << " ";
    }
    cout << "\nLikes: " << post.num_likes << endl;
    if (post.num_comments > 0){
        cout << "Comments:" << endl;
        for(unsigned int i = 0; i<post.num_comments; ++i){
            cout << post.comments[i].user->username << ": "
                 << post.comments[i].text << endl;
        }
    }
    cout << "- - - - - - - - - - - - - - -" << endl;
}


void printTag(const Tag_t& tag, unsigned int rank){
    cout << rank << " " << tag.tag_content << ": " << tag.tag_score << endl;
}
*/