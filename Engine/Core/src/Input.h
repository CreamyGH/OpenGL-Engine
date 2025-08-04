#pragma once
#include "pch.h"
#include "Helpers/Singleton.h"

#include "KeyCodes.h"
#include "MouseButtonCodes.h"

#include <GLFW/glfw3.h>

namespace Core
{
    class Input : public Singleton<Input>
    {
        friend class Singleton<Input>;

    public:
        void Init(GLFWwindow* window) {
            m_Window = window;
        }

        void Update() {
            m_PreviousKeys = m_CurrentKeys;
            m_PreviousMouseButtons = m_CurrentMouseButtons;

            for (int i = 0; i <= GLFW_KEY_LAST; ++i)
                m_CurrentKeys[i] = glfwGetKey(m_Window, i) == GLFW_PRESS || glfwGetKey(m_Window, i) == GLFW_REPEAT;

            for (int i = 0; i <= GLFW_MOUSE_BUTTON_LAST; ++i)
                m_CurrentMouseButtons[i] = glfwGetMouseButton(m_Window, i) == GLFW_PRESS;

            double x, y;
            glfwGetCursorPos(m_Window, &x, &y);
            m_MouseX = static_cast<float>(x);
            m_MouseY = static_cast<float>(y);
        }

        bool IsKeyDown(int keycode) {
            return m_CurrentKeys[keycode];
        }
        bool IsKeyPressed(int keycode) {
            return m_CurrentKeys[keycode] && !m_PreviousKeys[keycode];
        }
        bool IsKeyReleased(int keycode) {
            return !m_CurrentKeys[keycode] && m_PreviousKeys[keycode];
        }

        bool IsMouseButtonDown(int button) {
            return m_CurrentMouseButtons[button];
        }
        bool IsMouseButtonPressed(int button) {
            return m_CurrentMouseButtons[button] && !m_PreviousMouseButtons[button];
        }
        bool IsMouseButtonReleased(int button) {
            return !m_CurrentMouseButtons[button] && m_PreviousMouseButtons[button];
        }

        std::pair<float, float> GetMousePosition() {
            return { m_MouseX, m_MouseY };
        }
        float GetMouseX() { return m_MouseX; }
        float GetMouseY() { return m_MouseY; }

    private:
        GLFWwindow* m_Window = nullptr;

        std::array<bool, GLFW_KEY_LAST + 1> m_CurrentKeys{};
        std::array<bool, GLFW_KEY_LAST + 1> m_PreviousKeys{};

        std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1> m_CurrentMouseButtons{};
        std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1> m_PreviousMouseButtons{};

        float m_MouseX = 0.0f, m_MouseY = 0.0f;
    };
}