# ♟️ Terminal Chess — C++ / SFML Project

A complete, fully functional **terminal-based chess game** written in modern **C++17**, featuring:

- Local practice mode
- AI mode (minimax + alpha-beta pruning)
- Multiplayer mode (TCP over SFML)
- Colored ANSI terminal graphics
- Customizable color themes
- Full piece logic (castling, en passant, promotion, checkmate detection)

The project uses **SFML (2.6.1)** only for networking.  
All rendering is done through **Windows Console VT sequences**.

---

## 📁 Project Structure

Chess Game Project/
│
├── Utility/
│ ├── utils.h
│ └── utils.cpp
│
├── Entities/
│ ├── Piece.h / Piece.cpp
│ ├── Cell.h
│ ├── Board.h / Board.cpp
│
├── Menus/
│ ├── MainMenu.h / MainMenu.cpp
│ ├── Options.h / Options.cpp
│ ├── Game.h / Game.cpp
│ ├── AIGame.h / AIGame.cpp
│ ├── MultGame.h / MultGame.cpp
│ └── PracGame.h / PracGame.cpp
│
├── Chess.cpp ← Main entry point
└── Build/ ← Executable output (created locally)

---

## 🖥️ Requirements

### Windows (Recommended)

- **MinGW-w64** or **TDM-GCC 10.3.0**
- **SFML-2.6.1 (Windows, 64-bit)**
- A terminal that supports VT ANSI colors (Windows 10+)

> ✔ Linux support is possible but some Windows-specific console functions must be adapted.

---

## ⚙️ How to Build (Using g++)

### 1. Install SFML 2.6.1
Download from:  
https://www.sfml-dev.org/download.php

Extract to:  C:\SFML-2.6.1\

(If located elsewhere, update the include & lib paths.)

---

### 2. Build the project

Navigate to the project folder in a terminal:


Then run:

```sh
g++ -g Utility/utils.cpp \
Entities/*.cpp \
Menus/*.cpp \
Chess.cpp \
-o Build/Chess.exe \
-I C:/SFML-2.6.1/include \
-L C:/SFML-2.6.1/lib \
-DSFML_STATIC \
-lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-network-s -lsfml-system-s \
-lwinmm -lgdi32 -lopengl32 -lws2_32 -lfreetype -lopenal32 -lflac \
-lvorbisenc -lvorbisfile -lvorbis -logg \
-static-libgcc -static-libstdc++
```

If everything compiles, run:
```sh
Build\Chess.exe
```



❤️ Author

ASCII Chess created by Saurabh Pal...

