//
// Created by MIC on 2016/3/18.
//

#ifndef KAWASHIMA_HCA_INFO_H
#define KAWASHIMA_HCA_INFO_H

#include "kstypedef.h"

typedef enum {
    HCA_CIPHER_TYPE_NO_CIPHER = 0,
    HCA_CIPHER_TYPE_STATIC = 1,
    HCA_CIPHER_TYPE_WITH_KEY = 0x38,
    HCA_CIPHER_TYPE_FORCE_DWORD = (uint32)0xffffffff
} HCA_CIPHER_TYPE;

typedef struct _HCA_INFO {
    /**
     * Major part of version number.
     */
    uint16 versionMajor;
    /**
     * Minor part of version number.
     */
    uint16 versionMinor;
    /**
     * Channel count.
     */
    uint32 channelCount;
    /**
     * Sampling rate, in hertz.
     */
    uint32 samplingRate;
    /**
     * Total number of data blocks.
     */
    uint32 blockCount;
    /**
     * Size of each data block.
     */
    uint16 blockSize;
    /**
     * ATH type.
     * Possible values (observed) are 0 and 1.
     */
    uint16 athType;
    /**
     * Whether internal loop flag is on.
     */
    ubool loopExists;
    /**
     * The block index at the start of looping segment.
     */
    uint32 loopStart;
    /**
     * The block index at the end of looping segment.
     */
    uint32 loopEnd;
    /**
     * Cipher type.
     */
    HCA_CIPHER_TYPE cipherType;
    /**
     * Relative volume in RVA (relative volume adjustment) table. It is the multiply factor for floating point wave data.
     */
    float rvaVolume;
    /**
     * Length of comment.
     */
    uint8 commentLength;
    /**
     * Comment data.
     */
    char comment[0x100];
    uint16 fmtR01, fmtR02;
    uint16 compR01, compR02, compR03, compR04, compR05, compR06, compR07, compR08;
    uint32 compR09;
    uint16 vbrR01, vbrR02;
    uint16 loopR01, loopR02;
} HCA_INFO;

#endif //KAWASHIMA_HCA_INFO_H
