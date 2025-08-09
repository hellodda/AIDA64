[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org)
[![WinUI 3](https://img.shields.io/badge/Framework-WinUI%203-blueviolet.svg)](https://docs.microsoft.com/windows/apps/winui/)

<p align="center">
  <img width="2227" height="828" alt="Снимок экрана 2025-08-09 225906" src="https://github.com/user-attachments/assets/d8a1efdd-042b-4f6c-b881-e87ea09308dc" />
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
  <img width="2126" height="1291" alt="Снимок экрана 2025-08-09 225942" src="https://github.com/user-attachments/assets/355d8c0c-8f5b-4eb8-97a9-93951969cfb2" width="45%"/>
  <img width="2091" height="1275" alt="Снимок экрана 2025-08-09 230020" src="https://github.com/user-attachments/assets/d44d49bf-2bd9-4487-af13-b12e720df507" width="45%"/>
  <img width="2108" height="1252" alt="Снимок экрана 2025-08-09 230044" src="https://github.com/user-attachments/assets/ecfe8016-0141-4f43-96f8-7c4d057063cc" width="45%"/>
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

## 🗺️ Roadmap & Future Plans

Below is a sneak peek of our development roadmap. 📈

All of the pages and features shown above will be implemented in upcoming releases:

<p align="center">
  <img width="1933" height="1223" alt="Снимок экрана 2025-08-06 191544" src="https://github.com/user-attachments/assets/dc981574-00c8-4ca9-9214-0b91eb33ca3b" />
</p>

---

