/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   [!output FIX_PROJECT_NAME]
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
[!if ECO_COM_APP]
#include "Id[!output FIX_PROJECT_NAME].h"
[!endif]
[!if ADD_CONNECTION_POINTS]
#include "C[!output FIX_PROJECT_NAME]Sink.h"
#include "IEcoConnectionPointContainer.h"
[!endif]

/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    char_t* name = 0;
[!if ECO_COM_APP]
    char_t* copyName = 0;
    /* Указатель на тестируемый интерфейс */
    I[!output FIX_PROJECT_NAME]* pI[!output FIX_PROJECT_NAME] = 0;
[!endif]
[!if ADD_CONNECTION_POINTS]
    /* Указатель на интерфейс контейнера точек подключения */
    IEcoConnectionPointContainer* pICPC = 0;
    /* Указатель на интерфейс точки подключения */
    IEcoConnectionPoint* pICP = 0;
    /* Указатель на обратный интерфейс */
    I[!output FIX_PROJECT_NAME]Events* pI[!output FIX_PROJECT_NAME]Sink = 0;
    IEcoUnknown* pISinkUnk = 0;
    uint32_t cAdvise = 0;
[!endif]

    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem1, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
[!if ECO_COM_APP]
#ifdef ECO_LIB
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_[!output FIX_PROJECT_NAME], (IEcoUnknown*)GetIEcoComponentFactoryPtr_[!output GUID_CID_TARGET]);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#endif
[!endif]
    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

    /* Выделение блока памяти */
    name = (char_t *)pIMem->pVTbl->Alloc(pIMem, 10);

    /* Заполнение блока памяти */
    pIMem->pVTbl->Fill(pIMem, name, 'a', 9);

[!if ECO_COM_APP]

    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_[!output FIX_PROJECT_NAME], 0, &IID_I[!output FIX_PROJECT_NAME], (void**) &pI[!output FIX_PROJECT_NAME]);
    if (result != 0 || pI[!output FIX_PROJECT_NAME] == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

[!if ADD_CONNECTION_POINTS]
    /* Проверка поддержки подключений обратного интерфейса */
    result = pI[!output FIX_PROJECT_NAME]->pVTbl->QueryInterface(pI[!output FIX_PROJECT_NAME], &IID_IEcoConnectionPointContainer, (void **)&pICPC);
    if (result != 0 || pICPC == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Запрос на получения интерфейса точки подключения */
    result = pICPC->pVTbl->FindConnectionPoint(pICPC, &IID_I[!output FIX_PROJECT_NAME]Events, &pICP);
    if (result != 0 || pICP == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }
    /* Освобождение интерфейса */
    pICPC->pVTbl->Release(pICPC);

    /* Создание экземпляра обратного интерфейса */
    result = createC[!output FIX_PROJECT_NAME]Sink(pIMem, (I[!output FIX_PROJECT_NAME]Events**)&pI[!output FIX_PROJECT_NAME]Sink);

    if (pI[!output FIX_PROJECT_NAME]Sink != 0) {
        result = pI[!output FIX_PROJECT_NAME]Sink->pVTbl->QueryInterface(pI[!output FIX_PROJECT_NAME]Sink, &IID_IEcoUnknown,(void **)&pISinkUnk);
        if (result != 0 || pISinkUnk == 0) {
            /* Освобождение интерфейсов в случае ошибки */
            goto Release;
        }
        /* Подключение */
        result = pICP->pVTbl->Advise(pICP, pISinkUnk, &cAdvise);
        /* Проверка */
        if (result == 0 && cAdvise == 1) {
            /* Сюда можно добавить код */
        }
        /* Освобождение интерфейса */
        pISinkUnk->pVTbl->Release(pISinkUnk);
    }

[!endif]

    result = pI[!output FIX_PROJECT_NAME]->pVTbl->MyFunction(pI[!output FIX_PROJECT_NAME], name, &copyName);

[!endif]

    /* Освлбождение блока памяти */
    pIMem->pVTbl->Free(pIMem, name);

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

[!if ECO_COM_APP]
    /* Освобождение тестируемого интерфейса */
    if (pI[!output FIX_PROJECT_NAME] != 0) {
        pI[!output FIX_PROJECT_NAME]->pVTbl->Release(pI[!output FIX_PROJECT_NAME]);
    }

[!endif]

    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

