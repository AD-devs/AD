#!/bin/zsh

if [ ! -d "/var/jb/theos/" ]; then
    echo "錯誤: 不存在 iOS theos"
    exit 1
fi

if [ ! -d "/var/jb/theos/sdks/" ]; then
    echo "錯誤: 不存在 iOS theos 的 sdks 可能 theos 不是完整的 theos"
    exit 1
fi

ls -la /var/jb/theos/sdks/*.sdk
echo "找到的 iOS SDK"

for sdk in /var/jb/theos/sdks/*.sdk; do
    if [ -d "$sdk" ]; then
        ln -s "$sdk" "/var/AD/AD/usr/include/iOS_SDK/"
        echo "添加 iOS SDK 成功: $(basename "$sdk")"
    fi
done