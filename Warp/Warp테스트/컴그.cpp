#include "pch.h"
#include "CFramework.h"
#include "CShaderManager.h"

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);
GLvoid Keyboard(unsigned char key, int x, int y);

CFramework* g_mainGame;

void main(int argc, char** argv)
{
	glutInit(&argc, argv); // glut 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // 디스플레이 모드 설정
	glutInitWindowPosition(100, 100); // 윈도우의 위치 지정
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); // 윈도우의 크기 지정
	glutCreateWindow("스터디"); // 윈도우 생성
	glEnable(GL_CULL_FACE);
	
	//--- GLEW 초기화하기
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) // glew 초기화
	{
		std::cerr << "Unable to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
		std::cout << "GLEW Initialized\n";

	g_mainGame = new CFramework;
	CShaderManager::GetInstance()->
		AddShader(SHADER_TYPE::DEFAULT,
			"vertex.glsl", "fragment.glsl");

	CShaderManager::GetInstance()->AddShader(SHADER_TYPE::BOUNDING_BOX, "boundingVertex.glsl", "fragment.glsl");

	glutDisplayFunc(drawScene);
	glutIdleFunc(drawScene);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();

	delete g_mainGame;
}
GLvoid drawScene() 
{
	g_mainGame->Update();
	g_mainGame->Render();
}
GLvoid Reshape(int w, int h) 
{
	glViewport(0, 0, w, h);
}

GLvoid Keyboard(unsigned char key, int x, int y)
{
	g_mainGame->Keyboard(key, x, y);
}
