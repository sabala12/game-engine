//
// Created by eran on 2/9/16.
//

#include "sync.h"

namespace Engine
{
    Sync::Sync()
            : m_flag(true)
    {
    }

    void Sync::Notify()
    {
        {
            boost::lock_guard<boost::mutex> lk(m_mutex);
            m_flag = true;
        }
        m_cv.notify_one();
    }

    void Sync::Start(std::function<bool(void)> pred)
    {
        boost::unique_lock<boost::mutex> lk(m_mutex);
        m_flag = false;
        m_cv.wait(lk, pred);
    }

    bool Sync::IsStoped() const {
        return m_flag;
    }
}
