#include "Q2.h"

#include "OrbitalCamera.h"
#include "Utils.h"

#include <math.h>
#include <raylib.h>

// Example of a subset that is not a vector subspace
void Q2a() {
    OrbitalCamera cam({0.f, 0.f, 0.f}, 50.f);

    cam.SetXAngle(PI/4);
    cam.SetYAngle(2*PI/12);

    //SetWindowSize(750, 750);
    //RenderTexture render = LoadRenderTexture(750, 750);

    Vector3 A = {4.f, 2.f, 2.f};
    Vector3 B = {3.f, 2.f, -1.f};
    Vector3 C = {A.x+B.x, A.y+B.y, A.z+B.z};

    float subspace_y = 2.f;

    while (!WindowShouldClose()) {
        cam.UpdateAngles(.05f);
    //for(int i = 0; i < 100; ++i) {
    //    cam.SetXAngle(cam.GetXAngle() + (PI*2)/100);

        Camera3D rl_cam = cam.GetRlCamera();

        Vector2 x_text_pos = GetWorldToScreen({15.f, 0.f, 0.f}, rl_cam);
        Vector2 y_text_pos = GetWorldToScreen({0.f, 15.f, 0.f}, rl_cam);
        Vector2 z_text_pos = GetWorldToScreen({0.f, 0.f, 15.f}, rl_cam);

        Vector2 A_text_pos = GetWorldToScreen(A, rl_cam);
        Vector2 B_text_pos = GetWorldToScreen(B, rl_cam);
        Vector2 C_text_pos = GetWorldToScreen(C, rl_cam);

        Vector2 two_text_pos = GetWorldToScreen({0.f, 2.f, 0.f}, rl_cam);
        Vector2 four_text_pos = GetWorldToScreen({0.f, 4.f, 0.f}, rl_cam);

        //BeginTextureMode(render);
        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode3D(rl_cam);

        // axes
        if(!IsKeyDown(KEY_H)) {
            DrawLine3D({-15.f, 0.f, 0.f}, {15.f, 0.f, 0.f}, WHITE);
            DrawLine3D({0.f, -15.f, 0.f}, {0.f, 15.f, 0.f}, WHITE);
            DrawLine3D({0.f, 0.f, -15.f}, {0.f, 0.f, 15.f}, WHITE);
        }

        // grid
        for(int j = -15; j < 16; ++j) {
            if(abs(j) % 2 == 1) continue;
            DrawLine3D({-15.f, subspace_y, (float)j}, {15.f, subspace_y, (float)j}, {255, 255, 255, 150});
            DrawLine3D({(float)j, subspace_y, -15.f}, {(float)j, subspace_y, 15.f}, {255, 255, 255, 150});
        }

        // In-world elements

        // Points
        DrawSphere(A, .5f, BLUE);
        DrawSphere(B, .5f, BLUE);
        DrawSphere(C, .5f, BLUE);
        DrawLine3D(C, {C.x, subspace_y, C.z}, WHITE);
        DrawLine3D(C, {0.f, C.y, C.z}, WHITE);
        DrawLine3D({0.f, C.y, C.z}, {0.f, 4.f, 0.f}, WHITE);

        //Subspace
        DrawTriangle3DDouble({15.f, subspace_y, 15.f}, {15.f, subspace_y, -15.f}, {-15.f, subspace_y, 15.f}, {255, 0, 0, 150});
        DrawTriangle3DDouble({-15.f, subspace_y, -15.f}, {15.f, subspace_y, -15.f}, {-15.f, subspace_y, 15.f}, {255, 0, 0, 150});

        //DrawTriangle3DDouble({5.f, 0.01f, 5.f}, {5.f, 0.01f, -5.f}, {-5.f, 0.01f, 5.f}, {0, 255, 0, 127});
        //DrawTriangle3DDouble({-5.f, 0.01f, -5.f}, {5.f, 0.01f, -5.f}, {-5.f, 0.01f, 5.f}, {0, 255, 0, 127});

        EndMode3D();

        // Outside-world overlay
        DrawText("x", (int)x_text_pos.x, (int)x_text_pos.y, 20, WHITE);
        DrawText("y", (int)y_text_pos.x, (int)y_text_pos.y, 20, WHITE);
        DrawText("z", (int)z_text_pos.x, (int)z_text_pos.y, 20, WHITE);

        DrawText("2", (int)two_text_pos.x+1, (int)two_text_pos.y+1, 10, WHITE);
        DrawText("4", (int)four_text_pos.x+1, (int)four_text_pos.y+1, 10, WHITE);

        DrawText("A", (int)A_text_pos.x+3, (int)A_text_pos.y+3, 20, WHITE);
        DrawText("B", (int)B_text_pos.x+3, (int)B_text_pos.y+3, 20, WHITE);
        DrawText("A+B", (int)C_text_pos.x+3, (int)C_text_pos.y+3, 20, WHITE);

        DrawText("Move with arrow keys, hold H to hide axes.", 2, GetRenderHeight()-22, 20, WHITE);


        DrawText(
                TextFormat("A = (%f, %f, %f)", A.x, A.y, A.z),
                2, 2, 20, WHITE);
        DrawText(
                TextFormat("B = (%f, %f, %f)", B.x, B.y, B.z),
                2, 24, 20, WHITE);
        DrawText(
                TextFormat("A+B = (%f, %f, %f)", C.x, C.y, C.z),
                2, 46, 20, WHITE);

        //EndTextureMode();
        EndDrawing();

        /* Image img = LoadImageFromTexture(render.texture);
        ImageFlipVertical(&img);
        ExportImage(img, TextFormat("Frame%i.png", i));
        UnloadImage(img); */
    }

    //UnloadRenderTexture(render);
}

