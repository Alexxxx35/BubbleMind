#ifndef SPRINTERMONSTER
#define SPRINTERMONSTER
#include "Character.hh"
#include "TimeManager.hh"


class SprinterMonster : public Character {

    public:
        SprinterMonster();
        ~SprinterMonster();
        void Update();
        std::string Serialize() override;

};


#endif