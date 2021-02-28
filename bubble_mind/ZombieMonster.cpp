#include "ZombieMonster.hh"

using json = nlohmann::json;

ZombieMonster::ZombieMonster() : Character(){
    SetLife(100);
}
ZombieMonster::~ZombieMonster(){}

void ZombieMonster::Update(){
    unsigned int elapsed_time = TimeManager::GetInstance().GetElapsedTime();
    // elapsed_time/1000 ->  nous donne le temps en secondes
    SetX(GetX()+(1*(double) elapsed_time/1000));
    SetY(GetY()+(1* (double) elapsed_time/1000));

}

std::string ZombieMonster::Serialize(){
    json j ;
    j["type"] = "ZombieMonster";
    j["life"] = GetLife();
    j["x"] = GetX();
    j["y"] = GetY();
    return j.dump();

}