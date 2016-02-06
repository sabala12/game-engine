#ifndef GAME_ENGINE_DISPLAY_DATA_H
#define GAME_ENGINE_DISPLAY_DATA_H

namespace Engine {

    struct DisplayData {

        DisplayData(unsigned int height, unsigned int width, const std::string& title)
                : m_height(height), m_width(width), m_title(title)
        {
            if (height == 0) {
                //throw exception
            }

            if (width == 0) {
                //throw exception
            }

            m_ratio = width / height;
        }

        inline float Ratio() { return m_ratio; }

        unsigned int m_height;
        unsigned int m_width;
        float m_ratio;
        const std::string m_title;
    };
}

#endif //GAME_ENGINE_DISPLAY_DATA_H
