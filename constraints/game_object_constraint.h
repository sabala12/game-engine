//
// Created by eran on 2/3/16.
//

#ifndef GAME_ENGINE_GAME_OBJECT_CONSTRAINT_H
#define GAME_ENGINE_GAME_OBJECT_CONSTRAINT_H

#include <string>
//#include <curses.h>

#include "components/scene.h"

namespace Engine
{
    template <class Object>
    class GameObjectConstraint
    {
    private:
        static void constraints(Object* object) {
            //typename Object::AwakeOutput* awake_result = object->Awake(typename Object::AwakeInput());
            //typename Object::NotifyOutput notify_result = object->Awake(typename Object::NotifyOutput());
            const std::string& name = object->GetName();
            //object->SetScene(new Scene());
        }
    public:
        GameObjectConstraint() {
            void(*p)(Object*) = constraints;
        }
    };
}

#endif //GAME_ENGINE_GAME_OBJECT_CONSTRAINT_H
