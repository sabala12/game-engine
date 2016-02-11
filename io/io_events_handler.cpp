//
// Created by eran on 2/8/16.
//

#include "io_events_handler.h"

namespace Engine {

    void IOEventsHandler::GetKeyState(KeyState& key) {
        const Uint8 *state = SDL_GetKeyboardState(nullptr);
        key.state = state[key.scan_code];
    }

    void IOEventsHandler::GetKeysState(KeyState* keys, unsigned int length) {
        const Uint8* state = SDL_GetKeyboardState(nullptr);
        for(int i = 0; i < length; i++) {
            keys[i].state = state[keys[i].scan_code];
        }
   }
}