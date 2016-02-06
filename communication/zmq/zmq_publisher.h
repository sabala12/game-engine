//
// Created by eran on 2/4/16.
//

#ifndef GAME_ENGINE_PUBLISHER_H
#define GAME_ENGINE_PUBLISHER_H

#include <zmq.hpp>
#include <common_structs/routing_data.h>

namespace Engine
{
    struct RoutingData;

    template <class InputData>
    class ZmqPublisher
    {
    public:
        typedef InputData Input;
        struct Status;

        ZmqPublisher(const RoutingData& routingData)
            : m_socket(*routingData.m_context, ZMQ_PUB)
        {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            m_socket.bind(routingData.m_address);
        }

        Status* publishe(const char* input) {
            const unsigned int msg_len = std::strlen(input);
            zmq::message_t request(msg_len);
            memcpy ((void *)request.data(), input, msg_len);
            m_socket.send(request);
        }

        Status* publishe(const Input& input) {
            //m_socket
        }

    private:
        zmq::socket_t m_socket;
    };

    template <class Input>
    struct ZmqPublisher<Input>::Status {

    };
}


#endif //GAME_ENGINE_PUBLISHER_H
