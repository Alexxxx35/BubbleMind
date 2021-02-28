#ifndef DEF_MONSTERFACTORY
#define DEF_MONSTERFACTORY
#include "Character.hh"
#include "string"
#include "SprinterMonster.hh"
#include "ZombieMonster.hh"


class MonsterFactory{
    public:
        MonsterFactory();
        ~MonsterFactory();

        static Character* Create(const std::string&);
        static Character* Unserialize(const std::string&);
    

};

#endif