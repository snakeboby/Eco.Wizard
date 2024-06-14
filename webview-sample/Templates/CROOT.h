[!if ECO_COM_APP]
/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   C[!output FIX_PROJECT_NAME]
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента C[!output FIX_PROJECT_NAME]
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_H__
#define __C_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_H__

#include "I[!output FIX_PROJECT_NAME].h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
[!if ADD_CONNECTION_POINTS]
#include "IEcoEnumConnections.h"
#include "IEcoConnectionPointContainer.h"
#include "C[!output FIX_PROJECT_NAME]ConnectionPoint.h"
[!endif]
[!if ADD_CONTAINMENT_OUTER]
/*#include "IEcoXXXX.h"*/
[!endif]

typedef struct C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE] {

    /* Таблица функций интерфейса I[!output FIX_PROJECT_NAME] */
    I[!output FIX_PROJECT_NAME]VTbl* m_pVTblI[!output FIX_PROJECT_NAME];

[!if ADD_AGGREGATION_INNER]
    /* Неделигирующий интерфейс IEcoUnknown */
    IEcoUnknownVTbl* m_pVTblINondelegatingUnk;

[!endif]
[!if ADD_CONTAINMENT_OUTER]
    /* Таблица функций интерфейса IEcoXXXX */
    IEcoXXXXVTbl* m_pVTblIXXXX;

[!endif]
[!if ADD_CONNECTION_POINTS]
    /* Таблица функций интерфейса IEcoConnectionPointContainer */
    IEcoConnectionPointContainerVTbl* m_pVTblICPC;

    /* Вспомогательные функции для уведомлений */
    int16_t (*Fire_OnMyCallback)(/* in */ struct C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* me, /* in */ char_t* Name);

[!endif]

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

[!if ADD_CONNECTION_POINTS]
    /* Точка подключения */
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]* m_pISinkCP;

[!endif]
[!if ADD_AGGREGATION_INNER]
    /* Делегирующий IEcoUnknown, указывает на внешний или неделегирующий IEcoUnknown */
    IEcoUnknown* m_pIUnkOuter;

[!endif]
[!if ADD_AGGREGATION_OUTER]
    /* Указатель на IEcoUnknown внутреннего компонента */
    IEcoUnknown* m_pIUnkInner;

[!endif]
[!if ADD_CONTAINMENT_OUTER]
    /* Указатель на интерфейс IEcoXXXX включаемого компонента */
    IEcoXXXX* m_pIXXXX;

[!endif]
    /* Данные экземпляра */
    char_t* m_Name;

} C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE], *C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initC[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE](/*in*/ I[!output FIX_PROJECT_NAME]Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createC[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE](/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ I[!output FIX_PROJECT_NAME]Ptr_t* ppI[!output FIX_PROJECT_NAME]);
/* Удаление */
void ECOCALLMETHOD deleteC[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE](/* in */ I[!output FIX_PROJECT_NAME]Ptr_t pI[!output FIX_PROJECT_NAME]);

#endif /* __C_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_H__ */
[!endif]
