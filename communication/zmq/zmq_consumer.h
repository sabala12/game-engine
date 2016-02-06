//
// Created by eran on 2/4/16.
//

#ifndef GAME_ENGINE_CONSUMER_H
#define GAME_ENGINE_CONSUMER_H

#include <zmq.hpp>

namespace Engine
{
    struct RoutingData;

    class ZmqConsumer
    {
    public:
        struct ConsumeOutput;
        struct ConsumeInput;

        ZmqConsumer(const RoutingData&);

        ConsumeOutput* consume(const ConsumeInput&);

    private:
        zmq::socket_t m_socket;
    };
}



#endif //GAME_ENGINE_CONSUMER_H
