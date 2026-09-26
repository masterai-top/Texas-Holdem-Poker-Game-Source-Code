[简体中文](README.md) | [繁體中文](README.zh-TW.md) | **English**

# Texas Hold'em Poker Game Source Code: Lobby, Clubs, Leagues and Tournaments

This repository presents a real **Jinbei Club** Texas Hold'em product and its visible source assets. The public repository focuses on C++ server code, Tars protocols, game-state logic and product media. Its documented product scope includes a poker lobby, clubs, private friend tables, club leagues, a coin lobby, SNG and MTT tournaments, plus eight poker variants. It is useful for evaluating multiplayer poker architecture, table flows, tournament design and secondary development.

> Availability of a production-ready client, database, admin console or commercial deployment package must be confirmed from the actual repository and license. This document only describes code and screenshots that can be verified online.

## Real product screenshots

| Poker lobby | Club area | 9-seat table |
|---|---|---|
| ![Texas Holdem poker lobby source code interface](docs/Assets/Screenshots/dating.jpg) | ![Poker club and league interface](docs/Assets/Screenshots/julebu.jpg) | ![Nine seat Texas Holdem table](docs/Assets/Screenshots/9ren.jpg) |

| Create a friend table | Table chat | Account and ledger |
|---|---|---|
| ![Create a private poker room](docs/Assets/Screenshots/chuangjian.jpg) | ![Real-time poker table chat](docs/Assets/Screenshots/chat.jpg) | ![Player account ledger](docs/Assets/Screenshots/zhangdan.jpg) |

## Product capabilities

- **Lobby and room discovery:** players browse cash-game, club and tournament entrances before joining a table.
- **Clubs and leagues:** club lists, club pages and multi-club organization support private communities and friend games.
- **Private friend tables:** room creation supports invited-player sessions and internal events.
- **Tournament system:** SNG and MTT product flows cover tournament discovery, registration and multi-table play.
- **User and order services:** the repository exposes user-information code and order-service protocol/entry points.
- **Real-time table interaction:** screenshots show chat, settings and account views; server files expose sit-down, stand-up and game-state handling.

## Eight documented game modes

1. **Classic Texas Hold'em** with community cards and standard betting rounds.
2. **AOF (All-in or Fold)** for short, high-tempo decisions.
3. **6+ Short Deck** using a reduced deck.
4. **SNG** events that start when the required field is ready.
5. **MTT** multi-table tournaments for scheduled competition.
6. **Cowboy Hold'em**, a documented product variant.
7. **Omaha Poker** with multiple hole cards.
8. **Open Face Chinese Poker**, shown as the Pineapple mode.

## Typical player and server flow

A player signs in, enters the lobby and chooses a cash table, club or tournament. Standard tables allow room discovery and seating; a friend game starts with room creation and invitations; SNG/MTT players register and then enter their assigned tables. Tars protocol requests reach the C++ services, business processors apply state transitions, and results return to the client. Payment, settlement, anti-cheat and operations rules require separate review against the complete licensed deployment.

## Technology and source layout

Visible assets include **C++, Makefile, Tars interface definitions and a Unity resource directory**:

```text
LoginProto.tars / LoginServant.tars / LoginServantImp.cpp / LoginServer.cpp
    Login protocol, interface, implementation and service entry
OrderServant.tars / OrderServer.cpp
    Order interface and service entry
gamestation.cpp / Processor.cpp
    Game-state and business processing
sitdown.cpp / standup.cpp
    Player seating and leaving flows
userinfo.cpp / getuserinfo.cpp
    User information logic
Proto/ / u3d/ / Screenshots/ / docs/
    Protocols, client assets, real screenshots and documentation
```

Before building, verify compiler flags, include paths, linked libraries and target environment in `makefile`, then install matching C++/Tars dependencies. Do not assume the repository is production-ready without configuration and security review.

## Product and technical pages

- [Texas Hold'em source code](https://masterai-top.github.io/Texas-Holdem-Poker-Game-Source-Code/en/texas-holdem-source-code.html)
- [Poker lobby and tournament platform](https://masterai-top.github.io/Texas-Holdem-Poker-Game-Source-Code/en/poker-lobby-tournament-platform.html)
- [Simplified Chinese lobby source page](https://masterai-top.github.io/Texas-Holdem-Poker-Game-Source-Code/zh-cn/poker-lobby-source-code.html)
- [Simplified Chinese tournament source page](https://masterai-top.github.io/Texas-Holdem-Poker-Game-Source-Code/zh-cn/poker-tournament-source-code.html)

## Download, demo and documentation

```bash
git clone https://github.com/masterai-top/Texas-Holdem-Poker-Game-Source-Code.git
cd Texas-Holdem-Poker-Game-Source-Code
```

- [Full product demo](https://youtu.be/job2jRcSnl4?si=p3AjN6trak3jStfc)
- [Build guide](docs/build-guide.md) · [Server architecture](docs/server-architecture.md) · [Protocol guide](docs/protocol-guide.md)
- [Game flow](docs/game-flow.md) · [Security and compliance](docs/security-compliance.md) · [FAQ](docs/faq.md)

## License and responsible use

Poker software may be regulated by gaming, competition, payment, age and privacy laws. Before deployment, verify the repository license, third-party assets, random-number and game-log controls, data security and local law. Illegal use is prohibited. Open-source use is governed by [LICENSE](LICENSE).

Contact: Telegram `@xuzongbin001` · Email `masterai918@gmail.com` · [GitHub Issues](https://github.com/masterai-top/Texas-Holdem-Poker-Game-Source-Code/issues)
