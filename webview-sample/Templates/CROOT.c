/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "C[!output FIX_PROJECT_NAME].h"
[!if ADD_CONNECTION_POINTS]
#include "C[!output FIX_PROJECT_NAME]EnumConnectionPoints.h"
#include "IEcoConnectionPointContainer.h"
[!endif]

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса I[!output FIX_PROJECT_NAME]
 * </описание>
 *
 */
int16_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_QueryInterface(/* in */ I[!output FIX_PROJECT_NAME]Ptr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

[!if ADD_AGGREGATION_INNER]
    return pCMe->m_pIUnkOuter->pVTbl->QueryInterface(pCMe->m_pIUnkOuter, riid, ppv);
[!else]
    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_I[!output FIX_PROJECT_NAME]) ) {
        *ppv = &pCMe->m_pVTblI[!output FIX_PROJECT_NAME];
        pCMe->m_pVTblI[!output FIX_PROJECT_NAME]->AddRef((I[!output FIX_PROJECT_NAME]*)pCMe);
    }
[!if ADD_CONTAINMENT_OUTER]
    else if (IsEqualUGUID(riid, &IID_IEcoXXX)) {
        *ppv = &pCMe->m_pVTblIXXXX;
        pCMe->m_pVTblI[!output FIX_PROJECT_NAME]->AddRef((I[!output FIX_PROJECT_NAME]*)pCMe);
    }
[!endif]	
[!if ADD_CONNECTION_POINTS]
    else if ( IsEqualUGUID(riid, &IID_IEcoConnectionPointContainer) ) {
        *ppv = &pCMe->m_pVTblICPC;
        pCMe->m_pVTblICPC->AddRef((I[!output FIX_PROJECT_NAME]*)pCMe);
    }
[!endif]
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblI[!output FIX_PROJECT_NAME];
        pCMe->m_pVTblI[!output FIX_PROJECT_NAME]->AddRef((I[!output FIX_PROJECT_NAME]*)pCMe);
    }
[!if ADD_AGGREGATION_OUTER]
    /* Слепое агрегирование */
    else if (pCMe->m_pIUnkInner != 0) {
        /* Запрашиваем интерфейс внутреннего компонента */
        return pCMe->m_pIUnkInner->pVTbl->QueryInterface(pCMe->m_pIUnkInner, riid, ppv);
    }
[!endif]
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
[!endif]
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса I[!output FIX_PROJECT_NAME]
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_AddRef(/* in */ I[!output FIX_PROJECT_NAME]Ptr_t me) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

[!if ADD_AGGREGATION_INNER]
    return pCMe->m_pIUnkOuter->pVTbl->AddRef(pCMe->m_pIUnkOuter);
[!else]
    return ++pCMe->m_cRef;
[!endif]
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса I[!output FIX_PROJECT_NAME]
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_Release(/* in */ I[!output FIX_PROJECT_NAME]Ptr_t me) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

[!if ADD_AGGREGATION_INNER]
    return pCMe->m_pIUnkOuter->pVTbl->Release(pCMe->m_pIUnkOuter);
[!else]
    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
[!if ADD_AGGREGATION_OUTER]
        if ( pCMe->m_pIUnkInner != 0 ) {
            /* Предотвращение рекурсивного вызова */
            if (pCMe->m_pIUnkInner->pVTbl->Release(pCMe->m_pIUnkInner) == 0) {
                pCMe->m_pIUnkInner = 0;
            }
            else {
                pCMe->m_cRef = 1;
            }
        }
        if ( pCMe->m_cRef == 0 ) {
            deleteC[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]((I[!output FIX_PROJECT_NAME]*)pCMe);
        }		
[!else]
        deleteC[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]((I[!output FIX_PROJECT_NAME]*)pCMe);
[!endif]		
        return 0;
    }
    return pCMe->m_cRef;
[!endif]
}

/*
 *
 * <сводка>
 *   Функция MyFunction
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_MyFunction(/* in */ I[!output FIX_PROJECT_NAME]Ptr_t me, /* in */ char_t* Name, /* out */ char_t** copyName) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)me;
    int16_t index = 0;

    /* Проверка указателей */
    if (me == 0 || Name == 0 || copyName == 0) {
        return -1;
    }

    /* Копирование строки */
    while(Name[index] != 0) {
        index++;
    }
    pCMe->m_Name = (char_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, index + 1);
    index = 0;
    while(Name[index] != 0) {
        pCMe->m_Name[index] = Name[index];
        index++;
    }
    *copyName = pCMe->m_Name;

[!if ADD_CONNECTION_POINTS]
    /* Обратный вызов */
    pCMe->Fire_OnMyCallback(pCMe, pCMe->m_Name);

