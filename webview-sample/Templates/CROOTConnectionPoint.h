/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   C[!output FIX_PROJECT_NAME]ConnectionPoint
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию интерфейсов C[!output FIX_PROJECT_NAME]ConnectionPoint
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_CONNECTION_POINT_H__
#define __C_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_CONNECTION_POINT_H__

#include "IEcoConnectionPoint.h"
#include "IEcoConnectionPointContainer.h"
#include "IdEcoList1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE] {

    /* Таблица функций интерфейса IEcoConnectionPoint */
    IEcoConnectionPointVTbl* m_pVTblICP;

    /* Интерфейс контейнера точки подключения */
    IEcoConnectionPointContainer* m_pICPC;

    /* Идентификатор точки подключения */
    UGUID* m_piid;

    /* Cookie */
    uint32_t m_cNextCookie;

    /* Список подключений */
    IEcoList1* m_pSinkList;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

} C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE];

/* Создание экземпляра */
int16_t ECOCALLMETHOD createC[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE](/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoConnectionPointContainer* pICPC, /* in */ const UGUID* riid, /* out */ IEcoConnectionPoint** ppICP);
/* Удаление */
void ECOCALLMETHOD deleteC[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE](/* in */ IEcoConnectionPoint* pICP);

#endif /* __C_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_CONNECTION_POINT_H__ */
