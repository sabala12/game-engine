//
// Created by eran on 2/4/16.
//

#ifndef GAME_ENGINE_PUBLISHER_CONSTRAINT_H
#define GAME_ENGINE_PUBLISHER_CONSTRAINT_H

namespace Engine
{
    struct RoutingData;
    
    template <class Publisher>
    class PublisherConstraint
    {
    private:
        static void constraints() {
            Publisher *publisher = new Publisher(RoutingData());
            typename Publisher::Status* publish_result = publisher->publishe(typename Publisher::Input());
        }

    public:
        PublisherConstraint() {
            void(*p)() = constraints;
        }
    };
}


#endif //GAME_ENGINE_PUBLISHER_CONSTRAINT_H
