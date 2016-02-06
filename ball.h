#pragma once

#include "components/game_object.h"

#include <glm/glm.hpp>

namespace Engine
{

    class Ball : public Object
    {
    public:
        Ball(){

        }

        virtual ~Ball(){

        }

        // with some command oprition...
        virtual void Update(){

        }

        virtual void Awake(){

        }

        // with some command oprition...
        virtual void Notify(){
            
        }

        virtual void Render(){

        }
    };
}