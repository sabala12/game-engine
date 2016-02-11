//
// Created by eran on 2/9/16.
//

#ifndef GAME_ENGINE_SYNC_H
#define GAME_ENGINE_SYNC_H

#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>

namespace Engine
{
    class Sync
    {
    public:
        Sync();

        void Notify();
        void Start(std::function<bool(void)> pred);
        bool IsStoped() const;

    private:
        boost::condition_variable m_cv;
        boost::mutex m_mutex;
        bool m_flag;
    };

}

#endif //GAME_ENGINE_SYNC_H
