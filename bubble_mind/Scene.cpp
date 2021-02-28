#include "Scene.hh"

#include <iostream>
using json = nlohmann::json;
Scene::Scene(){}
Scene::~Scene(){}
/*Scene::Scene(const std::string& str){
    auto j = json::parse(str);
    for(json::iterator it =j.begin(); it!=j.end(); ++it){
        //std::cout <<   *it << std::endl;
        Character * c = MonsterFactory::Unserialize(*it);
        AddEntity(c);
    }

}*/

void Scene::test(const std::string& str){
    auto j = json::parse(str);
    for(json::iterator it =j.begin(); it!=j.end(); ++it){
        std::cout <<   *it << std::endl;
        
    }
}





std::list<AbstractEntity*> Scene::GetEntities() const{
    return Scene::listEntities;
}

void Scene::AddEntity(AbstractEntity* entity){
    this-> listEntities.push_back(entity);
}

void Scene::RemoveEntity(AbstractEntity* entity){

    listEntities.remove(entity);

}


void Scene::Update(){
    TimeManager::GetInstance().Update();
    for (AbstractEntity* entity : listEntities){
        entity->Update();
    } 
    for (AbstractEntity* entity : listEntities){
        entity->Draw();
    } 


}

std::string Scene::Serialize(){
    json j;
    for(AbstractEntity * a : listEntities){
        std::string s = a->Serialize();
        j.push_back( s);
    }
    return j.dump();

}

