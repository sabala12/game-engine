//
// Created by eran on 2/4/16.
//

#ifndef GAME_ENGINE_CONSUMER_CONSTRAINT_H
#define GAME_ENGINE_CONSUMER_CONSTRAINT_H

namespace Engine
{
    struct RoutingData;

    template <class Consumer>
    class ConsumerConstraint
    {
    private:
        static void constraints() {
            Consumer *consumer = new Consumer(RoutingData());
            typename Consumer::ConsumeOutput* consume_result = consumer->consume(typename Consumer::ConsumeInput());
        }

    public:
        ConsumerConstraint() {
            void(*p)() = constraints;
        }
    };
}


#endif //GAME_ENGINE_CONSUMER_CONSTRAINT_H
