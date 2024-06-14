[!if ECO_COM_APP]
/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   Id[!output FIX_PROJECT_NAME]
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс Id[!output FIX_PROJECT_NAME]
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __ID_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_H__
#define __ID_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_H__

#include "IEcoBase1.h"
#include "I[!output FIX_PROJECT_NAME].h"

/* [!output FIX_PROJECT_NAME] CID = [!output GUID_CID] */
#ifndef __CID_[!output FIX_PROJECT_NAME]
static const UGUID CID_[!output FIX_PROJECT_NAME] = [!output GUID_CID_FORMATED];
#endif /* __CID_[!output FIX_PROJECT_NAME] */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_[!output GUID_CID_TARGET];
#endif

#endif /* __ID_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_H__ */
[!endif]
