#ifndef SCENE
#define SCENE

#include "AbstractEntity.hh"
#include "TimeManager.hh"
#include "list"
#include "ISerializable.hh"
#include "json.hpp"
#include "MonsterFactory.hh"


class Scene: public ISerializable{
    public :
        Scene();
        //Scene(const std::string&);
        ~Scene();
        std::list<AbstractEntity*> GetEntities() const;
        void AddEntity(AbstractEntity*);
        void RemoveEntity(AbstractEntity*);
        void Update();
        std::string Serialize() override;
        void test(const std::string& str);

    private:
        std::list<AbstractEntity*> listEntities;

};

#endif