#include "player.h"

Player::Player()
{
    const float scr_width = GetScreenWidth();
    const float scr_height = GetScreenHeight();

    texture = LoadTexture("assets/player.png");
    player_pos.x = 5 * 40 ;
    player_pos.y = 6 * 40 ;
    velocity = {0 , 0};
    is_on_ground = false;

    camera = {0};
    camera.target = (Vector2){player_pos.x + 20.00f , player_pos.y + 20.00f};
    camera.offset = (Vector2){scr_width / 2.00f , scr_height / 2.00f};
    camera.rotation = 0.00f;
    camera.zoom = 1.00f;
}

Player::~Player()
{
    UnloadTexture(texture);
}

void Player::Draw()
{
    DrawRectangleRec(GetPlayerRect(), RED);
    DrawTextureV(texture , player_pos , WHITE);
}

Rectangle Player::GetPlayerRect()
{
    return {player_pos.x , player_pos.y , 40 , 40 };
}

void Player::Update()
{
    if (player_pos.y > 1000) // abyss depth
    {
    player_pos = (Vector2){ 5 * 40, 6 * 40 }; // respawn point
    velocity = (Vector2){ 0, 0 };
    }
    if(IsKeyDown(KEY_A))
        player_pos.x -= 4;
    if(IsKeyDown(KEY_D))
        player_pos.x += 4;
    if(IsKeyPressed(KEY_L))
        camera.zoom += 1.00f;
    if(IsKeyPressed(KEY_M))
        camera.zoom -= 0.10f;


    velocity.y += gravity;
    player_pos.y += velocity.y;
}

void Player::CheckCollisionWithObjects(Rectangle platform)
{
    
    Rectangle playerRect = GetPlayerRect();
    camera.target = (Vector2){ player_pos.x + 20, player_pos.y + 20 };


    // Check if the player is falling downwards and collides with the platform
    if (CheckCollisionRecs(playerRect, platform) && velocity.y > 0)
    {
        player_pos.y = platform.y - playerRect.height;
        velocity.y = 0;
        is_on_ground = true;
    }
    else
    {
        is_on_ground = false;
    }

    if(is_on_ground && IsKeyPressed(KEY_SPACE))
    {
        velocity.y = jumpForce;
        is_on_ground = false;
    }
}