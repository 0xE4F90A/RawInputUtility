//--------------------------------------------------------------------------------------
// File: RawInput.h
//
// ToolKit for RawInputAPI
//
// Copyright (c) 0xE4F90A. All rights reserved.
// Licensed under the MIT License.
//-------------------------------------------------------------------------------------

#ifndef _RAWINPUT_H_
#define _RAWINPUT_H_

// RawInputClass
class RawInputClass
{
public:
    explicit RawInputClass(HWND hwnd);
    virtual ~RawInputClass() = default;

    virtual void RegisterDevices() = 0;
    virtual void ProcessRawInput(LPARAM lParam) = 0;

protected:
    HWND m_hwnd;
};

// Keyboard
class Keyboard : public RawInputClass
{
public:
    explicit Keyboard(HWND hwnd);

    void RegisterDevices() override;

    void ProcessRawInput(LPARAM lParam) override;

    void SetKeyboardCallback(std::function<void(const RAWKEYBOARD&)> callback);

    const wchar_t* ShowMaouCode();

private:
    void HandleKeyboard(RAWINPUT* raw);

    std::function<void(const RAWKEYBOARD&)> m_keyboardCallback;
    std::wstring m_lastKey;
};

// Mouse
class Mouse : public RawInputClass
{
public:
    explicit Mouse(HWND hwnd);

    void RegisterDevices() override;

    void ProcessRawInput(LPARAM lParam) override;

    void SetMouseCallback(std::function<void(const RAWMOUSE&)> callback);

    const char* ShowMaouCode();

private:
    void HandleMouse(RAWINPUT* raw);

    std::function<void(const RAWMOUSE&)> m_mouseCallback;
    std::string m_lastEvent;
    POINT m_absolutePosition;
    bool m_mouseAbsolute;
};

#endif // _RAWINPUT_H_