void Q2b() {
    OrbitalCamera cam({0.f, 0.f, 0.f}, 50.f);

    cam.SetXAngle(PI/4);
    cam.SetYAngle(PI/12);

    Vector3 A = {1.f, 2.f, 0.f};
    Vector3 B = {5.f, 6.f, 0.f};
    Vector3 C = {10.f, 15.f, 0.f};
    Vector3 D = {3.f, 0.f, 0.f};


    while (!WindowShouldClose()) {
        cam.UpdateAngles(.05f);

    // for(int i = 0; i < 50; ++i) {
    //     cam.SetXAngle(cam.GetXAngle() + (PI*2)/50);

        Camera3D rl_cam = cam.GetRlCamera();

        Vector2 x_text_pos = GetWorldToScreen({15.f, 0.f, 0.f}, rl_cam);
        Vector2 y_text_pos = GetWorldToScreen({0.f, 15.f, 0.f}, rl_cam);
        Vector2 z_text_pos = GetWorldToScreen({0.f, 0.f, 15.f}, rl_cam);

        Vector2 A_text_pos = GetWorldToScreen(A, rl_cam);
        Vector2 B_text_pos = GetWorldToScreen(B, rl_cam);
        Vector2 C_text_pos = GetWorldToScreen(C, rl_cam);
        Vector2 D_text_pos = GetWorldToScreen(D, rl_cam);

        //BeginTextureMode(render);
        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode3D(rl_cam);

        //Axes
        DrawLine3D({-15.f, 0.f, 0.f}, {15.f, 0.f, 0.f}, WHITE);
        DrawLine3D({0.f, -15.f, 0.f}, {0.f, 15.f, 0.f}, WHITE);
        DrawLine3D({0.f, 0.f, -15.f}, {0.f, 0.f, 15.f}, WHITE);

        // grid
        for(int j = -15; j < 16; ++j) {
            if(abs(j) % 2 == 1) continue;
            DrawLine3D({-15.f, (float)j, 0.f}, {15.f, (float)j, 0.f}, {255, 255, 255, 150});
            DrawLine3D({(float)j, -15.f, 0.f}, {(float)j, 15.f, 0.f}, {255, 255, 255, 150});
        }


        //Points
        DrawSphere(A, .5f, BLUE);
        DrawSphere(B, .5f, BLUE);
        DrawSphere(C, .5f, BLUE);
        DrawSphere(D, .5f, BLUE);

        //Subspace
        DrawTriangle3DDouble({15.f, 15.f, 0.f}, {15.f, -15.f, 0.f}, {-15.f, 15.f, 0.f}, {255, 0, 0, 150});
        DrawTriangle3DDouble({-15.f, -15.f, 0.f}, {15.f, -15.f, 0.f}, {-15.f, 15.f, 0.f}, {255, 0, 0, 150});

        EndMode3D();


        DrawText("x", (int)x_text_pos.x, (int)x_text_pos.y, 20, WHITE);
        DrawText("y", (int)y_text_pos.x, (int)y_text_pos.y, 20, WHITE);
        DrawText("z", (int)z_text_pos.x, (int)z_text_pos.y, 20, WHITE);

        DrawText("A", (int)A_text_pos.x+3, (int)A_text_pos.y+3, 20, WHITE);
        DrawText("B", (int)B_text_pos.x+3, (int)B_text_pos.y+3, 20, WHITE);
        DrawText("C", (int)C_text_pos.x+3, (int)C_text_pos.y+3, 20, WHITE);
        DrawText("D", (int)D_text_pos.x+3, (int)D_text_pos.y+3, 20, WHITE);

        DrawText("Move with arrow keys.", 2, GetRenderHeight()-22, 20, WHITE);

        DrawText(
                TextFormat("A = (%f, %f, %f)", A.x, A.y, A.z),
                2, 2, 20, WHITE);
        DrawText(
                TextFormat("B = (%f, %f, %f)", B.x, B.y, B.z),
                2, 24, 20, WHITE);
        DrawText(
                TextFormat("C = (%f, %f, %f)", C.x, C.y, C.z),
                2, 46, 20, WHITE);
        DrawText(
                TextFormat("D = (%f, %f, %f)", D.x, D.y, D.z),
                2, 68, 20, WHITE);

        //EndTextureMode();
        EndDrawing();

        /*Image img = LoadImageFromTexture(render.texture);
        ImageFlipVertical(&img);
        ExportImage(img, TextFormat("Frame%i.png", i));
        UnloadImage(img);*/
    }

    //UnloadRenderTexture(render);
}

