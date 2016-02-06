//
// Created by eran on 2/4/16.
//

#ifndef GAME_ENGINE_CLIENT_CONSTRAINT_H
#define GAME_ENGINE_CLIENT_CONSTRAINT_H

namespace Engine
{
    template <class Client>
    class ClientConstraint
    {
    private:
        static void constraints(Client* client) {
            typename Client::SendSyncOutput* sync_result = client->send_sync_request(typename Client::SendSyncInput());
            typename Client::SendASyncOutput* async_result = client->send_async_request(typename Client::SendASyncInput());
        }

    public:
        ClientConstraint() {
            void(*p)(Client*) = constraints;
        }
    };
}

#endif //GAME_ENGINE_CLIENT_CONSTRAINT_H
