/*
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details.
 */

#ifndef KAWASHIMA_HCA_H
#define KAWASHIMA_HCA_H

#include "../kstypedef.h"
#include "./internal/CHcaAth.h"
#include "./internal/CHcaCipher.h"
#include "./internal/CHcaData.h"
#include "internal/HcaChannel.h"
#include "../ksapi.h"

typedef struct _KS_DECODE_STATUS KS_DECODE_STATUS;

class CHCA {

public:

    typedef void (*DecodeFunc)(float data, uint8 *buffer, uint32 *cursor);

    CHCA(uint32 ciphKey1, uint32 ciphKey2);

    static uint16 Checksum(void *data, uint32 size, uint16 sum);

    KS_RESULT ReadHeader(uint8 *fileData, uint32 fileSize, KS_DECODE_STATUS *status);

    KS_RESULT GetWaveHeader(uint8 *pBuffer, uint32 *pdwWaveHeaderSize);

    KS_RESULT DecodeData(uint8 *pData, uint32 dwDataSize, KS_DECODE_STATUS *status, uint8 *pWaveData,
                         uint32 *pdwWaveDataSize, ubool *pbHasMore);

    KS_RESULT GenerateWaveDataBlock(uint8 *pData, uint32 dwBlockSize, uint32 *pDataCursor, uint8 *pBuffer,
                                    uint32 *pBufferCursor, DecodeFunc pfnDecodeFunc);

    KS_RESULT DecodeBlock(uint8 *pData, uint32 dwBlockSize, uint32 *pDataCursor);

    const HCA_INFO *GetInfo();

private:

    uint32 _ciph_key1;
    uint32 _ciph_key2;

    CHcaAth _ath;
    CHcaCipher _cipher;
    HcaChannel _channels[0x10];
    HCA_INFO _hcaInfo;

};

#endif
