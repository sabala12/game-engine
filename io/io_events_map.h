//
// Created by eran on 2/8/16.
//

#ifndef GAME_ENGINE_IO_EVENTS_MAP_H
#define GAME_ENGINE_IO_EVENTS_MAP_H

#include <map>

namespace Engine
{
    class IOEventsHandler;

    class IOEventsMap
    {
    public:
        friend class IOEventsHandler;
        IOEventsMap();



    private:
        //void SetKeyEvent();
        //void SetMouseEvent();
        //void SetMouseEvent();
        std::map<int,int> m_events;
    };
}

#endif //GAME_ENGINE_IO_EVENTS_MAP_H
