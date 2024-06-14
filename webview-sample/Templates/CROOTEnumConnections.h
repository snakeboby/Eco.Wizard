/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   C[!output FIX_PROJECT_NAME]EnumConnections
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию интерфейсов C[!output FIX_PROJECT_NAME]EnumConnections
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_ENUM_CONNECTIONS_H__
#define __C_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_ENUM_CONNECTIONS_H__

#include "IEcoEnumConnections.h"
#include "IdEcoList1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct C[!output FIX_PROJECT_NAME]EnumConnections[!output GUID_CID_NAMESPACE] {

    /* Таблица функций интерфейса IEcoEnumConnections */
    IEcoEnumConnectionsVTbl* m_pVTblIEC;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Список подключений */
    IEcoList1* m_pSinkList;
    uint32_t m_cIndex;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

} C[!output FIX_PROJECT_NAME]EnumConnections[!output GUID_CID_NAMESPACE];

/* Создание экземпляра */
int16_t ECOCALLMETHOD createC[!output FIX_PROJECT_NAME]EnumConnections[!output GUID_CID_NAMESPACE](/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoList1* pIList, /* out */ IEcoEnumConnections** ppIEnum);
/* Удаление */
void ECOCALLMETHOD deleteC[!output FIX_PROJECT_NAME]EnumConnections[!output GUID_CID_NAMESPACE](/* in */ IEcoEnumConnections* pIEnum);

#endif /* __C_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_1_ENUM_CONNECTIONS_H__ */
