# C++ 德州扑克服务端架构

仓库采用多个服务及业务模块组织代码。Tars 文件定义接口，Server 文件负责服务入口，ServantImp 和业务类承载具体处理。

## 可见模块

- 登录：`LoginServer`、`LoginServantImp`、`LoginProto.tars`
- 订单：`OrderServer`、`OrderServant.tars`
- 用户：`userinfo`、`getuserinfo`、`userconfig`
- 牌局：`gamestation`、`Processor`
- 座位：`sitdown`、`standup`
- 公共支持：`Define.h`、`OuterFactoryImp`、`LogComm.h`

## 二次开发建议

先绘制“请求 → Servant → 业务处理 → 状态更新 → 响应”的调用图。将网络协议、牌局状态机、持久化和日志分离，并为状态转换建立测试。架构描述应与实际代码保持一致，不要写入仓库中不存在的服务。

