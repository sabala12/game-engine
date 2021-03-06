//
// Created by eran on 2/8/16.
//

#ifndef GAME_ENGINE_IO_EVENTS_HANDLER_H
#define GAME_ENGINE_IO_EVENTS_HANDLER_H

#include <SDL2/SDL.h>

namespace Engine
{
    struct KeyState {
        KeyState(SDL_Scancode scancode)
            : scan_code(scancode)
        {
        }

        SDL_Scancode scan_code;
        Uint8 state;
    };

    class IOEventsHandler
    {
    public:
        static void GetKeyState(KeyState& key);
        static void GetKeysState(KeyState* keys, unsigned int length);

        IOEventsHandler() = delete;
        IOEventsHandler(const IOEventsHandler&) = delete;
        void operator=(const IOEventsHandler&) = delete;
    };
}

#endif //GAME_ENGINE_IO_EVENTS_HANDLER_H