[!endif]
    return 0;
}

[!if ADD_AGGREGATION_INNER]
/*
 *
 * <сводка>
 *   Функция NondelegatingQueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция NondelegatingQueryInterface для интерфейса I[!output FIX_PROJECT_NAME]
 * </описание>
 *
 */
int16_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_NondelegatingQueryInterface(/* in */ I[!output FIX_PROJECT_NAME]Ptr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)((uint64_t)me - sizeof(struct I[!output FIX_PROJECT_NAME]*));

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_I[!output FIX_PROJECT_NAME]) ) {
        *ppv = &pCMe->m_pVTblI[!output FIX_PROJECT_NAME];
        pCMe->m_pVTblI[!output FIX_PROJECT_NAME]->AddRef((I[!output FIX_PROJECT_NAME]*)pCMe);
    }
[!if ADD_CONNECTION_POINTS]
    else if ( IsEqualUGUID(riid, &IID_IEcoConnectionPointContainer) ) {
        *ppv = &pCMe->m_VtblICPC;
        pCMe->m_pVTblICPC->AddRef((I[!output FIX_PROJECT_NAME]*)pCMe);
    }
[!endif]
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblI[!output FIX_PROJECT_NAME];
        pCMe->m_pVTblI[!output FIX_PROJECT_NAME]->AddRef((I[!output FIX_PROJECT_NAME]*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция NondelegatingAddRef
 * </сводка>
 *
 * <описание>
 *   Функция NondelegatingAddRef для интерфейса I[!output FIX_PROJECT_NAME]
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_NondelegatingAddRef(/* in */ I[!output FIX_PROJECT_NAME]Ptr_t me) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)((uint64_t)me - sizeof(struct I[!output FIX_PROJECT_NAME]*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция NondelegatingRelease
 * </сводка>
 *
 * <описание>
 *   Функция NondelegatingRelease для интерфейса I[!output FIX_PROJECT_NAME]
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_NondelegatingRelease(/* in */ I[!output FIX_PROJECT_NAME]Ptr_t me) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)((uint64_t)me - sizeof(struct I[!output FIX_PROJECT_NAME]*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteC[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]((I[!output FIX_PROJECT_NAME]*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}
[!endif]

[!if ADD_CONTAINMENT_OUTER]
/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoXXXX
 * </описание>
 *
 */
int16_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoXXXX_QueryInterface(/* in */ struct IEcoXXXX* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)((uint64_t)me - sizeof(struct I[!output FIX_PROJECT_NAME]*));

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_I[!output FIX_PROJECT_NAME]) ) {
        *ppv = &pCMe->m_pVTblI[!output FIX_PROJECT_NAME];
        pCMe->m_pVTblI[!output FIX_PROJECT_NAME]->AddRef((I[!output FIX_PROJECT_NAME]*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoXXX)) {
        *ppv = &pCMe->m_pVTblIXXXX;
        pCMe->m_pVTblI[!output FIX_PROJECT_NAME]->AddRef((I[!output FIX_PROJECT_NAME]*)pCMe);
    }	
[!if ADD_CONNECTION_POINTS]
    else if ( IsEqualUGUID(riid, &IID_IEcoConnectionPointContainer) ) {
        *ppv = &pCMe->m_VtblICPC;
        pCMe->m_pVTblICPC->AddRef((I[!output FIX_PROJECT_NAME]*)pCMe);
    }
[!endif]
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblI[!output FIX_PROJECT_NAME];
        pCMe->m_pVTblI[!output FIX_PROJECT_NAME]->AddRef((I[!output FIX_PROJECT_NAME]*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoXXXX
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoXXXX_AddRef(/* in */ struct IEcoXXXX* me) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)((uint64_t)me - sizeof(struct I[!output FIX_PROJECT_NAME]*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoXXXX
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoXXXX_Release(/* in */ struct IEcoXXXX* me) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)((uint64_t)me - sizeof(struct I[!output FIX_PROJECT_NAME]*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteC[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]((I[!output FIX_PROJECT_NAME]*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}
[!endif]

[!if ADD_CONNECTION_POINTS]
/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoConnectionPointContainer
 * </описание>
 *
 */
int16_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoConnectionPointContainer_QueryInterface(/* in */ struct IEcoConnectionPointContainer* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)((uint64_t)me - sizeof(struct I[!output FIX_PROJECT_NAME]));

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_I[!output FIX_PROJECT_NAME]) ) {
        *ppv = &pCMe->m_pVTblI[!output FIX_PROJECT_NAME];
        pCMe->m_pVTblI[!output FIX_PROJECT_NAME]->AddRef((I[!output FIX_PROJECT_NAME]*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoConnectionPointContainer) ) {
        *ppv = &pCMe->m_pVTblICPC;
        pCMe->m_pVTblI[!output FIX_PROJECT_NAME]->AddRef((I[!output FIX_PROJECT_NAME]*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblI[!output FIX_PROJECT_NAME];
        pCMe->m_pVTblI[!output FIX_PROJECT_NAME]->AddRef((I[!output FIX_PROJECT_NAME]*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoConnectionPointContainer
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoConnectionPointContainer_AddRef(/* in */ struct IEcoConnectionPointContainer* me) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)((uint64_t)me - sizeof(struct I[!output FIX_PROJECT_NAME]));

    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoConnectionPointContainer
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoConnectionPointContainer_Release(/* in */ struct IEcoConnectionPointContainer* me) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)((uint64_t)me - sizeof(struct I[!output FIX_PROJECT_NAME]));

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteC[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]((I[!output FIX_PROJECT_NAME]*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция EnumConnectionPoints
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoConnectionPointContainer_EnumConnectionPoints(/* in */ struct IEcoConnectionPointContainer* me, /* out */ struct IEcoEnumConnectionPoints **ppEnum) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)((uint64_t)me - sizeof(struct I[!output FIX_PROJECT_NAME]));
    int16_t result = 0;

    if (me == 0 || ppEnum == 0 ) {
        return -1;
    }

    result = createC[!output FIX_PROJECT_NAME]EnumConnectionPoints[!output GUID_CID_NAMESPACE]((IEcoUnknown*)pCMe->m_pISys, &pCMe->m_pISinkCP->m_pVTblICP, ppEnum);

    return result;
}

/*
 *
 * <сводка>
 *   Функция FindConnectionPoint
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoConnectionPointContainer_FindConnectionPoint(/* in */ struct IEcoConnectionPointContainer* me, /* in */ const UGUID* riid, /* out */ struct IEcoConnectionPoint **ppCP) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)((uint64_t)me - sizeof(struct I[!output FIX_PROJECT_NAME]));
    int16_t result = 0;

    if (me == 0 || ppCP == 0 ) {
        return -1;
    }

    if ( !IsEqualUGUID(riid, &IID_I[!output FIX_PROJECT_NAME]Events ) ) {
        *ppCP = 0;
        /* CONNECT_E_NOCONNECTION */
        return -1;
    }

    if (pCMe->m_pISinkCP == 0) {
        /* E_FAIL */
        return -1;
    }

    pCMe->m_pISinkCP->m_pVTblICP->AddRef(&pCMe->m_pISinkCP->m_pVTblICP);
    *ppCP =  &pCMe->m_pISinkCP->m_pVTblICP;

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Fire_OnSearchStarted
 * </сводка>
 *
 * <описание>
 *   Функция вызова обратного интерфейса
 * </описание>
 *
 */
int16_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_I[!output FIX_PROJECT_NAME]Events_Fire_OnMyCallback(/* in */ struct C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* me, /* in */ char_t* Name) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)me;
    int16_t result = 0;
    uint32_t count = 0;
    uint32_t index = 0;
    IEcoEnumConnections* pEnum = 0;
    I[!output FIX_PROJECT_NAME]Events* pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
        if ( (result == 0) && (pEnum != 0) ) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_I[!output FIX_PROJECT_NAME]Events, (void**)&pIEvents);
                if ( (result == 0) && (pIEvents != 0) ) {
                    result = pIEvents->pVTbl->OnMyCallback(pIEvents, Name);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}
[!endif]

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initC[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE](/*in*/ I[!output FIX_PROJECT_NAME]Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)me;
    IEcoInterfaceBus1* pIBus = 0;
[!if ADD_AGGREGATION_OUTER]
    IEcoUnknown* pOuterUnknown = (IEcoUnknown*)me;
[!endif]
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

[!if ADD_CONNECTION_POINTS]
    /* Создание точки подключения */
    result = createC[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]((IEcoUnknown*)pCMe->m_pISys, &pCMe->m_pVTblICPC, &IID_I[!output FIX_PROJECT_NAME]Events, (IEcoConnectionPoint**)&((pCMe)->m_pISinkCP));
    if (result == 0 && pCMe->m_pISinkCP != 0) {
        result = 0;
    }

[!endif]

[!if ADD_AGGREGATION_OUTER]
    /* Создание внутреннего компонента c поддержкой агрегирования */
    /* ВАЖНО: При агрегировании мы передаем IID IEcoUnknown */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoXXXX, pOuterUnknown, &IID_IEcoUnknown, (void**) &pCMe->m_pIUnkInner);
[!endif]
[!if ADD_CONTAINMENT_OUTER]
    /* Создание внутреннего компонента (включение) */
    /*result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoXXXX, 0, &IID_IEcoXXXX, (void**) &pCMe->m_pIXXXX);*/
[!endif]

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);
	
    return result;
}

/* Create Virtual Table I[!output FIX_PROJECT_NAME] */
I[!output FIX_PROJECT_NAME]VTbl g_x[!output GUID_IID_TARGET]VTbl[!output GUID_CID_NAMESPACE] = {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_QueryInterface,
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_AddRef,
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_Release,
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_MyFunction
};

[!if ADD_AGGREGATION_INNER]
/* Create Virtual Table IEcoNondelegatingUnknown */
IEcoUnknownVTbl g_x000000000000000000000000000000AAVTblUnk[!output GUID_CID_NAMESPACE] = {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_NondelegatingQueryInterface,
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_NondelegatingAddRef,
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_NondelegatingRelease
};
[!endif]

[!if ADD_CONTAINMENT_OUTER]
/* Create Virtual Table IEcoXXXX */
IEcoXXXXVTbl g_xXXXXVTbl[!output GUID_CID_NAMESPACE] = {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoXXXX_QueryInterface,
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoXXXX_AddRef,
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoXXXX_Release
};
[!endif]

[!if ADD_CONNECTION_POINTS]
/* Create Virtual Table IEcoConnectionPointContainer */
IEcoConnectionPointContainerVTbl g_x0000000500000000C000000000000046VTblCPC[!output GUID_CID_NAMESPACE] = {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoConnectionPointContainer_QueryInterface,
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoConnectionPointContainer_AddRef,
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoConnectionPointContainer_Release,
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoConnectionPointContainer_EnumConnectionPoints,
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_IEcoConnectionPointContainer_FindConnectionPoint
};
[!endif]

/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createC[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE](/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ I[!output FIX_PROJECT_NAME]Ptr_t* ppI[!output FIX_PROJECT_NAME]) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppI[!output FIX_PROJECT_NAME] == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

	/* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)pIMem->pVTbl->Alloc(pIMem, sizeof(C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса I[!output FIX_PROJECT_NAME] */
    pCMe->m_pVTblI[!output FIX_PROJECT_NAME] = &g_x[!output GUID_IID_TARGET]VTbl[!output GUID_CID_NAMESPACE];

[!if ADD_CONNECTION_POINTS]
    /* Создание таблицы функций интерфейса IEcoConnectionPointContainer */
    pCMe->m_pVTblICPC = &g_x0000000500000000C000000000000046VTblCPC[!output GUID_CID_NAMESPACE];

    pCMe->Fire_OnMyCallback = C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]_I[!output FIX_PROJECT_NAME]Events_Fire_OnMyCallback;

[!endif]
[!if ADD_AGGREGATION_INNER]
    /* Неделигирующий интерфейс IEcoUnknown */
    pCMe->m_pVTblINondelegatingUnk = &g_x000000000000000000000000000000AAVTblUnk[!output GUID_CID_NAMESPACE];

    pCMe->m_pIUnkOuter = 0;
    /* Если не агрегируется, использовать неделигирующий интерфейс IEcoUnknown */
    if (pIUnkOuter != 0) {
        pCMe->m_pIUnkOuter = pIUnkOuter;
    } else {
        pCMe->m_pIUnkOuter = (IEcoUnknown*)&pCMe->m_pVTblINondelegatingUnk;
    }


[!endif]
    /* Инициализация данных */
    pCMe->m_Name = 0;
[!if ADD_AGGREGATION_OUTER]
    pCMe->m_pIUnkInner = 0;
[!endif]
[!if ADD_CONTAINMENT_OUTER]
    pCMe->m_pIXXXX = 0;
[!endif]

    /* Возврат указателя на интерфейс */
    *ppI[!output FIX_PROJECT_NAME] = (I[!output FIX_PROJECT_NAME]*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteC[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE](/* in */ I[!output FIX_PROJECT_NAME]Ptr_t pI[!output FIX_PROJECT_NAME]) {
    C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME][!output GUID_CID_NAMESPACE]*)pI[!output FIX_PROJECT_NAME];
    IEcoMemoryAllocator1* pIMem = 0;

    if (pI[!output FIX_PROJECT_NAME] != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
[!if ADD_CONNECTION_POINTS]
        if (pCMe->m_pISinkCP != 0) {
            deleteC[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]((IEcoConnectionPoint*)(pCMe->m_pISinkCP));
            pCMe->m_pISinkCP = 0;
        }
[!endif]
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
