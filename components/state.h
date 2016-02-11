//
// Created by eran on 2/10/16.
//

#ifndef GAME_ENGINE_STATE_H
#define GAME_ENGINE_STATE_H

#include <boost/thread/shared_mutex.hpp>

namespace Engine
{
    class State
    {
    public:
        State(bool state)
            : m_state(state)
        {
        }

        inline void Stop()
        {
            Write(false);
        }

        inline void Start()
        {
            Write(true);
        }

        inline bool GetState()
        {
            boost::shared_lock<boost::shared_mutex> readLock(m_access);
            return m_state;
        }

    private:

        void Write(bool state) {
            boost::upgrade_lock<boost::shared_mutex> lock(m_access);
            boost::upgrade_to_unique_lock<boost::shared_mutex> uniqueLock(lock);
            m_state = state;
        }

        boost::shared_mutex m_access;
        bool m_state;
    };
}

#endif //GAME_ENGINE_STATE_H
