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
 *   Данный исходный код описывает реализацию интерфейсов C[!output FIX_PROJECT_NAME]ConnectionPoint
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "C[!output FIX_PROJECT_NAME]ConnectionPoint.h"
#include "C[!output FIX_PROJECT_NAME]EnumConnections.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_QueryInterface(/* in */ struct IEcoConnectionPoint* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]*)me;

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoConnectionPoint) ) {
        *ppv = &pCMe->m_pVTblICP;
        pCMe->m_pVTblICP->AddRef((IEcoConnectionPoint*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblICP;
        pCMe->m_pVTblICP->AddRef((IEcoConnectionPoint*)pCMe);
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
 *   Функция
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_AddRef(/* in */ struct IEcoConnectionPoint* me) {
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]*)me;

    if (me == 0 ) {
        return -1;
    }

    return pCMe->m_pICPC->pVTbl->AddRef(pCMe->m_pICPC);
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_Release(/* in */ struct IEcoConnectionPoint* me) {
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]*)me;

    if (me == 0 ) {
        return -1;
    }

    return pCMe->m_pICPC->pVTbl->Release(pCMe->m_pICPC);
}

/*
 *
 * <сводка>
 *   Функция GetConnectionInterface
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_GetConnectionInterface(/* in */ struct IEcoConnectionPoint* me, /* out */ UGUID *pIID) {
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]*)me;

    if (me == 0 || pIID == 0) {
        return -1;
    }

    pIID = (UGUID *)&pCMe->m_piid;
    return 0;
}

/*
 *
 * <сводка>
 *   Функция GetConnectionPointContainer
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
 int16_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_GetConnectionPointContainer(/* in */ struct IEcoConnectionPoint* me, /* out */ struct IEcoConnectionPointContainer **ppICPC) {
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]*)me;

    if (me == 0 || ppICPC == 0) {
        return -1;
    }

    *ppICPC = pCMe->m_pICPC;
    pCMe->m_pICPC->pVTbl->AddRef(pCMe->m_pICPC);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Advise
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_Advise(/* in */ struct IEcoConnectionPoint* me, /* in */ struct IEcoUnknown *pUnkSink, /* out */ uint32_t *pcCookie) {
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]*)me;
    int16_t result = 0;
    EcoConnectionData* pCD = 0;

    if (me == 0 || pUnkSink == 0 || pcCookie == 0) {
        return -1;
    }

    pCD = (EcoConnectionData*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, sizeof(EcoConnectionData));

    result = pUnkSink->pVTbl->QueryInterface(pUnkSink, pCMe->m_piid, (void**)&pCD->pUnk);
    if (result == 0 && pCD->pUnk != 0) {
        pCD->cCookie = ++pCMe->m_cNextCookie;

        /* Добавление в список */
        pCMe->m_pSinkList->pVTbl->Add(pCMe->m_pSinkList, pCD);

        /* Возвращение куки */
        *pcCookie = pCD->cCookie;
        return 0;
    }

    return -1;
}

/*
 *
 * <сводка>
 *   Функция Unadvise
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_Unadvise(/* in */ struct IEcoConnectionPoint* me, /* in */ uint32_t cCookie) {
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]*)me;
    EcoConnectionData* pCD = 0;
    IEcoUnknown* pSink = 0;
    uint32_t indx = 0;
    uint32_t count = 0;

    if (me == 0 ) {
        return -1;
    }

    count = pCMe->m_pSinkList->pVTbl->Count(pCMe->m_pSinkList);
    for (indx = 0; indx < count; indx++) {
        pCD = (EcoConnectionData*)pCMe->m_pSinkList->pVTbl->Item(pCMe->m_pSinkList, indx);
        if (pCD->cCookie == cCookie) {
            pSink = pCD->pUnk;

            /* Удаление из саиска */
            pCMe->m_pSinkList->pVTbl->RemoveAt(pCMe->m_pSinkList, indx);
            pSink->pVTbl->Release(pSink);
            pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, pCD);
            return 0;
        }
    }
    return -1;
}

/*
 *
 * <сводка>
 *   Функция EnumConnections
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_EnumConnections(/* in */ struct IEcoConnectionPoint* me, /* out */ struct IEcoEnumConnections **ppEnum) {
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]* pCMe = (C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]*)me;

    if (me == 0 || ppEnum == 0 ) {
        return -1;
    }

    /* Создание нумератора подключений1 */
    return createC[!output FIX_PROJECT_NAME]EnumConnections[!output GUID_CID_NAMESPACE]((IEcoUnknown*)pCMe->m_pISys, pCMe->m_pSinkList, ppEnum);
}

/* Create Virtual Table IEcoConnectionPointVTbl */
IEcoConnectionPointVTbl g_x0000000300000000C000000000000046VTblCP[!output GUID_CID_NAMESPACE] = {
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_QueryInterface,
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_AddRef,
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_Release,
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_GetConnectionInterface,
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_GetConnectionPointContainer,
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_Advise,
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_Unadvise,
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]_EnumConnections
};

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
int16_t ECOCALLMETHOD createC[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE](/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoConnectionPointContainer* pICPC, /* in */ const UGUID* riid, /* out */ IEcoConnectionPoint** ppICP) {
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]* pCMe = 0;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;	
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;		
    int16_t result = -1;

    /* Проверка указателей */
    if (ppICP == 0 || pIUnkSystem == 0 || pICPC == 0) {
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
    pCMe = (C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]*)pIMem->pVTbl->Alloc(pIMem, sizeof(C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;
    pCMe->m_cNextCookie = 0;

    /* Внешний компонент */
    pCMe->m_pICPC = pICPC;
    pCMe->m_piid = (UGUID*)riid;

    /* Создание таблицы функций интерфейса IEcoConnectionPoint */
    pCMe->m_pVTblICP = &g_x0000000300000000C000000000000046VTblCP[!output GUID_CID_NAMESPACE];
	

    /* Создание экземпляра работы со списком */
    pCMe->m_pSinkList = 0;
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pCMe->m_pSinkList);
    if (result != 0 || pCMe->m_pSinkList == 0) {
        deleteC[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]((IEcoConnectionPoint*)pCMe);
        return result;
    }

    /* Возврат указателя на интерфейс */
    *ppICP = (IEcoConnectionPoint*)pCMe;

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
void ECOCALLMETHOD deleteC[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE](/* in */ IEcoConnectionPoint* pICP) {
    C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]* pCMe = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    EcoConnectionData* pCD = 0;
    uint32_t count = 0;
    uint32_t index = 0;

    if (pICP != 0 ) {
        /* Преобразование */
        pCMe = (C[!output FIX_PROJECT_NAME]ConnectionPoint[!output GUID_CID_NAMESPACE]*)pICP;
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if (pCMe->m_pSinkList != 0) {
            count = pCMe->m_pSinkList->pVTbl->Count(pCMe->m_pSinkList);
            for (index = 0; index < count; index++) {
                pCD = (EcoConnectionData*)pCMe->m_pSinkList->pVTbl->Item(pCMe->m_pSinkList, index);
                pIMem->pVTbl->Free(pIMem, pCD);
            }
            pCMe->m_pSinkList->pVTbl->Clear(pCMe->m_pSinkList);
            pCMe->m_pSinkList->pVTbl->Release(pCMe->m_pSinkList);
        }
        if (pCMe->m_pISys != 0) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
            pCMe->m_pISys = 0;
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
