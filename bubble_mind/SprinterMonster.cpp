#include "SprinterMonster.hh"
using json = nlohmann::json;

SprinterMonster::SprinterMonster() : Character(){
    SetLife(25);
}
SprinterMonster::~SprinterMonster(){}

void SprinterMonster::Update(){
    unsigned int elapsed_time = TimeManager::GetInstance().GetElapsedTime();
    // elapsed_time/1000 ->  nous donne le temps en secondes
    SetX(GetX()+(5* (double) elapsed_time/1000));
    SetY(GetY()+(5*(double) elapsed_time/1000));
    
}

std::string SprinterMonster::Serialize(){
    json j ;
    j["type"] = "SprinterMonster";
    j["life"] = GetLife();
    j["x"] = GetX();
    j["y"] = GetY();
    return j.dump();

}