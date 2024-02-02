#include "OrbitalCamera.h"

#include <cmath>

OrbitalCamera::OrbitalCamera(Vector3 target, float radius) {
    m_target = target;
    m_radius = radius;
    m_x_angle = 0.0f;
    m_y_angle = 0.0f;
}

void OrbitalCamera::UpdateAngles(float speed) {
    m_x_angle += (speed * (-(float)IsKeyDown(KEY_RIGHT) + (float)IsKeyDown(KEY_LEFT)));

    m_y_angle += (speed * ((float)IsKeyDown(KEY_UP) - (float)IsKeyDown(KEY_DOWN)));
    if(m_y_angle > (PI/2.0f)-0.01f) m_y_angle = (PI/2.0f)-0.01f;
    else if(m_y_angle < (-PI/2.0f)+0.01f) m_y_angle = (-PI/2.0f)+0.01f;
}

float OrbitalCamera::GetXAngle() { return m_x_angle; }
void OrbitalCamera::SetXAngle(float angle) { m_x_angle = angle; }

float OrbitalCamera::GetYAngle() { return m_y_angle; }
void OrbitalCamera::SetYAngle(float angle) {
    m_y_angle = angle;
    if(m_y_angle > (PI/2.0f)-0.01f) m_y_angle = (PI/2.0f)-0.01f;
    else if(m_y_angle < (-PI/2.0f)+0.01f) m_y_angle = (-PI/2.0f)+0.01f;
}


Camera3D OrbitalCamera::GetRlCamera() {
    return {
            {
                    (float)(m_target.x + cos(m_x_angle) * cos(m_y_angle) * m_radius),
                    (float)(m_target.y + sin(m_y_angle) * m_radius),
                    (float)(m_target.z + sin(m_x_angle) * cos(m_y_angle) * m_radius)
            },
            m_target,
            {0.0f, 1.0f, 0.0f},
            50.0f,
            CAMERA_PERSPECTIVE
    };
}
