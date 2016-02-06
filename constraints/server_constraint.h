//
// Created by eran on 2/4/16.
//

#ifndef GAME_ENGINE_SERVER_CONSTRAINT_H
#define GAME_ENGINE_SERVER_CONSTRAINT_H

namespace Engine
{
    template <class Server>
    class ServerConstraint
    {
    private:
        static void constraints(Server* server) {
            typename Server::RecvOutput* recv_result = server->recv(typename Server::RecvInput());
            typename Server::ReplayOutput* replay_result = server->replay(typename Server::ReplayInput());
        }

    public:
        ServerConstraint() {
            void(*p)(Server*) = constraints;
        }
    };

}
#endif //GAME_ENGINE_SERVER_CONSTRAINT_H