void Q2c() {
    OrbitalCamera cam({0.f, 0.f, 0.f}, 50.f);

    cam.SetXAngle(PI/4);
    cam.SetYAngle(PI/12);


    while (!WindowShouldClose()) {
        cam.UpdateAngles(.05f);

        Camera3D rl_cam = cam.GetRlCamera();

        Vector2 x_text_pos = GetWorldToScreen({15.f, 0.f, 0.f}, rl_cam);
        Vector2 y_text_pos = GetWorldToScreen({0.f, 15.f, 0.f}, rl_cam);
        Vector2 z_text_pos = GetWorldToScreen({0.f, 0.f, 15.f}, rl_cam);


        //BeginTextureMode(render);
        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode3D(rl_cam);

        //Axes
        DrawLine3D({-15.f, 0.f, 0.f}, {15.f, 0.f, 0.f}, WHITE);
        DrawLine3D({0.f, -15.f, 0.f}, {0.f, 15.f, 0.f}, WHITE);
        DrawLine3D({0.f, 0.f, -15.f}, {0.f, 0.f, 15.f}, WHITE);

        // grid
        for(int j = -15; j < 16; ++j) {
            if(abs(j) % 2 == 1) continue;
            DrawLine3D({-15.f, (float)j, 0.f}, {15.f, (float)j, 0.f}, {255, 255, 255, 150});
            DrawLine3D({(float)j, -15.f, 0.f}, {(float)j, 15.f, 0.f}, {255, 255, 255, 150});

            DrawLine3D({0.f, (float)j, -15.f}, {0.f, (float)j, 15.f}, {255, 255, 255, 150});
            DrawLine3D({0.f, -15.f, (float)j}, {0.f, 15.f, (float)j}, {255, 255, 255, 150});
        }


        //Subspace
        DrawTriangle3DDouble({15.f, 15.f, 0.f}, {15.f, -15.f, 0.f}, {-15.f, 15.f, 0.f}, {255, 0, 0, 150});
        DrawTriangle3DDouble({-15.f, -15.f, 0.f}, {15.f, -15.f, 0.f}, {-15.f, 15.f, 0.f}, {255, 0, 0, 150});

        DrawTriangle3DDouble({0.f, 15.f, 15.f}, {0.f, -15.f, 15.f}, {0.f, 15.f, -15.f}, {0, 0, 255, 150});
        DrawTriangle3DDouble({0.f, -15.f, -15.f}, {0.f, -15.f, 15.f}, {0.f, 15.f, -15.f}, {0, 0, 255, 150});

        EndMode3D();


        DrawText("x", (int)x_text_pos.x, (int)x_text_pos.y, 20, WHITE);
        DrawText("y", (int)y_text_pos.x, (int)y_text_pos.y, 20, WHITE);
        DrawText("z", (int)z_text_pos.x, (int)z_text_pos.y, 20, WHITE);

        DrawText("E = span( (1,0,0) , (0,1,0) )", 2, 2, 20, RED);
        DrawText("F = span( (0,1,0) , (0,0,1) )", 2, 24, 20, BLUE);


        DrawText("Move with arrow keys.", 2, GetRenderHeight()-22, 20, WHITE);

        EndDrawing();
    }
}
