# E1Recorder - 搜狗E1录音笔应用程序

## 项目简介

E1Recorder是专为搜狗E1录音设备开发的现代化录音应用程序，采用Qt6/QML技术栈构建，支持ARM64交叉编译。

## 主要特性

- 🎙️ **高质量录音** - 基于Qt6 Multimedia的专业录音功能
- 💾 **智能存储管理** - 自动文件管理、存储监控、空间优化
- ⌨️ **硬件按键支持** - 完整的物理按键映射和事件处理
- 🎨 **现代化UI** - Material Design 3深色主题，320x320小屏优化
- ⚙️ **灵活配置** - 录音质量、格式、时长等多项可调参数
- 🔄 **交叉编译** - 支持ARM64目标平台的交叉编译

## 技术架构

### 后端模块 (C++)
- **StorageManager** - 存储和配置管理
- **AudioRecorder** - 音频录制功能
- **HardwareKeyManager** - 硬件按键处理
- **Recorder** - 底层录音实现

### 前端界面 (QML)
- **录音页面** - 主要录音控制和状态显示
- **文件页面** - 录音文件管理和操作
- **设置页面** - 应用程序配置界面

## 构建要求

### 系统依赖
- Qt6 (Core, Quick, QML, Multimedia)
- CMake 3.14+
- GCC/G++ 11+
- ALSA开发库 (用于音频)

### Ubuntu/Debian 安装依赖
```bash
sudo apt update
sudo apt install -y qt6-declarative-dev qt6-multimedia-dev \
    qml6-module-qtquick-controls qml6-module-qtquick-layouts \
    cmake build-essential libasound2-dev
```

## 构建方法

### 本地构建 (x86_64)
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

### ARM64交叉编译
```bash
mkdir build-arm64 && cd build-arm64
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain-arm64.cmake ..
make -j$(nproc)
```

## 运行方法

### 本地运行
```bash
cd build
./E1Recorder
```

### 在E1设备上运行
1. 将编译好的可执行文件复制到E1设备
2. 确保E1设备上有Qt6运行时库
3. 运行程序

## 项目结构

```
E1Recorder/
├── src/                    # C++源代码
│   ├── storagemanager.*    # 存储管理
│   ├── audiorecorder.*     # 录音功能
│   └── hardwarekeymanager.*# 按键管理
├── qml/                    # QML界面文件
│   ├── Main.qml           # 主窗口
│   ├── ModernRecordingScreen.qml  # 录音页面
│   ├── FileListScreen.qml # 文件管理页面
│   └── DeviceSettingsScenarioPage.qml # 设置页面
├── resources/              # 资源文件
├── recorder/               # 底层录音模块
├── CMakeLists.txt         # 构建配置
├── main.cpp              # 程序入口
└── toolchain-arm64.cmake # ARM64工具链
```

## 硬件按键映射

| 物理按键 | 功能 | 说明 |
|---------|------|------|
| 录音键 | 开始/暂停录音 | 智能切换录音状态 |
| 停止键 | 停止录音并保存 | 自动保存到指定目录 |
| 标记键 | 添加书签/转写 | 短按书签，长按转写 |
| 音量+/- | 音量控制 | 系统音量调节 |
| 电源键 | 屏幕/电源控制 | 短按屏幕，长按关机 |

## 开发计划

- [ ] 完善硬件按键集成
- [ ] 添加音频播放功能
- [ ] 支持更多录音格式 (MP3, FLAC)
- [ ] 实现音频波形显示
- [ ] 添加云同步功能
- [ ] 语音转文字集成

## 贡献指南

欢迎提交Issue和Pull Request！请确保：
1. 遵循现有代码风格
2. 添加必要的测试
3. 更新相关文档

## 许可证

本项目采用开源许可证，具体待定。

## 联系方式

- 项目主页: https://github.com/Hermes-Language/Armbian_E1
- 问题反馈: GitHub Issues

---

*为搜狗E1录音设备打造的专业录音解决方案* 🎵 