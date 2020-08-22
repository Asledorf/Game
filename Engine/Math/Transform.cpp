#include "pch.h"
#include "Transform.h"


namespace Engine
{

    std::istream& operator >> (std::istream& stream, Transform& tf)
    {
        stream >> tf.position;
        std::cout << "Pos: " << tf.position << '\n';
        stream >> tf.scale;
        std::cout << "Sca: " << tf.scale << '\n';
        stream >> tf.angle;
        std::cout << "Ang: " << tf.angle << '\n';

        return stream;

        // TODO: insert return statement here
    }
}
