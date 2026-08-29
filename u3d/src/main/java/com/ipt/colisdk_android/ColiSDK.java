package com.ipt.colisdk_android;

import android.util.Log;

import com.ipt.DeviceID.DeviceIdGet;
import com.ipt.Permission.PermissionsSet;
import com.ipt.SelectImage.SelectImage;

public class ColiSDK {
    public static  ColiSDK  instance;
    public static ColiSDK getInstance() {
        if (instance == null)
            instance = new ColiSDK();
        return instance;
    }

    public Object GetColiSDK(String type)
    {
        Log.w("type",type);
        switch (type)
        {
            case ColiSDKType.ColiSDKSelectImage:
                return SelectImage.Instance();
            case ColiSDKType.ColiSDKPermission:
                return PermissionsSet.Instance();
            case ColiSDKType.ColiSDKDeviceIdGet:
                return DeviceIdGet.Instance();
        }
        return  null;
    }
}

class ColiSDKType
{
    public static final String ColiSDKSelectImage = "ColiSDKSelectImage";
    public static final String ColiSDKPermission = "ColiSDKPermission";
    public static final String ColiSDKDeviceIdGet = "ColiSDKDeviceIdGet";
}


