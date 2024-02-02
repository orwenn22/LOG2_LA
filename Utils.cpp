#include "Utils.h"

void DrawTriangle3DDouble(Vector3 v1, Vector3 v2, Vector3 v3, Color c) {
    DrawTriangle3D(v1, v2, v3, c);
    DrawTriangle3D(v1, v3, v2, c);
}

