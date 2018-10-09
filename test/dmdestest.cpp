
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
