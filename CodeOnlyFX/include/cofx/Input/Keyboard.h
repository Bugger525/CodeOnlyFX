#pragma once

struct GLFWwindow;

namespace co
{
	// �Է� ���� ������� ������ �ִ� �κ��ε�, ���� ���� �ڵ� �ϴ� ���� �Ұ����ұ�?
	class Keyboard
	{
	public:
		Keyboard() = delete;

		static void Initialize(GLFWwindow* window);

		static bool IsKeyHeld();
		static bool IsKeyPressed();
		static bool IsKeyReleased();
	};
}