#include "common/macros.h"
#include "common/nndef.h"
#include "common/nnlogic.h"
#include "gameroot.h"
#include "logic/clientlogic/core/gamestation.h"
#include "utils/tarslog.h"
#include "context/context.h"
#include "config/gameconfig.h"
#include "suoha.pb.h"
#include "process/process.h"
#include "message/sendclientmessage.h"
#include "message/sendroommessage.h"
#include "logic/gamelogic/core/endtimer.h"
#include "CommonCode.pb.h"
#include "logic/gamelogic/core/checkbegin.h"

using namespace nndef;

namespace game
{
    namespace logic
    {
        namespace clientlogic
        {
            void BuBi(long uid, const vector<char> &vecMsgData, GameRoot *root)
            {
                PERFSTATS_ENTRY();
                __TRY__
                using namespace RoomSo;
                using namespace context;
                using namespace process;
                using namespace config;
                using namespace message;
                using namespace nnlogic;
                using namespace gamelogic;

                XGameSHProto::SH_msg2csBuBi shcm4 = pbToObj<XGameSHProto::SH_msg2csBuBi>(vecMsgData);
                DLOG_TRACE("roomid:" << root->roomid() << ",bubi. shcm4: "<< logPb(shcm4));

                User* user = root->con->getUserByCid(shcm4.icid());
                if(!user)
                {
                    DLOG_TRACE("roomid:" << root->roomid() << ",bubi. user is nullptr: cid: "<< shcm4.icid());
                    return ;
                }

                XGameSHProto::SH_msg2csBuBi shcm2;
                shcm2.set_icid(shcm4.icid());
                if(root->cfg->getMinTake() > user->getWealth())
                {
                    DLOG_TRACE("roomid:" << root->roomid() << ",bubi. gold not enough. wealth: "<< user->getWealth());
                    shcm2.set_iresultid(XGameRetCode::GAME_GOLD_BUY_INSUFFICIENT);
                    sendClientMessage<XGameSHProto::SH_msg2csBuBi>(user->getUid(), XGameSHProto::SH_msg2csBuBi_E, shcm2, root);
                    return;
                }

                user->setWealth(user->getWealth() - root->cfg->getMinTake());
                user->setSHWealth(user->getSHWealth() + root->cfg->getMinTake());
                shcm2.set_lcidscore(user->getSHWealth());

                DLOG_TRACE("roomid:" << root->roomid() << ", bubi. uid: " << user->getUid() << ", shcm2: "<< logPb(shcm2));
                sendClientMessage<XGameSHProto::SH_msg2csBuBi>(uid, XGameSHProto::SH_msg2csBuBi_E, shcm2, root);

                //变更货币
              /*  TGAME_PlayerScoreChange tmm;
                tmm.info.buyInNum = 0;
                tmm.info.winNum = 0;
                tmm.info.buyInCount = 0;
                tmm.aiInfo.iAiGameRound = 0;
                tmm.aiInfo.iAiGamePoint = 0;
                tmm.iNowRound = 0;
                tmm.changeType = 2;
                tmm.changePoint.insert(std::make_pair(user->getUid(), -root->cfg->getMinTake()));
                sendRoomMessage<TGAME_PlayerScoreChange>(TGAME_PlayerScoreChange_E, tmm, root);*/

                EndTimer(NN_XTIME_BUBI, root, false);
                //check game begin
                game::logic::gamelogic::CheckBegin(root);

                __CATCH__
                PERFSTATS_EXIT();
            }
        }
    }
}
