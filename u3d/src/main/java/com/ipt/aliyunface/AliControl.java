package com.ipt.aliyunface;

import com.alipay.face.api.ZIMCallback;
import com.alipay.face.api.ZIMFacade;
import com.alipay.face.api.ZIMFacadeBuilder;
import com.alipay.face.api.ZIMResponse;

import com.unity3d.player.UnityPlayer;

import android.util.Log;

public class AliControl {
    private FaceVerifyInterface listenerFaceVerify;
    private Boolean isInit = false;

    public void initFace() {
        if(!isInit){
            ZIMFacade.install(UnityPlayer.currentActivity);
            isInit = true;
        }
    }

    public  String getMetaInfos(){ return ZIMFacade.getMetaInfos(UnityPlayer.currentActivity); }

    public void faceVerify(String certifyId){
        Log.w("certifyId", certifyId);
        ZIMFacade zimFacade = ZIMFacadeBuilder.create(UnityPlayer.currentActivity);
        zimFacade.verify(certifyId, true, null, new ZIMCallback() {
            @Override
            public boolean response(final ZIMResponse response) {
                listenerFaceVerify.onListenerFaceVerify(response.code, response.reason);
                return true;
            }
        });
    }

    public void addListenerFaceVerify(FaceVerifyInterface listener){
        this.listenerFaceVerify = listener;
    }
}
