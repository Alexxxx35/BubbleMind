#include "TimeManager.hh"
#include <chrono>
#include <iostream>

TimeManager* TimeManager::timeManager_= nullptr;

TimeManager::TimeManager(){
    this-> countUpdates = 0;
}
TimeManager::~TimeManager() {}


TimeManager& TimeManager::GetInstance(){
    if(timeManager_==nullptr){
        timeManager_=new TimeManager();
    }
    return *timeManager_;
}



void TimeManager::Start(){
    this-> startTime=  std::chrono::system_clock::now();
}

void TimeManager::Update(){
    if(countUpdates==0){
        this->lastUpdatedTime = std::chrono::system_clock::now();
        countUpdates++;   
    }
    else {
        this->previousUpdatedTime = this->lastUpdatedTime;
        this -> lastUpdatedTime = std::chrono::system_clock::now();
        countUpdates++;
    }

    
    
    
}
unsigned int TimeManager::GetStartedTime() const{
    return (unsigned int)(std::chrono::duration_cast<std::chrono::milliseconds> (lastUpdatedTime-startTime).count());

}
unsigned int TimeManager::GetElapsedTime() const{
    if(countUpdates <2) return 0;
    else return (unsigned int)(std::chrono::duration_cast<std::chrono::milliseconds> (lastUpdatedTime-previousUpdatedTime).count());
}

