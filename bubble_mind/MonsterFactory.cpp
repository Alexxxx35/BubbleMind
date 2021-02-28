#include "MonsterFactory.hh"
using json = nlohmann::json;

MonsterFactory::MonsterFactory(){}

MonsterFactory::~MonsterFactory(){}

Character* MonsterFactory::Create(const std::string& str){
    if (str=="ZombieMonster"){
        return new ZombieMonster();
    }
    else if (str=="SprinterMonster"){
        return new SprinterMonster();
    }
    else {
        return nullptr;
    }

}
Character* MonsterFactory::Unserialize(const std::string& str){
    auto json = json::parse(str);
    int life = json["life"];
    std::string type = json["type"];
    double x = json["x"];
    double y = json["y"];

    Character* resultat = MonsterFactory::Create(type);
    resultat->SetLife(life);
    resultat->SetX(x);
    resultat->SetY(y);

    return resultat;




}

