#pragma once

#define _USE_MATH_DEFINES
#include <glm/gtc/constants.inl>
#include <math.h>

// ========== MODEL CONSTANTS ==========


// **** SKYBOX ****
static constexpr char SKY_TOP[] = "resources/top.jpg";
static constexpr char SKY_BOTTOM[] = "resources/bottom.jpg";
static constexpr char SKY_FRONT[] = "resources/front.jpg";
static constexpr char SKY_BACK[] = "resources/back.jpg";
static constexpr char SKY_LEFT[] = "resources/left.jpg";
static constexpr char SKY_RIGHT[] = "resources/right.jpg";


// **** CAMERA ****
static constexpr GLfloat CAMERA_X = -13.1f;
static constexpr GLfloat CAMERA_Y = 9.2f;
static constexpr GLfloat CAMERA_Z = 23.3f;
static constexpr GLfloat CAMERA_YAW = -57.46f;
static constexpr GLfloat CAMERA_PITCH = -16.5f;


// **** SUN ****
static constexpr GLfloat SUN_X = -125.0f;
static constexpr GLfloat SUN_Y = 150.0f;
static constexpr GLfloat SUN_Z = 20.0f;
static constexpr GLfloat SUN_INTENSITY = 0.8f;
static constexpr GLfloat SUN_AMBIENT_R = 0.5f;
static constexpr GLfloat SUN_AMBIENT_G = 0.5f;
static constexpr GLfloat SUN_AMBIENT_B = 0.5f;
static constexpr GLfloat SUN_DIFFUSE_R = 0.5f;
static constexpr GLfloat SUN_DIFFUSE_G = 0.5f;
static constexpr GLfloat SUN_DIFFUSE_B = 0.4f;
static constexpr GLfloat SUN_SPECULAR_R = 0.8f;
static constexpr GLfloat SUN_SPECULAR_G = 0.8f;
static constexpr GLfloat SUN_SPECULAR_B = 0.7f;


// **** LAMP ****
static constexpr GLfloat LAMP_X = 2.5f;
static constexpr GLfloat LAMP_Y = 4.2f;
static constexpr GLfloat LAMP_Z = 0.0f;
static constexpr GLfloat LAMP_INTENSITY = 0.65f;
static constexpr GLfloat LAMP_AMBIENT_R = 0.0f;
static constexpr GLfloat LAMP_AMBIENT_G = 0.0f;
static constexpr GLfloat LAMP_AMBIENT_B = 0.0f;
static constexpr GLfloat LAMP_DIFFUSE_R = 1.0f;
static constexpr GLfloat LAMP_DIFFUSE_G = 0.7f;
static constexpr GLfloat LAMP_DIFFUSE_B = 0.0f;
static constexpr GLfloat LAMP_SPECULAR_R = 0.6f;
static constexpr GLfloat LAMP_SPECULAR_G = 0.6f;
static constexpr GLfloat LAMP_SPECULAR_B = 0.6f;
static constexpr GLfloat LAMP_ATTENUATION_CONSTANT = 1.0f;
static constexpr GLfloat LAMP_ATTENUATION_LINEAR = 0.14f;
static constexpr GLfloat LAMP_ATTENUATION_QUADRATIC = 0.07f;


// **** BASE ****
static constexpr GLfloat BASE_WIDTH = 20.0f;
static constexpr GLfloat BASE_HEIGHT = 1.0f;
static constexpr GLfloat BASE_DEPTH = 30.0f;
static constexpr char BASE_TEXTURE[] = "resources/concrete.jpg";
static constexpr GLfloat BASE_SHININESS = 32.0f;
static constexpr GLfloat BASE_SPECULAR_R = 0.3f;
static constexpr GLfloat BASE_SPECULAR_G = 0.3f;
static constexpr GLfloat BASE_SPECULAR_B = 0.3f;


