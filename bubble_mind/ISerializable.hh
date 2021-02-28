#ifndef ISERIALIZABLE
#define ISERIALIZABLE
#include "string"

class ISerializable{
    public:
        virtual std::string Serialize()=0;
        virtual ~ISerializable(){};

};

#endif