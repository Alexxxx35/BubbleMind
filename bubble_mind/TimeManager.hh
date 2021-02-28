#ifndef DEF_TIMEMANAGER
#define DEF_TIMEMANAGER

#include <chrono>

class TimeManager{
    public :
        ~TimeManager();

        //Singletons should not be cloneable.
        TimeManager(TimeManager& other ) = delete;

        //Singletons should not be assignable.
        void operator=(const TimeManager&) = delete;

        static TimeManager& GetInstance();
        void Start();
        void Update();
        unsigned int GetElapsedTime() const;
        unsigned int GetStartedTime() const;

        std::chrono::time_point<std::chrono::system_clock> GetStart();
        




    protected:
        TimeManager();
        static TimeManager* timeManager_;

        int countUpdates;
        std::chrono::time_point<std::chrono::system_clock> startTime;
        std::chrono::time_point<std::chrono::system_clock> lastUpdatedTime;
        std::chrono::time_point<std::chrono::system_clock> previousUpdatedTime;

    };
#endif