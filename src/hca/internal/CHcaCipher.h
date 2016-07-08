#ifndef KAWASHIMA_HCACIPHER_H
#define KAWASHIMA_HCACIPHER_H

#include "../../kstypedef.h"
#include "../../hca_info.h"

class CHcaCipher {

public:
    CHcaCipher();

    ubool Init(HCA_CIPHER_TYPE type, uint32 key1, uint32 key2);

    void Decrypt(uint8 *data, uint32 size);

private:
    uint8 _decryptTable[0x100];

    void Init0();

    void Init1();

    void Init56(uint32 key1, uint32 key2);

    void Init56_CreateTable(uint8 *table, uint8 key);

};

#endif //KAWASHIMA_HCACIPHER_H
