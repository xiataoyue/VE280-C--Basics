// include the library you want
// put the defintion of class before main
// define the creature base type
#include <iostream>
#include <string>
using namespace std;

class creature{
    //put your code here
    //note: do not declare attributes, such as life as public members(otherwise there will be deduction)
protected:
    int life;
    int DPA;
public:
    creature(): life(0), DPA(0) {};
    void life_loss(int attack);
    void set_data(int _life, int _DPA);
    int show_DPA();
    bool isDead();
};

void creature::life_loss(int attack) {
    life -= attack;
}

void creature::set_data(int _life, int _DPA) {
    life = _life;
    DPA = _DPA;
}

int creature::show_DPA() {
    return DPA;
}

bool creature::isDead() {
    return life <= 0;
}


class Elves: public creature{
    //put your code here(it can be blank)
private:
    int round;
public:
    Elves(): creature(), round(0) {};
    void feature(int attack);
};

void Elves::feature(int attack) {
    round ++;
    if(round == 2) {
        life += attack;
        round = 0;
    }
}

class Humans: public creature{
    //put your code here(it can be blank)
public:
    Humans(): creature() {};

};

class Hobbits: public creature{
    //put your code here(it can be blank)
private:
    bool doubleAttack;
public:
    Hobbits(): creature(), doubleAttack(false){};
    void feature();
};

void Hobbits::feature() {
    if(life < 3 && !doubleAttack){
        this->DPA *= 2;
        doubleAttack = true;
    }
}

// you can declare and implement other functions here

int main(){
    //put your code here
    int Elves_num, Humans_num, Hobbits_num;
    cin >> Elves_num >> Humans_num >> Hobbits_num;

    int Elves_life, Humans_life, Hobbits_life;
    cin >> Elves_life >> Humans_life >> Hobbits_life;

    int Elves_DPA, Humans_DPA, Hobbits_DPA;
    cin >> Elves_DPA >> Humans_DPA >> Hobbits_DPA;

    Elves elv[50];
    for(int i = 0; i < Elves_num; i++){
        elv[i].set_data(Elves_life, Elves_DPA);
    }

    Humans hum[50];
    for(int i = 0; i < Humans_num; i++){
        hum[i].set_data(Humans_life, Humans_DPA);
    }

    Hobbits hob[50];
    for(int i = 0; i < Hobbits_num; i++){
        hob[i].set_data(Hobbits_life, Hobbits_DPA);
    }

    int cnt_elv = 0, cnt_hum = 0, cnt_hob = 0;
    bool f1 = false, f2 = false, f3 = false;
    string group1, group2;
    cin >> group1 >> group2;

    cout << "Group size(Elves, Humans, Hobbits): " << Elves_num << ", " << Humans_num << ", " << Hobbits_num << endl;
    cout << "Life value(Elves, Humans, Hobbits): " << Elves_life << ", " << Humans_life << ", " << Hobbits_life << endl;
    cout << "DPA(Elves, Humans, Hobbits): " << Elves_DPA << ", " << Humans_DPA << ", " << Hobbits_DPA << endl;
    cout << "When " << group1 << " fights with " << group2 << endl;

    if((group1 == "Elves" && group2 == "Humans") || (group1 == "Humans" && group2 == "Elves")){
        while(1){
            hum[cnt_hum].life_loss(elv[cnt_elv].show_DPA());
            if(hum[cnt_hum].isDead()) cnt_hum ++;
            if(cnt_hum >= Humans_num){
                f1 = true;
                break;
            }

            elv[cnt_elv].life_loss(hum[cnt_hum].show_DPA());
            elv[cnt_elv].feature(Humans_DPA);
            if(elv[cnt_elv].isDead()) cnt_elv++;
            if(cnt_elv >= Elves_num) {
                f2 = true;
                break;
            }
        }
    }
    else if((group1 == "Humans" && group2 == "Hobbits") || (group1 == "Hobbits" && group2 == "Humans")){
        while(cnt_hum < Humans_num && cnt_hob < Hobbits_num){
            hob[cnt_hob].life_loss(hum[cnt_hum].show_DPA());
            hob[cnt_hob].feature();
            if(hob[cnt_hob].isDead()) cnt_hob ++;
            if(cnt_hob >= Hobbits_num){
                f2 = true;
                break;
            }
            cout << hob[cnt_hob].show_DPA() << endl;
            hum[cnt_hum].life_loss(hob[cnt_hob].show_DPA());
            if(hum[cnt_hum].isDead()) cnt_hum++;
            if(cnt_hum >= Humans_num) {
                f3 = true;
                break;
            }
        }
    }
    else if((group1 == "Elves" && group2 == "Hobbits") || (group1 == "Hobbits" && group2 == "Elves")){
        while(1){
            hob[cnt_hob].life_loss(elv[cnt_elv].show_DPA());
            hob[cnt_hob].feature();
            if(hob[cnt_hob].isDead()) cnt_hob ++;
            if(cnt_hob >= Hobbits_num){
                f1 = true;
                break;
            }
            elv[cnt_elv].life_loss(hob[cnt_hob].show_DPA());
            elv[cnt_elv].feature(hob[cnt_hob].show_DPA());
            if(elv[cnt_elv].isDead()) cnt_elv++;
            if(cnt_elv >= Elves_num) {
                f3 = true;
                break;
            }
        }
    }
    else cout << "Invalid group name!" << endl;

    if(f1) cout << "Elves wins!" << endl;
    if(f2) cout << "Humans wins!" << endl;
    if(f3) cout << "Hobbits wins!" << endl;

    return 0;
}
