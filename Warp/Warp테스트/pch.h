#pragma once
#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>
#include <memory>
#include <vector>	//크기가 정해지지않은 배열
#include <queue>
#include <unordered_map>	//key를 통해서 hash - 값에 접근 
#include <string>
#include <assert.h>
#include <array>
#include <chrono>

using namespace std;
using namespace std::chrono;

#include"MathUtil.h"

#define DIR_FORWARD 0x01
#define DIR_BACKWARD 0x02
#define DIR_LEFT 0x04
#define DIR_RIGHT 0x08
#define FIRE_BULLET 0x10

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 800;

inline bool IsfloatEqual(float a, float b)
{
	if (abs(a - b) <= FLT_EPSILON)	//abs : 절댓값해주능거
		return true;
	return false;
}

enum class OBJ_TYPE { START, PLAYER, ENEMY, BULLET, END };

enum class SHADER_TYPE { DEFAULT, BOUNDING_BOX };