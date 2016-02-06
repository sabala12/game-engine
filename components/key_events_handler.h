#ifndef GAME_ENGINE_KEY_EVENTS_HANDLER_H
#define GAME_ENGINE_KEY_EVENTS_HANDLER_H

namespace Engine
{
    struct RoutingData;

    template <class Publisher>
    class KeyEventsHandler
    {
    public:
        void Start(const RoutingData& routingData);

        static KeyEventsHandler* getInstance();

    private:
        KeyEventsHandler();

        KeyEventsHandler(const KeyEventsHandler&) = delete;
        void operator=(const KeyEventsHandler&) = delete;

        void KeyEvent(const SDL_KeyboardEvent& event);
        void MouseEvent(const SDL_MouseMotionEvent& event);
        void QuitEvent();

        void PublishEvent(const char* message);

        SDL_Event m_event;
        Publisher* m_publisher;
    };
}

#include "components/key_event_handler_impl.h"

#endif //GAME_ENGINE_KEY_EVENTS_HANDLER_H