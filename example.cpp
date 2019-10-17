#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

class Base{
int coordinates, maxcoordinates;
int width = 3;
public:
  Base(){
    maxcoordinates = 50;
    coordinates = rand()%maxcoordinates+1;
  }
  int get_coordinates(){ 
    return coordinates;
  }
  int get_width(){
    return width;
  }
};

class Player{
  string name;
  int money;
public:
  Player(){
      name = "";
      money = 0;
  }
  int victory(int win){
    money = money+win;
    return money;
  }
  int rate(int rate){
    money = money-rate;
    return rate;
  }
  string get_name()
  {
    return name;
  }
  int get_money(){
    return money;
  }
  void set_name(string input_name){
    name = input_name;
  }
  void set_money(int input_money){
    money = input_money;
  }
  int shoot(int v, int ang){
    return (int)(pow(v, 2)*sin((ang*M_PI)/180))/9.8;
  }
};

class Bank{
  int money;
public:
  Bank(){
    money = 0;
  }
  void put_money(int added_money){
    money = money + added_money;
  }
  int get_money_of_bank(){
    return money;
  }
};

class Game{
  bool game_run;
  Player list_of_players[2];
  Bank bank;
  Base base;
public:

  void registration(){
    cout<<"Igra na dvoih"<<endl;
    cout<<endl;
    for (int i=0; i<2; i++){
      Player new_player;
      string name;
      cout<<"Enter your name"<<endl;
      cin>>name;
      new_player.set_name(name);
      new_player.set_money(10);
      cout<<"Weclome to  "<<name<<" "<<"Your balance is "<<new_player.get_money()<<" "<<"coins"<<endl;
      cout<<endl;
      list_of_players[i] = new_player;
    }

  }

  void new_game()
  {
      game_run = true;
      cout<<"Start game"<<endl;
      for (int i=0; i<2; i++){
        bank.put_money(list_of_players[i].rate(5));
        cout<<"Player "<<list_of_players[i].get_name()<<" "<<"makes a bet 5 coins"<<endl;
      }
      cout<<endl<<"Base installation"<<endl;
      cout<<"The base is set. Coordinates: "<<base.get_coordinates()<< ". "<<"Width of base: "<<base.get_width()<< endl;
      click();
  }

  void click(){
    while(game_run){
      for (int i = 0; i<2; i++){
        cout<<"Goes player "<<list_of_players[i].get_name()<<endl;
        int speed, angle;
        cout<<"Enter the speed: "<<endl;
        cin>> speed;
        cout<<"Enter the angle:"<<endl;
        cin>> angle;
        int shot = list_of_players[i].shoot(speed, angle);
        cout<< "Your ball landed in the coordinate: "<<shot<<" "<<endl;
        if (check_win(shot)){
          cout<<"Сongratulate "<<list_of_players[i].get_name()<<"!"<<endl;
          int jackpot = bank.get_money_of_bank();
          list_of_players[i].victory(jackpot);
          game_run = false;
          continuation_of_the_game();
        }
      }
    }
  }

  bool check_win(int shot){
    if((base.get_coordinates()-base.get_width())<=shot && shot<=(base.get_coordinates()+base.get_width())){
      cout<<"Hit!"<<endl;
      return true;
    }
    else{
     cout<<"Loser!"<<endl;
     return false;
    }
  }

  void continuation_of_the_game(){
    for (int i = 0; i<2; i++){
      cout<<list_of_players[i].get_name()<<" "<<"If you want to continue type yes"<<endl;
      string question;
      cin>>question;
      if(question=="yes"){
        cout<<"You're back in the game "<<list_of_players[i].get_name()<<endl;
        continue;
      }
      else{
      cout<<"Goodbye!"<<endl;
      }
    }
    new_game();
  }
};


int main(){
  Game game;
  game.registration();
  game.new_game();
}
