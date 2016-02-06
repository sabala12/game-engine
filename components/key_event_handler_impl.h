//
// Created by eran on 2/4/16.
//

#ifndef GAME_ENGINE_KEY_EVENT_HANDLER_IMPL_H
#define GAME_ENGINE_KEY_EVENT_HANDLER_IMPL_H

#include "constraints/publisher_constraint.h"

#include <SDL2/SDL.h>

namespace Engine
{
    template <class Publisher>
    class KeyEventsHandler;

    template <class Publisher>
    KeyEventsHandler<Publisher>::KeyEventsHandler()
    {
        PublisherConstraint<Publisher>();
    }

    template <class Publisher>
    Engine::KeyEventsHandler<Publisher>* Engine::KeyEventsHandler<Publisher>::getInstance()
    {
        static KeyEventsHandler<Publisher> *instance = new KeyEventsHandler<Publisher>();
        return instance;
    }

    template <class Publisher>
    void KeyEventsHandler<Publisher>::PublishEvent(const char* message) {
        m_publisher->publishe(message);
    }

    template <class Publisher>
    void KeyEventsHandler<Publisher>::Start(const RoutingData& routingData)
    {
        m_publisher = new Publisher(routingData);
        bool condition_variable = true;
        while (condition_variable) {
            SDL_PollEvent(&m_event);
            switch (m_event.type) {
                case SDL_QUIT:
                    QuitEvent();
                    break;
                case SDL_MOUSEMOTION:
                    MouseEvent(m_event.motion);
                    break;
                case SDL_KEYDOWN:
                    KeyEvent(m_event.key);
                    break;
            }
        }
    }

    template <class Publisher>
    void KeyEventsHandler<Publisher>::KeyEvent(const SDL_KeyboardEvent& event) {
        switch (event.keysym.scancode)
        {
            case SDL_SCANCODE_A:
                PublishEvent("A");
                break;
            case SDL_SCANCODE_D:
                PublishEvent("D");
                break;
            case SDL_SCANCODE_W:
                PublishEvent("Wa");
                break;
            case SDL_SCANCODE_S:
                PublishEvent("S");
                break;
            case SDL_SCANCODE_E:
                PublishEvent("E");
                break;
            case SDL_SCANCODE_Q:
                PublishEvent("Q");
                break;
            default:
                break;
        }
    }

    template <class Publisher>
    void KeyEventsHandler<Publisher>::MouseEvent(const SDL_MouseMotionEvent& event) {

    }

    template <class Publisher>
    void KeyEventsHandler<Publisher>::QuitEvent() {

    }
}

#endif //GAME_ENGINE_KEY_EVENT_HANDLER_IMPL_H
