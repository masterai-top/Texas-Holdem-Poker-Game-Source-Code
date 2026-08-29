# Add project specific ProGuard rules here.
# You can control the set of applied configuration files using the
# proguardFiles setting in build.gradle.
#
# For more details, see
#   http://developer.android.com/guide/developing/tools/proguard.html

# If your project uses WebView with JS, uncomment the following
# and specify the fully qualified class name to the JavaScript interface
# class:
#-keepclassmembers class fqcn.of.javascript.interface.for.webview {
#   public *;
#}

# Uncomment this to preserve the line number information for
# debugging stack traces.
#-keepattributes SourceFile,LineNumberTable

# If you keep the line number information, uncomment this to
# hide the original source file name.
#-renamesourcefileattribute SourceFile

# aliyunface 要求  为避免接口被混淆而造成功能异常，您需要在App工程的proguard-rules.pro文件中添加如下配置信息
-keep class com.alipay.deviceid.** { *; }
-keep class net.security.device.api.** {*;}
-keep class org.json.** { *;}
-keep class com.alibaba.fastjson.** {*;}
-keep class com.alibaba.sdk.android.oss.** { *; }

-dontwarn okio.**
-dontwarn org.apache.commons.codec.binary.**

-keepclassmembers,allowobfuscation class * {
     @com.alibaba.fastjson.annotation.JSONField <fields>;
}