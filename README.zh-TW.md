[簡體中文](README.md) | **繁體中文** | [English](README.en.md)

# 德州撲克遊戲原始碼：大廳、俱樂部、聯盟與錦標賽系統

这是以 **Jinbei 俱樂部**真实產品为基础的德州撲克遊戲原始碼项目。仓库公开内容以 C++ 伺服器端、Tars 协议、牌局状态逻辑和產品演示资源为主，產品形态覆盖德州大廳、俱樂部、好友桌/私人局、聯盟、金币大廳、SNG 与 MTT 錦標賽。适合评估多人扑克伺服器端架构、牌局流程、赛事系统和二次開發方案。

> 仓库是否包含可直接上线的客户端、資料库、运营后台及商业部署组件，请以实际目錄与授权說明为准。本文只描述线上程式碼和截图能够验证的内容。

## 產品截图

| 德州大廳 | 俱樂部 | 9 人牌桌 |
|---|---|---|
| ![德州撲克大廳原始碼產品界面](docs/Assets/Screenshots/dating.jpg) | ![德州俱樂部与聯盟產品界面](docs/Assets/Screenshots/julebu.jpg) | ![德州撲克九人桌遊戲界面](docs/Assets/Screenshots/9ren.jpg) |

| 建立房间/好友局 | 实时聊天 | 帳號与账单 |
|---|---|---|
| ![建立德州朋友局房间](docs/Assets/Screenshots/chuangjian.jpg) | ![牌桌实时聊天系统](docs/Assets/Screenshots/chat.jpg) | ![玩家帳號账单界面](docs/Assets/Screenshots/zhangdan.jpg) |

## 產品功能

- **大廳与房间入口**：玩家从大廳查看桌局和赛事入口，進入不同玩法与房间；大廳截图可验证真实產品结构。
- **俱樂部与聯盟**：支持俱樂部列表、俱樂部详情、成员情境及聯盟型运营结构；适合朋友局、私人局与多俱樂部组织。
- **好友桌/私人房**：通过建立房间组织固定玩家对局，适用于熟人娱乐和内部赛事情境。
- **赛事系统**：涵盖 SNG 和 MTT 两类赛事形态，支持从赛事入口、报名到多桌竞赛的產品流程。
- **使用者与订单模块**：仓库包含使用者信息、查詢使用者以及订单服务的协议和實作入口。
- **实时交互**：產品截图展示牌桌聊天、设置及账户相關页面；牌局程式碼包含坐下、站起与遊戲状态处理。

## 八种玩法

1. **经典德州撲克**：公共牌、下注轮次和标准 Texas Hold'em 桌局体验。
2. **AOF**：All-in or Fold 快节奏模式，缩短单局决策链路。
3. **6+ 短牌**：Short Deck 使用精简牌组的德州变体。
4. **SNG**：人数满足后开赛的 Sit and Go 单桌或小型赛事。
5. **MTT**：多桌錦標賽，面向德州比赛、德州赛事和錦標賽情境。
6. **德州牛仔**：產品中的特色扩展玩法。
7. **奥马哈**：Omaha Poker 多底牌玩法入口。
8. **大菠萝**：Open Face Chinese Poker 玩法入口。

## 典型使用流程

玩家登录后進入德州大廳，選擇金币大廳、俱樂部或赛事入口；普通桌可查看房间并坐下，好友局可先建立房间再邀请玩家；赛事玩家選擇 SNG 或 MTT，完成报名后進入对应牌桌。伺服器端通过协议接收请求，执行业务处理和状态变化，再向客户端返回结果。实际付款、结算、反作弊和运营规则应结合完整授权组件及部署環境审计。

## 技術与原始碼结构

项目可见技術資產包括 **C++、Makefile、Tars 介面定义和 Unity 资源目錄**。主要程式碼入口：

```text
LoginProto.tars / LoginServant.tars / LoginServantImp.cpp / LoginServer.cpp
    登录协议、服务介面、實作与服务入口
OrderServant.tars / OrderServer.cpp
    订单介面与服务入口
gamestation.cpp / Processor.cpp
    牌局状态与业务处理
sitdown.cpp / standup.cpp
    玩家入座和离桌流程
userinfo.cpp / getuserinfo.cpp
    使用者信息相關逻辑
Proto/ / u3d/ / Screenshots/ / docs/
    协议、客户端资源、真实截图和技術文档
```

建置前请检查 `makefile` 中的编译器、头檔案、链接库和目标環境，并准备匹配版本的 Tars/C++ 依赖。不要假设仓库下載后无需環境設定即可生产部署。

## 線上专题文档

- [德州撲克原始碼与程式碼模块](https://masterai-top.github.io/Texas-Holdem-Poker-Game-Source-Code/zh-cn/texas-holdem-source-code.html)
- [德州大廳原始碼与玩家流程](https://masterai-top.github.io/Texas-Holdem-Poker-Game-Source-Code/zh-cn/poker-lobby-source-code.html)
- [德州聯盟与俱樂部系统](https://masterai-top.github.io/Texas-Holdem-Poker-Game-Source-Code/zh-cn/poker-alliance-system.html)
- [德州比赛、MTT 与錦標賽原始碼](https://masterai-top.github.io/Texas-Holdem-Poker-Game-Source-Code/zh-cn/poker-tournament-source-code.html)
- [English product overview](https://masterai-top.github.io/Texas-Holdem-Poker-Game-Source-Code/en/texas-holdem-source-code.html)

## 下載、演示与使用

```bash
git clone https://github.com/masterai-top/Texas-Holdem-Poker-Game-Source-Code.git
cd Texas-Holdem-Poker-Game-Source-Code
```

- [完整產品演示视频](https://youtu.be/job2jRcSnl4?si=p3AjN6trak3jStfc)
- [建置准备](docs/build-guide.md) · [伺服器端架构](docs/server-architecture.md) · [协议指南](docs/protocol-guide.md)
- [牌局流程](docs/game-flow.md) · [安全与合规](docs/security-compliance.md) · [常见问题](docs/faq.md)

## 合规与授权

扑克软件在不同地區可能受到遊戲、竞赛、付款、年龄和資料保护法规约束。部署或商业使用前应核对许可证、第三方資產授权、随机数与牌局日志、隐私安全及当地法律。严禁用于违法活动。开源范围以 [LICENSE](LICENSE) 为准。

聯絡：Telegram `@xuzongbin001` · Email `masterai918@gmail.com` · [GitHub Issues](https://github.com/masterai-top/Texas-Holdem-Poker-Game-Source-Code/issues)