// **** FRAME ****
static constexpr char FRAME_TEXTURE[] = "resources/frame.jpg";
static constexpr GLfloat FRAME_X = 0.0f;
static constexpr GLfloat FRAME_Y = 4.0f;
static constexpr GLfloat FRAME_Z = 0.0f;
static constexpr GLfloat FRAME_WIDTH = 12.0f;
static constexpr GLfloat FRAME_HEIGHT = 7.4f;
static constexpr GLfloat FRAME_DEPTH = 3.0f;
static constexpr GLfloat FRAME_THICKNESS = 1.65f;
// frame support:
static constexpr GLfloat FRAME_SUPPORT_WIDTH = FRAME_THICKNESS;
static constexpr GLfloat FRAME_SUPPORT_HEIGHT = FRAME_HEIGHT - FRAME_THICKNESS;
static constexpr GLfloat FRAME_SUPPORT_DEPTH = FRAME_DEPTH;
static constexpr GLfloat FRAME_SUPPORT_X_OFFSET = 0.5f * (FRAME_WIDTH - FRAME_THICKNESS);
static constexpr GLfloat FRAME_SUPPORT_Y_OFFSET = 0.5f * FRAME_THICKNESS;
// frame left support:
static constexpr GLfloat FRAME_LEFT_SUPPORT_X = FRAME_X - FRAME_SUPPORT_X_OFFSET;
static constexpr GLfloat FRAME_LEFT_SUPPORT_Y = FRAME_Y - FRAME_SUPPORT_Y_OFFSET;
static constexpr GLfloat FRAME_LEFT_SUPPORT_Z = FRAME_Z;
// frame right support:
static constexpr GLfloat FRAME_RIGHT_SUPPORT_X = FRAME_X + FRAME_SUPPORT_X_OFFSET;
static constexpr GLfloat FRAME_RIGHT_SUPPORT_Y = FRAME_Y - FRAME_SUPPORT_Y_OFFSET;
static constexpr GLfloat FRAME_RIGHT_SUPPORT_Z = FRAME_Z;
// frame top part:
static constexpr GLfloat FRAME_TOP_WIDTH = FRAME_WIDTH;
static constexpr GLfloat FRAME_TOP_HEIGHT = FRAME_THICKNESS;
static constexpr GLfloat FRAME_TOP_DEPTH = FRAME_DEPTH;
static constexpr GLfloat FRAME_TOP_X = FRAME_X;
static constexpr GLfloat FRAME_TOP_Y = FRAME_Y + 0.5f * (FRAME_HEIGHT - FRAME_THICKNESS);
static constexpr GLfloat FRAME_TOP_Z = FRAME_Z;


