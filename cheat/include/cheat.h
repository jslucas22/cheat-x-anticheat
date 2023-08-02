#ifndef CHEAT_H
#define CHEAT_H

#include <Windows.h>

namespace Cheat {
    void SendKeyPressToNotepad();
    DWORD FindNotepadProcessId();
    HWND FindNotepadWindowByProcessId(DWORD processId);
}

#endif
