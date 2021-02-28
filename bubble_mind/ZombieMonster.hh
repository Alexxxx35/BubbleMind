#ifndef DEF_ZOMBIEMONSTER
#define DEF_ZOMBIEMONSTER
#include "Character.hh"
#include "TimeManager.hh"

class ZombieMonster : public Character {

    public:
        ZombieMonster();
        ~ZombieMonster();
        void Update();
        std::string Serialize() override;

};


#endif