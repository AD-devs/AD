# AD

#### 這是什麼東西?
- AD的私有庫
- AD的家目錄
- AD的工作目錄

#### 安裝
- 使用 cd /var && git clone https://github.com/AD-devs/AD 來安裝
- 權限不足請使用 sudo -i 或者 su root來獲取root權限後再來操作

#### 添加環境變量
- 添加 AD="/var/AD/UsrLb" 環境變量之後可以使用 cd $AD 來到達 AD 的家目錄
- 如果已經有了 AD 這個用戶則不需要 有 AD 這個用戶的要安裝到 AD 用戶的家目錄中

#### 建議添加的環境變量
- export AD_PRIVATE_ROOT="/var/AD/AD"
- export AD_INCLUDE_PATH="${AD_PRIVATE_ROOT}/usr/include" #### 添加頭文件庫
- export AD_LIB_PATH="${AD_PRIVATE_ROOT}/usr/lib/dylib" #### 添加 dylib 動態庫
- export AD_LIB_PATH="${AD_PRIVATE_ROOT}/usr/lib/so" #### 添加 so 動態庫
- export AD_LIB_PATH="${AD_PRIVATE_ROOT}/usr/lib/a" #### 添加靜態庫

#### 其他問題
- Q: 沒有 AD 用戶可以用嗎?
- A: 可以用,沒有 AD 用戶的話通常使用第一個普通用戶
- Q: 如何設置 AD "家目錄" 的權限?
- A: 在 Linux 中 通常是 AD:wheel 如果沒有 AD 用戶則使用第一個普通用戶
- A: 在 MacOS 中 通常是 AD:admin 或者 AD:wheel 推薦 AD:admin 沒有 AD 用戶 則使用第一個普通用戶
- Q: 可以在 Linux 中 用 root:root 在 MacOS 中用 root:wheel 嗎?
- A: 不推薦但是可以, 因為權限越大責任越大,通常推薦是普通用戶加wheel或者admin組

......