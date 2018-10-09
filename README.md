# dmdes

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)

[dmdes GitHub](https://github.com/brinkqiang/dmdes)

## Build status
| [Linux][lin-link] | [MacOSX][osx-link] | [Windows][win-link] |
| :---------------: | :----------------: | :-----------------: |
| ![lin-badge]      | ![osx-badge]       | ![win-badge]        |

[lin-badge]: https://travis-ci.org/brinkqiang/dmdes.svg?branch=master "Travis build status"
[lin-link]:  https://travis-ci.org/brinkqiang/dmdes "Travis build status"
[osx-badge]: https://travis-ci.org/brinkqiang/dmdes.svg?branch=master "Travis build status"
[osx-link]:  https://travis-ci.org/brinkqiang/dmdes "Travis build status"
[win-badge]: https://ci.appveyor.com/api/projects/status/github/brinkqiang/dmdes?branch=master&svg=true "AppVeyor build status"
[win-link]:  https://ci.appveyor.com/project/brinkqiang/dmdes "AppVeyor build status"

## Intro
dmdes
```cpp

#include "dmdes.h"
#include <string>
#include <iostream>

int main( int argc, char* argv[] ) {

    CDMDes oDes;

    DMDES3Block sBlock = { 0 };
    DMDES3Context stContext = {0};

    oDes.DESGenEncKeySche(&stContext, sBlock);

    std::string strData = "hello world";
    std::string strBuf;
    strBuf.resize(strData.size());

    oDes.DESEncryptNCBC(&stContext, &sBlock, strData.size(), (uint8_t*)&strData[0], (uint8_t*)&strBuf[0]);

    strData.clear();
    strData.resize(strBuf.size());
    oDes.DESDecryptNCBC(&stContext, &sBlock, strBuf.size(), (uint8_t*)&strBuf[0], (uint8_t*)&strData[0]);

    std::cout << strData << std::endl;

    return 0;
}

```
## Contacts
[![Join the chat](https://badges.gitter.im/brinkqiang/dmdes/Lobby.svg)](https://gitter.im/brinkqiang/dmdes)

## Thanks