// **** CONVEYOR BELT ****
static constexpr GLfloat CONVEYOR_BELT_WIDTH = 6.0f;
static constexpr GLfloat CONVEYOR_BELT_HEIGHT = 1.0f;
static constexpr GLfloat CONVEYOR_BELT_DEPTH = 20.0f;
static constexpr GLfloat CONVEYOR_BELT_X = 0.0f;
static constexpr GLfloat CONVEYOR_BELT_Y = 1.5f;
static constexpr GLfloat CONVEYOR_BELT_Z = 0.0f;
static constexpr GLfloat BELT_PERCENTAGE = 0.85f;
static constexpr GLfloat BELT_SHININESS = 32.0f;
static constexpr GLfloat BELT_SPECULAR_R = 0.1f;
static constexpr GLfloat BELT_SPECULAR_G = 0.1f;
static constexpr GLfloat BELT_SPECULAR_B = 0.1f;
// belt corner:
static constexpr char BELT_CORNER_TEXTURE[] = "resources/belt_corner.jpg";
static constexpr GLfloat BELT_CORNER_RADIUS = 0.5f * CONVEYOR_BELT_HEIGHT;
static constexpr GLfloat BELT_CORNER_HEIGHT = CONVEYOR_BELT_WIDTH * BELT_PERCENTAGE;
static constexpr GLuint BELT_CORNER_SEGMENTS = 40;
static constexpr GLfloat BELT_CORNER_PITCH = 0.0f;
static constexpr GLfloat BELT_CORNER_YAW = 90.0f;
static constexpr GLfloat BELT_CORNER_ROLL = 0.0f;
static constexpr GLfloat BELT_CORNER_Z_OFFSET = 0.5f * CONVEYOR_BELT_DEPTH - BELT_CORNER_RADIUS;
// belt front corner:
static constexpr GLfloat BELT_CORNER_FRONT_X = CONVEYOR_BELT_X;
static constexpr GLfloat BELT_CORNER_FRONT_Y = CONVEYOR_BELT_Y;
static constexpr GLfloat BELT_CORNER_FRONT_Z = CONVEYOR_BELT_Z + BELT_CORNER_Z_OFFSET;
// belt back corner:
static constexpr GLfloat BELT_CORNER_BACK_X = CONVEYOR_BELT_X;
static constexpr GLfloat BELT_CORNER_BACK_Y = CONVEYOR_BELT_Y;
static constexpr GLfloat BELT_CORNER_BACK_Z = CONVEYOR_BELT_Z - BELT_CORNER_Z_OFFSET;
// belt:
static constexpr char BELT_TEXTURE[] = "resources/belt.jpg";
static constexpr GLfloat BELT_WIDTH = CONVEYOR_BELT_DEPTH - 2 * BELT_CORNER_RADIUS;
static constexpr GLfloat BELT_HEIGHT = CONVEYOR_BELT_WIDTH * BELT_PERCENTAGE;
static constexpr GLfloat BELT_PITCH = 90.0f;
static constexpr GLfloat BELT_YAW = 90.0f;
static constexpr GLfloat BELT_ROLL = 0.0f;
static constexpr GLfloat BELT_Y_OFFSET = BELT_CORNER_RADIUS;
// belt top:
static constexpr GLfloat BELT_TOP_X = CONVEYOR_BELT_X;
static constexpr GLfloat BELT_TOP_Y = CONVEYOR_BELT_Y + BELT_Y_OFFSET;
static constexpr GLfloat BELT_TOP_Z = CONVEYOR_BELT_Z;
// belt bottom:
static constexpr GLfloat BELT_BOTTOM_X = CONVEYOR_BELT_X;
static constexpr GLfloat BELT_BOTTOM_Y = CONVEYOR_BELT_Y - BELT_Y_OFFSET;
static constexpr GLfloat BELT_BOTTOM_Z = CONVEYOR_BELT_Z;
// pulley:
static constexpr char PULLEY_TEXTURE[] = "resources/pulley.jpg";
static constexpr GLfloat PULLEY_SHININESS = 8.0f;
static constexpr GLfloat PULLEY_SPECULAR_R = 0.1f;
static constexpr GLfloat PULLEY_SPECULAR_G = 0.1f;
static constexpr GLfloat PULLEY_SPECULAR_B = 0.1f;
static constexpr GLfloat PULLEY_SCALE = 0.999f;
static constexpr GLfloat PULLEY_RADIUS = BELT_CORNER_RADIUS * PULLEY_SCALE;
static constexpr GLfloat PULLEY_HEIGHT = BELT_CORNER_HEIGHT / BELT_PERCENTAGE;
static constexpr GLuint PULLEY_SEGMENTS = BELT_CORNER_SEGMENTS;
static constexpr GLfloat PULLEY_PITCH = BELT_CORNER_PITCH;
static constexpr GLfloat PULLEY_YAW = BELT_CORNER_YAW;
static constexpr GLfloat PULLEY_ROLL = BELT_CORNER_ROLL;
static constexpr GLfloat PULLEY_Z_OFFSET = 0.01f;
// front pulley:
static constexpr GLfloat PULLEY_FRONT_X = BELT_CORNER_FRONT_X;
static constexpr GLfloat PULLEY_FRONT_Y = BELT_CORNER_FRONT_Y;
static constexpr GLfloat PULLEY_FRONT_Z = BELT_CORNER_FRONT_Z - PULLEY_Z_OFFSET;
// back pulley:
static constexpr GLfloat PULLEY_BACK_X = BELT_CORNER_BACK_X;
static constexpr GLfloat PULLEY_BACK_Y = BELT_CORNER_BACK_Y;
static constexpr GLfloat PULLEY_BACK_Z = BELT_CORNER_BACK_Z + PULLEY_Z_OFFSET;


// **** PRESS CYLINDER ****
static constexpr char CYLINDER_TEXTURE[] = "resources/cylinder.jpg";
static constexpr GLfloat CYLINDER_RADIUS = 1.0f;
static constexpr GLfloat CYLINDER_HEIGHT = 4.0f;
static constexpr GLuint CYLINDER_SEGMENTS = 32;
static constexpr GLfloat CYLINDER_X = 0.0f;
static constexpr GLfloat CYLINDER_Y = 5.69f;
static constexpr GLfloat CYLINDER_Z = 0.0f;
static constexpr GLfloat CYLINDER_YAW = 0.0f;
static constexpr GLfloat CYLINDER_PITCH = -90.0f;
static constexpr GLfloat CYLINDER_ROLL = 0.0f;
static constexpr GLfloat CYLINDER_SHININESS = 8.0f;
static constexpr GLfloat CYLINDER_SPECULAR_R = 0.5f;
static constexpr GLfloat CYLINDER_SPECULAR_G = 0.5f;
static constexpr GLfloat CYLINDER_SPECULAR_B = 0.5f;


