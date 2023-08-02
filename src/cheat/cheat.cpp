#include "include/cheat.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <tlhelp32.h>

struct EnumData {
    DWORD processID;
    HWND hWnd;
};

BOOL CALLBACK EnumWindowsByProcessId(HWND hwnd, LPARAM lParam) {
    EnumData& data = *(EnumData*)lParam;
    DWORD processID = 0;
    GetWindowThreadProcessId(hwnd, &processID);
    if (data.processID == processID) {
        data.hWnd = hwnd; 

        return FALSE; 
    }
    return TRUE;
}

DWORD Cheat::FindNotepadProcessId() {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return 0; 
    }

    PROCESSENTRY32W pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32W);

    WCHAR szExeFileWide[MAX_PATH];

    if (!Process32FirstW(hSnapshot, &pe32)) {
        CloseHandle(hSnapshot);
        return 0; 
    }

    do {
        if (_wcsicmp(pe32.szExeFile, L"Notepad.exe") == 0) {
            wprintf(L"Encontrado Notepad com PID: %lu\n", pe32.th32ProcessID);
            CloseHandle(hSnapshot);
            return pe32.th32ProcessID;
        }
    } while (Process32NextW(hSnapshot, &pe32));

    CloseHandle(hSnapshot);
    return 0;
}

HWND Cheat::FindNotepadWindowByProcessId(DWORD processId) {
    EnumData data = { processId, NULL };
    EnumWindows(EnumWindowsByProcessId, (LPARAM)&data);
    return data.hWnd; 
}

void Cheat::SendKeyPressToNotepad() {
    DWORD notepadProcessId = FindNotepadProcessId();
    HWND notepad = FindNotepadWindowByProcessId(notepadProcessId);

    if (notepad) {
        std::cout << "Bloco de Notas encontrado. Enviando as teclas 'U', 'G' e 'A'..." << std::endl;
        SetForegroundWindow(notepad);
        
        keybd_event('U', 0, 0, 0); 
        keybd_event('G', 0, 0, 0); 
        keybd_event('A', 0, 0, 0); 

        keybd_event('U', 0, KEYEVENTF_KEYUP, 0);
        keybd_event('G', 0, KEYEVENTF_KEYUP, 0);
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0);
    }
    else {
        std::cout << "Bloco de Notas nao encontrado." << std::endl;
    }
}

int main() {
    while (true) { 
        Cheat::SendKeyPressToNotepad();
        
        Sleep(1000);

        if (GetAsyncKeyState(VK_ESCAPE)) {
            break;
        }
    }
    return 0;
}
