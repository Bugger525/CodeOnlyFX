#pragma once

struct GLFWwindow;

namespace co
{
	// �Է� ���� ������� ������ �ִ� �κ��ε�, ���� ���� �ڵ� �ϴ� ���� �Ұ����ұ�?
	class Keyboard
	{
	private:
		Keyboard();
	public:
		static bool IsKeyHeld();
		static bool IsKeyPressed();
		static bool IsKeyReleased();
	};
}