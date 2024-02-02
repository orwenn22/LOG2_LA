#include "Q1.h"

#include "OrbitalCamera.h"
#include "Utils.h"

#include <raylib.h>

void Q1() {
    //GetWorldToScreen();

    OrbitalCamera cam({0.f, 0.f, 0.f}, 50.f);

    cam.SetXAngle(PI/4);
    cam.SetYAngle(PI/12);

    RenderTexture render = LoadRenderTexture(500, 500);

    //while (!WindowShouldClose()) {
    //cam.UpdateAngles();
    for(int i = 0; i < 50; ++i) {
        cam.SetXAngle(cam.GetXAngle() + (PI*2)/50);

        Camera3D rl_cam = cam.GetRlCamera();

        Vector2 x_text_pos = GetWorldToScreen({15.f, 0.f, 0.f}, rl_cam);
        Vector2 y_text_pos = GetWorldToScreen({0.f, 15.f, 0.f}, rl_cam);
        Vector2 z_text_pos = GetWorldToScreen({0.f, 0.f, 15.f}, rl_cam);

        //BeginDrawing();

        BeginTextureMode(render);
        ClearBackground(BLACK);

        BeginMode3D(rl_cam);
        DrawLine3D({-15.f, 0.f, 0.f}, {15.f, 0.f, 0.f}, WHITE);
        DrawLine3D({0.f, -15.f, 0.f}, {0.f, 15.f, 0.f}, WHITE);
        DrawLine3D({0.f, 0.f, -15.f}, {0.f, 0.f, 15.f}, WHITE);

        DrawTriangle3DDouble(
                {15.f, 0.f, 15.f},
                {15.f, 0.f, -15.f},
                {-15.f, 0.f, 15.f},
                {255, 0, 0, 127}
        );

        DrawTriangle3DDouble(
                {-15.f, 0.f, -15.f},
                {-15.f, 0.f, 15.f},
                {15.f, 0.f, -15.f},
                {255, 0, 0, 127}
        );

        EndMode3D();

        DrawText("x", (int)x_text_pos.x, (int)x_text_pos.y, 10, WHITE);
        DrawText("y", (int)y_text_pos.x, (int)y_text_pos.y, 10, WHITE);
        DrawText("z", (int)z_text_pos.x, (int)z_text_pos.y, 10, WHITE);

        EndTextureMode();

        Image img = LoadImageFromTexture(render.texture);
        ImageFlipVertical(&img);
        ExportImage(img, TextFormat("Frame%i.png", i));
        UnloadImage(img);
    }

    UnloadRenderTexture(render);
}