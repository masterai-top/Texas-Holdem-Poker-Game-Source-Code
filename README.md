[简体中文](README.md) | [繁體中文](README.zh-TW.md) | [English](README.en.md)

# 德州扑克游戏源码：大厅、俱乐部、联盟与锦标赛系统

这是以 **Jinbei 俱乐部**真实产品为基础的德州扑克游戏源码项目。仓库公开内容以 C++ 服务端、Tars 协议、牌局状态逻辑和产品演示资源为主，产品形态覆盖德州大厅、俱乐部、好友桌/私人局、联盟、金币大厅、SNG 与 MTT 锦标赛。适合评估多人扑克服务端架构、牌局流程、赛事系统和二次开发方案。

> 仓库是否包含可直接上线的客户端、数据库、运营后台及商业部署组件，请以实际目录与授权说明为准。本文只描述线上代码和截图能够验证的内容。

## 产品截图

| 德州大厅 | 俱乐部 | 9 人牌桌 |
|---|---|---|
| ![德州扑克大厅源码产品界面](docs/Assets/Screenshots/dating.jpg) | ![德州俱乐部与联盟产品界面](docs/Assets/Screenshots/julebu.jpg) | ![德州扑克九人桌游戏界面](docs/Assets/Screenshots/9ren.jpg) |

| 创建房间/好友局 | 实时聊天 | 账号与账单 |
|---|---|---|
| ![创建德州朋友局房间](docs/Assets/Screenshots/chuangjian.jpg) | ![牌桌实时聊天系统](docs/Assets/Screenshots/chat.jpg) | ![玩家账号账单界面](docs/Assets/Screenshots/zhangdan.jpg) |

## 产品功能

- **大厅与房间入口**：玩家从大厅查看桌局和赛事入口，进入不同玩法与房间；大厅截图可验证真实产品结构。
- **俱乐部与联盟**：支持俱乐部列表、俱乐部详情、成员场景及联盟型运营结构；适合朋友局、私人局与多俱乐部组织。
- **好友桌/私人房**：通过创建房间组织固定玩家对局，适用于熟人娱乐和内部赛事场景。
- **赛事系统**：涵盖 SNG 和 MTT 两类赛事形态，支持从赛事入口、报名到多桌竞赛的产品流程。
- **用户与订单模块**：仓库包含用户信息、查询用户以及订单服务的协议和实现入口。
- **实时交互**：产品截图展示牌桌聊天、设置及账户相关页面；牌局代码包含坐下、站起与游戏状态处理。

## 八种玩法

1. **经典德州扑克**：公共牌、下注轮次和标准 Texas Hold'em 桌局体验。
2. **AOF**：All-in or Fold 快节奏模式，缩短单局决策链路。
3. **6+ 短牌**：Short Deck 使用精简牌组的德州变体。
4. **SNG**：人数满足后开赛的 Sit and Go 单桌或小型赛事。
5. **MTT**：多桌锦标赛，面向德州比赛、德州赛事和锦标赛场景。
6. **德州牛仔**：产品中的特色扩展玩法。
7. **奥马哈**：Omaha Poker 多底牌玩法入口。
8. **大菠萝**：Open Face Chinese Poker 玩法入口。

## 典型使用流程

玩家登录后进入德州大厅，选择金币大厅、俱乐部或赛事入口；普通桌可查看房间并坐下，好友局可先创建房间再邀请玩家；赛事玩家选择 SNG 或 MTT，完成报名后进入对应牌桌。服务端通过协议接收请求，执行业务处理和状态变化，再向客户端返回结果。实际支付、结算、反作弊和运营规则应结合完整授权组件及部署环境审计。

## 技术与源码结构

项目可见技术资产包括 **C++、Makefile、Tars 接口定义和 Unity 资源目录**。主要代码入口：

```text
LoginProto.tars / LoginServant.tars / LoginServantImp.cpp / LoginServer.cpp
    登录协议、服务接口、实现与服务入口
OrderServant.tars / OrderServer.cpp
    订单接口与服务入口
gamestation.cpp / Processor.cpp
    牌局状态与业务处理
sitdown.cpp / standup.cpp
    玩家入座和离桌流程
userinfo.cpp / getuserinfo.cpp
    用户信息相关逻辑
Proto/ / u3d/ / Screenshots/ / docs/
    协议、客户端资源、真实截图和技术文档
```

构建前请检查 `makefile` 中的编译器、头文件、链接库和目标环境，并准备匹配版本的 Tars/C++ 依赖。不要假设仓库下载后无需环境配置即可生产部署。

## 在线专题文档

- [德州扑克源码与代码模块](https://masterai-top.github.io/Texas-Holdem-Poker-Game-Source-Code/zh-cn/texas-holdem-source-code.html)
- [德州大厅源码与玩家流程](https://masterai-top.github.io/Texas-Holdem-Poker-Game-Source-Code/zh-cn/poker-lobby-source-code.html)
- [德州联盟与俱乐部系统](https://masterai-top.github.io/Texas-Holdem-Poker-Game-Source-Code/zh-cn/poker-alliance-system.html)
- [德州比赛、MTT 与锦标赛源码](https://masterai-top.github.io/Texas-Holdem-Poker-Game-Source-Code/zh-cn/poker-tournament-source-code.html)
- [English product overview](https://masterai-top.github.io/Texas-Holdem-Poker-Game-Source-Code/en/texas-holdem-source-code.html)

## 下载、演示与使用

```bash
git clone https://github.com/masterai-top/Texas-Holdem-Poker-Game-Source-Code.git
cd Texas-Holdem-Poker-Game-Source-Code
```

- [完整产品演示视频](https://youtu.be/job2jRcSnl4?si=p3AjN6trak3jStfc)
- [构建准备](docs/build-guide.md) · [服务端架构](docs/server-architecture.md) · [协议指南](docs/protocol-guide.md)
- [牌局流程](docs/game-flow.md) · [安全与合规](docs/security-compliance.md) · [常见问题](docs/faq.md)

## 合规与授权

扑克软件在不同地区可能受到游戏、竞赛、支付、年龄和数据保护法规约束。部署或商业使用前应核对许可证、第三方资产授权、随机数与牌局日志、隐私安全及当地法律。严禁用于违法活动。开源范围以 [LICENSE](LICENSE) 为准。

联系：Telegram `@xuzongbin001` · Email `masterai918@gmail.com` · [GitHub Issues](https://github.com/masterai-top/Texas-Holdem-Poker-Game-Source-Code/issues)
