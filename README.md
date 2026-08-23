# 德州扑克源码：C++ Texas Hold'em 游戏服务端

[![Language](https://img.shields.io/badge/language-C%2B%2B-00599c?logo=cplusplus)](https://github.com/masterai-top/Texas-Holdem-Poker-Game-Source-Code)
[![Stars](https://img.shields.io/github/stars/masterai-top/Texas-Holdem-Poker-Game-Source-Code?style=flat)](https://github.com/masterai-top/Texas-Holdem-Poker-Game-Source-Code/stargazers)
[![License](https://img.shields.io/github/license/masterai-top/Texas-Holdem-Poker-Game-Source-Code)](./LICENSE)

这是一个以 C++ 编写的德州扑克源码项目，仓库包含游戏服务端、登录服务、订单服务、用户信息、坐下/站起、牌局状态及 Tars 协议等代码，可用于学习多人扑克游戏的服务端结构、通信协议和牌局业务流程。

**English:** C++ Texas Hold'em poker server source code with game-session, login, order, user and Tars protocol modules.

> 当前公开仓库以服务端代码、协议文件和演示资源为主。是否包含客户端、数据库脚本、管理后台及商业部署组件，请以实际目录和授权说明为准。

## 项目内容

- C++ 德州扑克游戏服务端代码
- 登录服务与用户信息模块
- 牌桌坐下、站起及牌局状态处理
- 订单相关服务接口
- Tars 协议定义与服务实现
- Makefile 编译入口
- 产品截图和演示视频资源

## 源码目录

```text
.
|-- Bag/                    # 相关代码与资源目录
|-- Screenshots/            # 产品截图
|-- Video/                  # 演示视频资源
|-- LoginProto.tars         # 登录协议定义
|-- LoginServant.tars       # 登录服务接口
|-- LoginServantImp.cpp     # 登录服务实现
|-- LoginServer.cpp         # 登录服务入口
|-- OrderServant.tars       # 订单服务接口
|-- OrderServer.cpp         # 订单服务入口
|-- gamestation.cpp         # 牌局状态相关逻辑
|-- sitdown.cpp             # 坐下流程
|-- standup.cpp             # 站起流程
|-- userinfo.cpp            # 用户信息逻辑
|-- Processor.cpp           # 业务处理模块
|-- makefile                # 编译配置
`-- LICENSE                 # 许可证
```

## 快速下载

### Download ZIP

点击仓库页面右上方 **Code → Download ZIP** 下载德州扑克源码。

### Git 克隆

```bash
git clone https://github.com/masterai-top/Texas-Holdem-Poker-Game-Source-Code.git
cd Texas-Holdem-Poker-Game-Source-Code
```

## 构建前准备

该项目包含 C++、Makefile 和 Tars 协议文件。构建前请检查 `makefile` 中配置的编译器、头文件目录、链接库和目标环境，并准备与源码版本匹配的 Tars/C++ 依赖。

```bash
make
```

不同服务器环境的依赖路径可能不同，不能保证下载后无需配置即可完成编译。建议先阅读：

- [`docs/build-guide.md`](./docs/build-guide.md)
- [`docs/server-architecture.md`](./docs/server-architecture.md)
- [`docs/protocol-guide.md`](./docs/protocol-guide.md)

## 核心模块

### 登录服务

`LoginProto.tars`、`LoginServant.tars`、`LoginServantImp.cpp` 和 `LoginServer.cpp` 构成登录协议与服务实现的主要入口。

### 牌局流程

`gamestation.cpp`、`sitdown.cpp`、`standup.cpp` 和 `Processor.cpp` 等文件负责牌局状态及相关业务处理。阅读时建议从协议输入、状态变化和响应输出三个方向梳理调用关系。

### 用户与订单

`userinfo.cpp`、`getuserinfo.cpp` 以及 `OrderServant.tars`、`OrderServer.cpp` 等文件提供用户信息和订单相关代码入口。

## 截图与视频

真实界面图片保存在 [`Screenshots`](./Screenshots) 目录，视频资源保存在 [`Video`](./Video) 目录。

演示视频：[Texas Hold'em Poker Demo](https://youtu.be/job2jRcSnl4)

建议在 README 首屏只展示 3 至 5 张清晰截图，并为图片添加准确的中文说明，例如“德州扑克九人桌界面”“俱乐部牌局列表”，不要继续使用“微信图片”等无意义图片名称。

## 适用场景

- 学习 C++ 多人游戏服务端架构
- 研究德州扑克牌局状态与用户流程
- 阅读 Tars 接口和服务实现
- 制作扑克游戏服务器原型
- 为已有项目补充协议、测试和文档

## 使用与合规说明

扑克软件可能受到不同国家或地区关于游戏、竞赛、支付和数据保护的法律限制。部署或商业使用前，请确认：

- 仓库许可证与商业授权范围
- 第三方代码、图片、音频和字体的许可证
- 所在地区对扑克软件和虚拟货币的规定
- 用户年龄、隐私、支付和数据安全要求
- 服务端随机数、牌局日志和反作弊机制是否经过审计

严禁将本项目用于违法活动。

## 文档导航

- [德州扑克源码说明](./docs/texas-holdem-source-code.md)
- [C++ 游戏服务端架构](./docs/server-architecture.md)
- [构建与部署准备](./docs/build-guide.md)
- [Tars 协议阅读指南](./docs/protocol-guide.md)
- [牌局流程与状态管理](./docs/game-flow.md)
- [安全、随机数与合规](./docs/security-compliance.md)
- [常见问题](./docs/faq.md)

## 参与贡献

欢迎通过 Issue 或 Pull Request 提交编译修复、协议说明、测试案例、文档和安全改进。报告问题时，请提供操作系统、编译器版本、依赖版本、执行命令及完整错误信息。

## 许可证与联系

开源使用范围以 [`LICENSE`](./LICENSE) 为准。商业授权、完整组件范围和部署支持应在使用前单独确认。

- Issues：<https://github.com/masterai-top/Texas-Holdem-Poker-Game-Source-Code/issues>
- Telegram：`@xuzongbin001`
- Email：`masterai918@gmail.com`

关键词：德州源码、德州扑克源码、C++ 扑克游戏服务端、Texas Hold'em source code、poker server、multiplayer poker game。





## ✨ 核心特性

- **丰富玩法支持**：经典德州扑克、Short Deck (6+短牌)、Omaha、AOF 快牌、SNG 单桌赛、MTT 多桌锦标赛、朋友局、私人局、金币场
- **完整俱乐部与代理系统**：俱乐部创建、管理、自定义规则与抽水、排行榜、专属房间、代理分润、联盟模式
- **高性能实时服务器**：C++ 服务端 + WebSocket/TCP 双协议，支持断线重连、毫秒级同步
- **客户端框架**：Cocos Creator / Unity（轻松编译多平台）
- **后台管理面板**：完整运营后台，支持用户、牌局、财务、风控管理
- **实测性能**：支持 10,000+ 并发玩家，亚洲区平均延迟 50-80ms
- **部署方式**：Docker / Kubernetes / 云服务器均可，支持 CDN 加速
- **安全风控**：服务端防作弊验证、TLS 加密、DDoS 防护、日志监控
- **全套资源**：高清 UI 素材、音效、动画、牌型判断引擎等

##📞 问题反馈与交流

- Telegram：@xuzongbin001  
- Email：masterai918@gmail.com  



## 🚀 产品演示视频（强烈推荐观看）

[![德州扑克完整功能演示](https://youtu.be/job2jRcSnl4?si=p3AjN6trak3jStfc)](https://youtu.be/job2jRcSnl4?si=p3AjN6trak3jStfc)

**德州扑克完整功能演示视频**  
金币大厅 + 俱乐部系统 + 多锦标赛 + 短牌玩法 + 实时对战

视频时长约 10分钟，展示了系统的核心功能流程。
点击上方图片直接跳转 YouTube 播放。
## 📸 界面展示,真实产品演示：

![微信图片_20241029191811 - 副本](https://github.com/user-attachments/assets/31da98f9-d812-4501-9756-d7e9efe08f12)
![优化-9人桌](https://github.com/user-attachments/assets/1dc7be3e-eee3-4bfb-98ef-27b428bcc3fa)
![微信图片_20241031110830](https://github.com/user-attachments/assets/af9ed4cc-a4fb-4901-a96b-3b3cf7abaaf1)
![微信图片_20241031110826](https://github.com/user-attachments/assets/fc8b80b7-7732-4a70-9ff3-99e3c6004db5)
![微信图片_20241031110821](https://github.com/user-attachments/assets/cac8a5e5-7898-45c2-ad19-0be183961f00)
![微信图片_20241031110816](https://github.com/user-attachments/assets/1d991a2f-1315-4a2d-932d-57002f0d36d8)
![微信图片_20241029191842](https://github.com/user-attachments/assets/c5b8c91f-4eaa-4391-a6b8-f3ac17a0003c)
![微信图片_20241029191835](https://github.com/user-attachments/assets/5ac3245e-d395-4837-b347-dcffd94daf14)
![微信图片_20241029191822](https://github.com/user-attachments/assets/50a898dc-2e69-471b-9022-cc18eb7b5f69)
![微信图片_20241029191811 - 副本](https://github.com/user-attachments/assets/ac84cd0c-6eea-4009-ad63-2bcb574847cb)

---
![Stars](https://img.shields.io/github/stars/masterai-top/Texas-Holdem-Poker-Game-Source-Code-Online-AI-Multiplayer-?style=social)
![Last Update](https://img.shields.io/github/last-commit/masterai-top/Texas-Holdem-Poker-Game-Source-Code-Online-AI-Multiplayer-)



## 🚀 快速开始


# 1. 克隆项目
git clone https://github.com/masterai-top/Texas-Holdem-Poker-Game-Source-Code.git
cd Texas-Holdem-Poker-Game-Source-Code

# 2. 服务器编译与启动（C++ 服务端）
# 请参考 docs/Server_Deployment.md 详细步骤

# 3. 客户端运行
# 打开 client 目录（Unity 或 Cocos Creator）
# 修改服务器 IP/端口 → 编译运行
详细部署文档、数据库初始化、配置说明请查看 docs/ 文件夹。
##🛠 技术栈

服务端：C++（高性能核心） + Tars / 自有协议
客户端：Unity / Cocos Creator
数据库：MySQL + Redis（实时牌局缓存）
通信协议：WebSocket + TCP
其他：Docker 支持、多语言、多端适配

##💡 为什么选择我们？

代码成熟稳定，非简单 Demo，可直接商业上线或深度定制
完整俱乐部 + 金币 + 联盟体系，商业价值高
提供全套美术资源 + 后台面板，大幅降低开发成本


##📜 许可说明
本项目代码仅供学习、研究和二次开发参考。




## 💼 Monetization and Business Model | 盈利模式

- **SaaS Deployment**: Offer the poker game engine as a service, allowing businesses to launch their own online poker platforms.
- **White-label Solution**: Provide a fully customizable version of the game that can be branded and tailored to specific business needs.
- **API Integration**: Allow other platforms to integrate poker games via API for multiplayer interaction.

Perfect for online casinos, gaming companies, and social gaming platforms.

Star 支持一下项目，让我们一起把这个德州扑克源码做得更好！


德州扑克源码、德州扑克游戏源码、德州俱乐部源码、德州金币大厅源码、德州朋友局源码、MTT 德州赛事源码、SNG 德州、短牌德州、AOF 德州、德州扑克服务器源码、在线多人德州扑克、poker source code、texas holdem source code、poker club system、texas holdem multiplayer game







