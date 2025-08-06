[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org)
[![WinUI 3](https://img.shields.io/badge/Framework-WinUI%203-blueviolet.svg)](https://docs.microsoft.com/windows/apps/winui/)

<p align="center">
<img width="2237" height="540" alt="Снимок экрана 2025-08-06 190929" src="https://github.com/user-attachments/assets/3b3884fc-5047-4c98-b106-d3853372e419" />
</p>

## 🚀 AIDA64-WinUI3

\*A modern system monitoring tool built with **WinUI 3** and **C++/WinRT*, featuring a sleek interface and extensible design.*

---

## ✨ Features

* 🖥️ **Real-time Monitoring:** CPU, GPU, Memory, Disk, Network
* 🎨 **Customizable Themes:** Light, Dark, and Accent Colors
* 🤖 **AI Assistant:** Integrated chatbot for diagnostics and tips
* 🔌 **Plugin Architecture:** Easily extend functionality
* 📦 **Modular Codebase:** Clean separation of concerns

---

## 📝 Overview

This project provides a clean, responsive interface inspired by AIDA64, built using **WinUI 3** and **C++/WinRT**. It targets Windows 10 (1903+) and Windows 11, offering deep insights into system performance with smooth animations and theming support.

It leverages **Windows Management Instrumentation (WMI)** as the **core data provider**, ensuring access to detailed system information such as CPU load, memory usage, GPU stats, and hardware sensors.

> ⚠️ **Early Alpha:** This is a very early-stage prototype. Many features and code components will be refined or rewritten in upcoming releases (if I'm not lazy 😉).

---

## 📑 Pages

| Page             | Description                                     |
| ---------------- | ----------------------------------------------- |
| **CPU**          | Core usage, frequencies, temperatures           |
| **Memory**       | RAM usage, swap activity, available capacity    |
| **Display**      | Resolution, refresh rate, color profiles        |
| **AI Assistant** | Chatbot helper for troubleshooting              |
| **Settings**     | Themes, update channels, performance thresholds |

---

## 📸 Screenshots

<p align="center">
  <img width="1940" height="1250" alt="Снимок экрана 2025-08-06 191201" src="https://github.com/user-attachments/assets/66da5e0c-e302-4832-8cd7-9341a8419c61" width="45%"/>
  <img width="1939" height="1281" alt="Снимок экрана 2025-08-06 191135" src="https://github.com/user-attachments/assets/3e68c191-6946-4230-ae1b-9c2b63f3b103" width="45%"/>
  <img width="1941" height="1299" alt="Снимок экрана 2025-08-06 191107" src="https://github.com/user-attachments/assets/5d1f24dd-471d-4d57-90b1-a21d73583843" width="45%"/>
</p>

---

## 🏁 Getting Started

### Prerequisites

* **Windows 10** (1903+) / **Windows 11**
* **Visual Studio 2022** with **C++/WinRT**, **WinUI 3**, and **NuGet** workloads

### Installation

```bash
git clone https://github.com/hellodda/AIDA64.git
cd AIDA64
# Restore NuGet packages
nuget restore
# Open solution
enable-winui3-solution WinUIAIDA64.sln
# Build & Run in Visual Studio
```

---

## 💡 Usage

1. Launch **AIDA64** from Visual Studio or the built executable.
2. Select a page from the sidebar to view system metrics.
3. Open **Settings** to customize themes and update preferences.
4. Chat with the **AI Assistant** for quick diagnostics and tips.

---


1. Fork the repo
2. `git checkout -b feature/YourFeature`
3. \`git commit -m "feat: Add Feature"
4. `git push origin feature/YourFeature`
5. Open a **Pull Request**


---

## 🗺️ Roadmap & Future Plans

Below is a sneak peek of our development roadmap. 📈

All of the pages and features shown above will be implemented in upcoming releases:

<p align="center">
  <img width="1933" height="1223" alt="Снимок экрана 2025-08-06 191544" src="https://github.com/user-attachments/assets/dc981574-00c8-4ca9-9214-0b91eb33ca3b" />
</p>

---

