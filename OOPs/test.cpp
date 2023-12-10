#include<iostream>
#include<time.h>
#include<windows.h>
#include<vector>
using namespace std;
#define ll long long

class hero{// aply 4 pil in this class ps BD
    //private
    private:
    int level;
    int health;
    int damage;
    float soulpower;
    string name;

    //public
    public:
    void sethealth(int valuehehe){
        this->health=valuehehe;
    }
    void setdamage(int valuehehe){
        this->damage=valuehehe;
    }
    void setsoulpower(float valuehehe){
        this->soulpower=valuehehe;
    }
    int gethealth(){
        return this->health;
    }
    int getdamage(){
        return this->damage;
    }
    float getsoulpower(){
        return this->soulpower;
    }
    void assambale(){
        health = 1000 * 1.5 * level;
        damage = 100 * 1.4 * level;
        soulpower = 2;
    }
    void stats(){
        cout << "=----------------------=" << endl ;
        cout << "name = " << name << endl ;
        cout << "level = " << level << endl ;
        cout << "health = " << health << endl ;
        cout << "damage = " << damage << endl ;
        cout << "soulpower = " << soulpower << endl ;
        cout << "=----------------------=" << endl ;
    }
    void give_name(string name){
        this->name=name;
    }
    void level_set(int level){
        this->level = level;
    }
    string returnname(){
        return this->name;
    }
    void takedamage(hero *player){
        this->health-=player->getdamage();
        if(this->soulpower!=0){
            this->soulpower+=0.2;
        }

    }
    void takespd(hero *player){
        this->health-=(player->getsoulpower()*player->getdamage());
        player->setsoulpower(0);
    }
};

void creation(hero *player){
    cout <<  "Your Charecters name " ;
    string name;
    cin >> name;
    player->give_name(name);
    cout << "Your Charecters level " ;
    int level;
    cin >> level;
    (*player).level_set(level);
    (*player).assambale();
}
int rooladice(){
    int number;
    srand(time(0));
    number = (rand() % 6) + 1;
    switch (number){
        case 1:
            cout << ".-------." << endl;
            cout << "|       |" << endl;
            cout << "|   o   |" << endl;
            cout << "|       |" << endl;
            cout << "'-------'" << endl;
            return number;

        case 2:
            cout << ".-------." << endl;
            cout << "| o     |" << endl;
            cout << "|       |" << endl;
            cout << "|     o |" << endl;
            cout << "'-------'" << endl;
            return number;

        case 3:
            cout << ".-------." << endl;
            cout << "| o     |" << endl;
            cout << "|   o   |" << endl;
            cout << "|     o |" << endl;
            cout << "'-------'" << endl;
            return number;

        case 4:
            cout << ".-------." << endl;
            cout << "| o   o |" << endl;
            cout << "|       |" << endl;
            cout << "| o   o |" << endl;
            cout << "'-------'" << endl;
            return number;

        case 5:
            cout << ".-------." << endl;
            cout << "| o   o |" << endl;
            cout << "|   o   |" << endl;
            cout << "| o   o |" << endl;
            cout << "'-------'" << endl;
            return number;

        case 6:
            cout << ".-------." << endl;
            cout << "| o   o |" << endl;
            cout << "| o   o |" << endl;
            cout << "| o   o |" << endl;
            cout << "'-------'" << endl;
            return number;
    }
}

int main(){
    //declaration of objects
    //{
    hero *player1= new hero;
    hero *player2= new hero;
    //}
    
    //creation
    //{
    creation(player1);
    player1->stats();
    creation(player2);
    player2->stats();
    //}

    //rule
    //{
    cout << "Rules are simple, if odd then " << player1->returnname() << " gose frist and if even " << player2->returnname() << " goes first" << endl ;
    //}

    while(player1->gethealth()>0 && player2->gethealth()>0){
        cout << "roll a die rn....." << endl ;
        int number = rooladice();
        start:
        if(number%2!=0){
            cout << player1->returnname() << "'s turn" << endl << endl ;
            cout << "1. ATTACK\n2. SP\n3. SP REGENERATE" << endl << endl ;
            int option;
            cin >> option ;
            switch (option)
            {
            case 1:
                player2->takedamage(player1);
                break;
            case 2:
                player2->takespd(player1);
                break;
            case 3:
                player1->setsoulpower((player1->getsoulpower())*1.1);
                break;
            case 1322:
                cout << player1->returnname() << " is using god's language" << endl ;
                cout << "Let The Lightning,Fire,Nature And Phys Be Upon Us. Combine For Me To Destroy The Very Existence Of This Mortal......\nFADE!!!!!!!!!!!!!!!!!!!!!!" << endl ;
                player2->sethealth(-314159);
                break;
            default:
                cout << "This Is Not An Option" << endl ;
                goto start;
                break;
            }
        }
        else{
            cout << player2->returnname() << "'s turn" << endl << endl ;
            cout << "1. ATTACK\n2. SP\n3. SP REGENERATE" << endl << endl ;
            int option;
            cin >> option ;
            switch (option)
            {
            case 1:
                player1->takedamage(player2);
                break;
            case 2:
                player1->takespd(player2);
                break;
            case 3:
                player2->setsoulpower((player2->getsoulpower())*1.2);
                break;
            case 1322:
                cout << player2->returnname() << " is using god's language" << endl ;
                Sleep(1);
                cout << "Let The Lightning,Fire,Nature And Phys Be Upon Us. Combine For Me To Destroy The Very Existence Of This Mortal......\nFADE!!!!!!!!!!!!!!!!!!!!!!" << endl ;
                Sleep(1);
                player1->sethealth(-314159);
                break;
            default:
                cout << "This Is Not An Option" << endl ;
                goto start;
                break;
            }
        }
        player1->stats();
        player2->stats();
    }
    player2->gethealth()<=0? cout << (*player1).returnname() << " is the winner" : cout << (*player2).returnname() << " is the winner";
    cout << endl << endl << endl << endl << endl ;
    system("pause");//this is for cmd hold
    return 0;
}   