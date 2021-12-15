#include <iostream>
#include <cstring>
#include <ctime>











class Monster{

private:

    std::string orr;
    std::string name;
    int strong;
    int helth;
    bool Alive;

    void Die(){
        Alive = false;
    }


public:

    Monster(std::string orr_t,std::string name_t, int strong_t,int helth_t){
        orr=orr_t;
        name=name_t;
        strong=strong_t;
        helth=helth_t;
        Alive = true;

    } // Constructor

    virtual ~Monster(){} // Destructor

    std::string getName()const{return name;}
    int getHealth()const { return helth; }

    void battle_cry(){
        std::cout<<orr<<std::endl;
      }

    int give_damage(){
        return strong + ( 1 + rand() %10);
    }

    void take_damage(int damage){
        helth-=damage;

        if(helth<=0){
            Die();
        }

    }



    bool isAlive(){
        if(Alive == true) return true;
        else return false;
    }

};


class Knight{

private:

    std::string orr;
    std::string name;
    int strong;
    int helth;
    int armor;
    bool Alive;

    void Die(){
        Alive = false;
    }

public:

    Knight(std::string orr_t,std:: string name_t,int strong_t,int helth_t,int armor_t){
        orr=orr_t;
        name=name_t;
        strong=strong_t;
        helth=helth_t;
        armor=armor_t;
        Alive = true;

    }

      std::string getName()const{return name;}
      int getHealth()const { return helth; }

    virtual ~Knight(){}


    void battle_cry(){
        std::cout<<orr<<std::endl;
      }


    int give_armor(){
        return armor + ( 1 + rand() %5);
    }


    int give_damage(){
        return strong + ( 1 + rand() %10);
    }

    void take_damage(int damage){

        damage = damage - armor; // 1 - 3 = -2
        if(damage<0){
            damage = 0;
        }


        helth=helth-damage;

        if(helth<=0){
            Die();
        }

        // 2 - 1 = 1
        // 1 - 2 = -1
    }



    bool isAlive(){
        if(Alive == true) return true;
        else return false;
    }



};


int main(){
    srand(time(NULL));

    Monster volodya("I`m MONSTER","Volodya",6,40);
    Knight grisha("Iam knighte!","Grigory",3,50,1);

    bool Fight = true;
    while (Fight) {
        // Во первых вначале атакует монстр. Он кричит, говорит свое имя и бьет рыцаря. После мы показываем статус Лог о том сколько урона нанесенно.
        // Так же рыцарь в свою очередь говорит, бьет и выводиться лог о том, сколько урона нанесено
        // Дальше мы выводим хп обоих и проверяем живы ли мобы, если кто то из них мертв или оба - заканчиваем бой. Выводим кто победитель.

        volodya.battle_cry();
        std::cout<<volodya.getName()<<" IT`s MY NAME "<<std::endl;
        int monsterTmp_dmg = volodya.give_damage();
        grisha.take_damage(monsterTmp_dmg);
        std::cout << " Knight take : " << monsterTmp_dmg << " dmg!" << std::endl;
        if (grisha.isAlive() == false){
            Fight = false;
            break;
        }
        std::cout << " ------------ \n";

        grisha.battle_cry();
        std::cout<<grisha.getName()<<" iT`S my name "<<std::endl;
        int knightTmp_dmg = grisha.give_damage();
        volodya.take_damage(knightTmp_dmg);
        std::cout<<" Monster take : "<<knightTmp_dmg<<" dmg! "<<std::endl;
        if (volodya.isAlive()==false){
            Fight = false;
            break;
        }

        std::cout << " ------------ \n";
        std::cout << " Monster health: " << volodya.getHealth() << std::endl;
        std::cout << " Knight health: " << grisha.getHealth() << std::endl;
        std::cout << " ------------ \n";


    }

       if(volodya.isAlive()==true){
           std::cout<<volodya.getName()<<" Winer "<<std::endl;
       }
       else{
           std::cout<<grisha.getName()<<" Winer "<<std::endl;
       }

    return 0;


};

