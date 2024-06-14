/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   C[!output FIX_PROJECT_NAME]EnumConnectionPoints
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию интерфейсов C[!output FIX_PROJECT_NAME]EnumConnectionPoints
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_ENUM_CONNECTION_POINTS_H__
#define __C_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_ENUM_CONNECTION_POINTS_H__

#include "IEcoEnumConnectionPoints.h"
#include "IdEcoList1.h"
#include "IdEcoMemoryManager1.h"

typedef struct C[!output FIX_PROJECT_NAME]EnumConnectionPoints[!output GUID_CID_NAMESPACE] {

    /* Таблица функций интерфейса IEcoEnumConnectionPoints */
    IEcoEnumConnectionPointsVTbl* m_pVTblIECP;

    /* Список */
    IEcoList1* m_List;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

} C[!output FIX_PROJECT_NAME]EnumConnectionPoints[!output GUID_CID_NAMESPACE];

/* Создание экземпляра */
int16_t ECOCALLMETHOD createC[!output FIX_PROJECT_NAME]EnumConnectionPoints[!output GUID_CID_NAMESPACE](/* in */ IEcoUnknown* pIUnkSystem, /* in */ struct IEcoConnectionPoint *pCP, /* out */ IEcoEnumConnectionPoints** ppIEnum);
/* Удаление */
void ECOCALLMETHOD deleteC[!output FIX_PROJECT_NAME]EnumConnectionPoints[!output GUID_CID_NAMESPACE](/* in */ IEcoEnumConnectionPoints* pIEnum);

#endif /* __C_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_ENUM_CONNECTION_POINTS_H__ */
