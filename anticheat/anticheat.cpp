#include "include/anticheat.h"
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

bool AntiCheat::DetectAndKillCheat(const char* processName) {
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);

    PROCESSENTRY32W pEntry{};
    pEntry.dwSize = sizeof(pEntry);
    BOOL hRes = Process32FirstW(hSnapShot, &pEntry);

    while (hRes) {
        char szExeFileAnsi[MAX_PATH];
        WideCharToMultiByte(CP_ACP, 0, pEntry.szExeFile, -1, szExeFileAnsi, sizeof(szExeFileAnsi), NULL, NULL);

        if (strcmp(szExeFileAnsi, processName) == 0) {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0, pEntry.th32ProcessID);
            if (hProcess) {
                if (TerminateProcess(hProcess, 9)) {
                    CloseHandle(hProcess);
                    CloseHandle(hSnapShot);
                    return true;
                }
                CloseHandle(hProcess);
            }
        }
        hRes = Process32NextW(hSnapShot, &pEntry);
    }
    CloseHandle(hSnapShot);
    return false;
}

void AntiCheat::MonitorForCheat() {
    std::cout << "AntiCheat iniciado..." << std::endl;
    while (true) {
        Sleep(1000);
        if (DetectAndKillCheat("cheat.exe")) {
            std::cout << "'cheat.exe' detectado e encerrado!" << std::endl;
        }
    }
}

int main() {
    AntiCheat::MonitorForCheat();
    return 0;
}
