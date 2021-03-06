#ifndef DISTRIBUTED_MAKEFILE_QUEUEDOABLE_H
#define DISTRIBUTED_MAKEFILE_QUEUEDOABLE_H

#include <iostream>
#include <vector>

#include <boost/serialization/vector.hpp>

class QueueDoable {
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & queueDoable;
    }
public:
    QueueDoable();

    void pushDoable(std::string nomFile);
    std::string popDoable();
    bool empty();
private:
    //Pour gérer une file unique de nom de regle faisable
    std::vector<std::string> queueDoable;
};

#endif //DISTRIBUTED_MAKEFILE_QUEUEDOABLE_H
