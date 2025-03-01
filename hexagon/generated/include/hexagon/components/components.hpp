#pragma once

#include <moss/components/components.hpp>


namespace hexagon {

struct RotationDevice : moss::Component {
    float rotationSpeed;
    bool clockWise;
};

struct BallTag : moss::Component { };
struct HexTag : moss::Component { };

} // hexagon
