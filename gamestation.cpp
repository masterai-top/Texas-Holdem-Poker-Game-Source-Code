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
#include "logic/gamelogic/core/endtimer.h"
#include "CommonCode.pb.h"

using namespace nndef;

namespace game
{
    namespace logic
    {
        namespace clientlogic
        {
            void GameStation(long uid, const vector<char> &vecMsgData, GameRoot *root)
            {
                PERFSTATS_ENTRY();
                __TRY__
                using namespace context;
                using namespace process;
                using namespace config;
                using namespace message;
                using namespace nnlogic;

                DLOG_TRACE("roomid:" << root->roomid() << ", game station. uid: " << uid);
               
                XGameSHProto::SH_msg2csGameStation shcm;
                shcm.set_iresultid(0);
                shcm.set_igameround(root->pro->getProcess());
                shcm.set_ibankercid(root->con->getBankerCid());
                shcm.set_itokencid(root->con->getTokenCid());
                shcm.set_lpoolscore(root->con->getTotalPoolNum());
                shcm.set_mbasescore(root->cfg->getFrontBet());

                XGameSHProto::SH_msg2sTokenNotify cm;
                cm.set_icid(root->con->getTokenCid());
                User *user = root->con->getUserByUid(uid);
                if(user)
                {
                    user->setLeft(false);
                }
                if(user && root->con->getTokenCid() == user->getCid())
                {
                    cm.set_iact(user->getAct());
                    cm.set_lcallscore(root->con->getRoundMaxBetNum() - user->getRoundBetNum(root->pro->getProcess()));
                }
                
                cm.set_icfgoptiontime(root->cfg->getBetTime());

                long userOpTime = time(nullptr) - root->con->getTokenOpTime();

                DLOG_TRACE("roomid:" << root->roomid() << ", userOpTime: " << userOpTime << ", cfgBetTime: "<< root->cfg->getBetTime());
                userOpTime = userOpTime < 0 || userOpTime > root->cfg->getBetTime() ? 0 : userOpTime;
                cm.set_iremainoptiontime(userOpTime);

                (*shcm.mutable_stokento()) = cm;
                    
                std::map<cid_t, User> const &usermap = root->con->getUserMap();
                for (auto it = usermap.begin(); it != usermap.end(); it++)
                { 
                    XGameSHProto::SH_sUserInfo userinfo;
                    userinfo.set_lplayerid(it->second.getUid());
                    userinfo.set_snickname(it->second.getNick());
                    userinfo.set_sheadstr(it->second.getUrl());
                    userinfo.set_iplayergender(it->second.getGender());
                    userinfo.set_lcidscore(it->second.getSHWealth());
                    userinfo.set_iroundact(it->second.getOption());
                    userinfo.set_lroundbetscore(it->second.getRoundBetNum(root->pro->getProcess()));
                    auto vec_cards = it->second.getVecCards();
                    if(vec_cards.size() > 1)
                    {
                        XGameSHProto::SH_Card hd_card;
                        hd_card.set_icardtype(-1);
                        int start_index = 0;
                        if(it->first != user->getCid())
                        {
                            start_index = 1;
                            hd_card.add_vcards(nil_card);
                        }
                        
                        for(unsigned int i = start_index; i < vec_cards.size(); i++)
                        {
                            hd_card.add_vcards(vec_cards[i]);
                        }
                        (*userinfo.mutable_mhdcard()) = hd_card;
                    }
                    (*shcm.mutable_muserinfo())[it->first] = userinfo;
                }

                DLOG_TRACE("roomid:" << root->roomid() << ", game station. uid: " << uid << ", shcm: "<< logPb(shcm));
                sendClientMessage<XGameSHProto::SH_msg2csGameStation>(uid, XGameSHProto::SH_msg2csGameStation_E, shcm, root);

                __CATCH__
                PERFSTATS_EXIT();
            }
        }
    }
}
