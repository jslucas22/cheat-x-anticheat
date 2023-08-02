#ifndef ANTICHEAT_H
#define ANTICHEAT_H

namespace AntiCheat {
    bool DetectAndKillCheat(const char* processName);
    void MonitorForCheat();
}

#endif