// **** CANS ****
static constexpr char CAN_TEXTURE[] = "resources/ebe_ebe.jpg";
static constexpr GLfloat CAN_SHININESS = 32.0f;
static constexpr GLfloat CAN_SPECULAR_R = 1.0f;
static constexpr GLfloat CAN_SPECULAR_G = 1.0f;
static constexpr GLfloat CAN_SPECULAR_B = 1.0f;
static constexpr GLfloat CAN_RADIUS = 0.35f;
static constexpr GLfloat CAN_HEIGHT = 1.5f;
static constexpr GLuint CAN_SEGMENTS = 32;
static constexpr GLfloat CAN_X = 0.0f;
static constexpr GLfloat CAN_Y = 2.01f + CAN_HEIGHT / 2;
static constexpr GLfloat CAN_Z = -7.6f;
static constexpr GLfloat CAN_YAW = 0.0f;
static constexpr GLfloat CAN_PITCH = -90.0f;
static constexpr GLfloat CAN_ROLL = 0.0f;
// crushed cans:
static constexpr GLfloat CRUSHED_CAN_RADIUS = CAN_RADIUS;
static constexpr GLuint CRUSHED_CAN_SEGMENTS = CAN_SEGMENTS;
static constexpr GLfloat CRUSHED_CAN_HEIGHT = 0.1f;
static constexpr GLfloat CRUSHED_CAN_X = CAN_X;
static constexpr GLfloat CRUSHED_CAN_Y = CAN_Y + 0.5f * (CRUSHED_CAN_HEIGHT - CAN_HEIGHT);
static constexpr GLfloat CRUSHED_CAN_Z = 0.0f;
static constexpr GLfloat CRUSHED_CAN_YAW = CAN_YAW;
static constexpr GLfloat CRUSHED_CAN_PITCH = CAN_PITCH;
static constexpr GLfloat CRUSHED_CAN_ROLL = CAN_ROLL;



// ========== ANIMATION CONSTANTS ==========

// **** CONVEYOR BELT ****
static constexpr GLfloat BELT_PERIOD = 10.0f;
static constexpr GLfloat PULLEY_PERIOD = 2.0f * static_cast<GLfloat>(M_PI) * BELT_CORNER_RADIUS / BELT_WIDTH * BELT_PERIOD;


// **** PRESS CYLINDER ****
static constexpr GLfloat CYLINDER_PERIOD = 4.0f;
static constexpr GLfloat CYLINDER_PUSH_TIMESTAMP = 2.7f;
static constexpr GLfloat CYLINDER_STOP_TIMESTAMP = 3.0f;
static constexpr GLfloat CYLINDER_RELEASE_TIMESTAMP = 3.25f;
static constexpr GLfloat CYLINDER_Y_SHIFT = -1.6f;


// **** CANS ****
static constexpr GLfloat CAN_Y_SHIFT = 3.0f;
static constexpr GLfloat CAN_Z_SHIFT = -CAN_Z;
static constexpr GLfloat CAN_ON_GROUND_TIMESTAMP = 2.0f;
static constexpr GLfloat CAN_UNDER_CYLINDER_TIMESTAMP = 6.0f;
static constexpr GLfloat CAN_INVISIBLE_TIMESTAMP = 6.01f;
static constexpr GLfloat CAN_PERIOD = 8.0f;
// crushed cans:
static constexpr GLfloat CRUSHED_CAN_Y_SHIFT = -1.5f;
static constexpr GLfloat CRUSHED_CAN_Z_SHIFT = BELT_WIDTH / 2.0f;
static constexpr GLfloat CRUSHED_CAN_PERIOD = CAN_PERIOD;
static constexpr GLfloat CRUSHED_CAN_AT_EDGE_TIMESTAMP = 5.0f;
static constexpr GLfloat CRUSHED_CAN_FALL_TIME = 1.0f;
static constexpr GLint FALL_TIME_RESOLUTION = 10;
static constexpr GLfloat CRUSHED_CAN_FALL_PITCH = 60.0f;
