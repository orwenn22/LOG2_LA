#ifndef INC_3DGRID_ORBITALCAMERA_H
#define INC_3DGRID_ORBITALCAMERA_H

#include <raylib.h>

class OrbitalCamera {
public:
    OrbitalCamera(Vector3 target, float radius);

    void UpdateAngles(float speed);

    float GetXAngle();
    void SetXAngle(float angle);
    float GetYAngle();
    void SetYAngle(float angle);

    Camera3D GetRlCamera();

private:
    float m_radius;
    Vector3 m_target{};

    float m_x_angle;
    float m_y_angle;
};


#endif //INC_3DGRID_ORBITALCAMERA_H
