# Cheat vs. AntiCheat: A Dummy Example

This repository houses the source code for a basic demonstration of a "cheat" software and an "anticheat" software. It's designed to serve as a simple example of their interaction and functionality.

## 📁 Project Structure

The project adopts a modular organization, with distinct directories for the cheat and the anticheat, both housed under the `src` directory.

📂 src/
│
├─ 📂 cheat/
│   ├── 📂 include/
│   │   └─ 📄 cheat.h
│   └─ 📄 cheat.cpp
│
└─ 📂 anticheat/
    ├── 📂 include/
    │   └─ 📄 anticheat.h
    └─ 📄 anticheat.cpp

## 🎮 Cheat Module

The "cheat" module consists of functions and methods tailored for cheating in a given application. The specifics of the functions and their implementations can be found in the associated source files.

### Compilation and Usage

```bash
# Navigate to the cheat directory
cd src/cheat/

# Compile (adjust the command as needed)
g++ -o cheat cheat.cpp
```

## 🛡 AntiCheat Module

The "anticheat" module is crafted to detect and potentially thwart the use of the "cheat" software. Similar to the "cheat" module, the function details can be perused in the source files.

### Compilation and Usage
```bash
# Navigate to the anticheat directory
cd src/anticheat/

# Compile (adjust the command as needed)
g++ -o anticheat anticheat.cpp
```

## ⚠️ Note

This project is purely illustrative and is not intended for actual gaming or security use cases. It's simply a dummy example to provide a basic understanding of how cheat and anticheat systems might interact.

## 🤝 Contributions
Feel free to contribute to this project. If you encounter issues or have enhancement suggestions, please open an issue or submit a pull request.