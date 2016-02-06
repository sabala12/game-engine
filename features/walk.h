#ifndef GAME_ENGINE_WALK_H
#define GAME_ENGINE_WALK_H

#include "features/feature.h"

namespace Engine
{
    class GameObject;

    class Walk : public Feature
    {
    public:
        struct ExecuteInput;
        struct ExecuteOutput;

        Walk(Object* object)
            : Feature(object)
        {

        }

        ExecuteOutput* Execute(const ExecuteInput& input) {
        }
    };

    struct Walk::ExecuteInput {

    };

    struct Walk::ExecuteOutput {

    };
}

#endif //GAME_ENGINE_WALK_H
