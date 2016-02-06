#ifndef GAME_ENGINE_ENGINE_DATA_H
#define GAME_ENGINE_ENGINE_DATA_H

#include "common_structs/routing_data.h"
#include "common_structs/camera_data.h"
#include "common_structs/display_data.h"
#include "common_structs/camera_data.h"
#include "communication/zmq/zmq_publisher.h"

#include <string>

namespace Engine
{
    struct EngineData
    {
        EngineData(const CameraData& camera_data, const DisplayData& display_data)
            : m_camera_data(camera_data), m_display_data(display_data)
        {
        }

        const DisplayData m_display_data;
        const CameraData m_camera_data;
    };
}

#endif //GAME_ENGINE_ENGINE_DATA_H
