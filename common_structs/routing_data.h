//
// Created by eran on 2/6/16.
//

#ifndef GAME_ENGINE_ROUTING_DATA_H
#define GAME_ENGINE_ROUTING_DATA_H

#include <zmq.hpp>

namespace Engine
{
    struct RoutingData
    {
        RoutingData() {

        }

        RoutingData(zmq::context_t& context, const std::string& address)
            : m_context(&context), m_address(address)
        {

        }

        zmq::context_t* m_context;
        const std::string m_address;
    };
}

#endif //GAME_ENGINE_ROUTING_DATA_H
