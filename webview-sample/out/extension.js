"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.deactivate = exports.activate = void 0;
const vscode = require("vscode");
const path = require("path");
const fs = require("fs");
class MyFileSystemProvider {
    constructor() {
        this.onDidChangeFile = new vscode.EventEmitter().event;
    }
    createDirectory(uri) {
        const directoryPath = uri.path;
        const fullDirectoryPath = path.join(vscode.workspace.rootPath || '', directoryPath);
        //function createFolders(strProjectPath: string, bUnitTestProject: boolean, strProjectName: string): void {
        const strProjectPath = directoryPath;
        const strProjectName = 'Eco.Component';
        const bUnitTestProject = false;
        console.log('Create folders');
        try {
            const objFSO = fs;
            if (!objFSO.existsSync(strProjectPath)) {
                objFSO.mkdirSync(strProjectPath);
            }
            const pathAssemblyFiles = path.join(strProjectPath, 'AssemblyFiles');
            if (!objFSO.existsSync(pathAssemblyFiles)) {
                objFSO.mkdirSync(pathAssemblyFiles);
            }
            const pathDesignFiles = path.join(strProjectPath, 'DesignFiles');
            if (!fs.existsSync(pathDesignFiles)) {
                fs.mkdirSync(pathDesignFiles);
            }
            const pathBuildFiles = path.join(strProjectPath, 'BuildFiles');
            if (!fs.existsSync(pathBuildFiles)) {
                fs.mkdirSync(pathBuildFiles);
            }
            const pathHeaderFiles = path.join(strProjectPath, 'HeaderFiles');
            if (!fs.existsSync(pathHeaderFiles)) {
                fs.mkdirSync(pathHeaderFiles);
            }
            const pathSharedFiles = path.join(strProjectPath, 'SharedFiles');
            if (!fs.existsSync(pathSharedFiles)) {
                fs.mkdirSync(pathSharedFiles);
            }
            const pathSourceFiles = path.join(strProjectPath, 'SourceFiles');
            if (!fs.existsSync(pathSourceFiles)) {
                fs.mkdirSync(pathSourceFiles);
            }
            // Android
            const pathAndroid = path.join(pathAssemblyFiles, 'Android');
            if (!fs.existsSync(pathAndroid)) {
                fs.mkdirSync(pathAndroid);
            }
            const pathAndroidNDK120 = path.join(pathAndroid, 'Android_NDK_12_0');
            if (!fs.existsSync(pathAndroidNDK120)) {
                fs.mkdirSync(pathAndroidNDK120);
            }
            const pathAndroidJNI = path.join(pathAndroidNDK120, 'jni');
            if (!fs.existsSync(pathAndroidJNI)) {
                fs.mkdirSync(pathAndroidJNI);
            }
            // AVR8
            const pathAVR8 = path.join(pathAssemblyFiles, 'AVR8');
            if (!fs.existsSync(pathAVR8)) {
                fs.mkdirSync(pathAVR8);
            }
            const pathAtmelStudio70 = path.join(pathAVR8, 'AtmelStudio_7_0');
            if (!fs.existsSync(pathAtmelStudio70)) {
                fs.mkdirSync(pathAtmelStudio70);
            }
            // BCM283x
            const pathBCM283x = path.join(pathAssemblyFiles, 'BCM283x');
            if (!fs.existsSync(pathBCM283x)) {
                fs.mkdirSync(pathBCM283x);
            }
            const pathGCC750 = path.join(pathBCM283x, 'gcc_7_5_0');
            if (!fs.existsSync(pathGCC750)) {
                fs.mkdirSync(pathGCC750);
            }
            // iOS
            const pathIOS = path.join(pathAssemblyFiles, 'iOS');
            if (!fs.existsSync(pathIOS)) {
                fs.mkdirSync(pathIOS);
            }
            const pathXcode123iOS = path.join(pathIOS, 'Xcode_12_3');
            if (!fs.existsSync(pathXcode123iOS)) {
                fs.mkdirSync(pathXcode123iOS);
            }
            // Linux
            const pathLinux = path.join(pathAssemblyFiles, 'Linux');
            if (!fs.existsSync(pathLinux)) {
                fs.mkdirSync(pathLinux);
            }
            const pathGCC740 = path.join(pathLinux, 'gcc_7_4_0');
            if (!fs.existsSync(pathGCC740)) {
                fs.mkdirSync(pathGCC740);
            }
            // Mac
            const pathMac = path.join(strProjectPath, 'Mac');
            if (!fs.existsSync(pathMac)) {
                fs.mkdirSync(pathMac);
            }
            const pathXcode123Mac = path.join(pathMac, 'Xcode_12_3');
            if (!fs.existsSync(pathXcode123Mac)) {
                fs.mkdirSync(pathXcode123Mac);
            }
            const pathMacPrj = path.join(pathXcode123Mac, `${strProjectName}.xcodeproj`);
            if (!fs.existsSync(pathMacPrj)) {
                fs.mkdirSync(pathMacPrj);
            }
            const pathMacShared = path.join(pathMacPrj, 'xcshareddata');
            if (!fs.existsSync(pathMacShared)) {
                fs.mkdirSync(pathMacShared);
            }
            const pathMacSchemes = path.join(pathMacShared, 'xcschemes');
            if (!fs.existsSync(pathMacSchemes)) {
                fs.mkdirSync(pathMacSchemes);
            }
            const pathMacWork = path.join(pathMacPrj, 'project.xcworkspace');
            if (!fs.existsSync(pathMacWork)) {
                fs.mkdirSync(pathMacWork);
            }
            const pathMacSharedWork = path.join(pathMacWork, 'xcshareddata');
            if (!fs.existsSync(pathMacSharedWork)) {
                fs.mkdirSync(pathMacSharedWork);
            }
            const pathMacPrjUnit = path.join(pathXcode123Mac, `${strProjectName}UnitTest.xcodeproj`);
            if (!fs.existsSync(pathMacPrjUnit)) {
                fs.mkdirSync(pathMacPrjUnit);
            }
            const pathMacSharedUnit = path.join(pathMacPrjUnit, 'xcshareddata');
            if (!fs.existsSync(pathMacSharedUnit)) {
                fs.mkdirSync(pathMacSharedUnit);
            }
            const pathMacSchemesUnit = path.join(pathMacSharedUnit, 'xcschemes');
            if (!fs.existsSync(pathMacSchemesUnit)) {
                fs.mkdirSync(pathMacSchemesUnit);
            }
            const pathMacWorkUnit = path.join(pathMacPrjUnit, 'project.xcworkspace');
            if (!fs.existsSync(pathMacWorkUnit)) {
                fs.mkdirSync(pathMacWorkUnit);
            }
            const pathMacSharedWorkUnit = path.join(pathMacWorkUnit, 'xcshareddata');
            if (!fs.existsSync(pathMacSharedWorkUnit)) {
                fs.mkdirSync(pathMacSharedWorkUnit);
            }
            // K210
            const pathK210 = path.join(strProjectPath, 'AssemblyFiles', 'K210');
            if (!fs.existsSync(pathK210)) {
                fs.mkdirSync(pathK210);
            }
            const pathGCCriscv64 = path.join(pathK210, 'gcc_riscv64_8_2_0');
            if (!fs.existsSync(pathGCCriscv64)) {
                fs.mkdirSync(pathGCCriscv64);
            }
            // PIC32
            const pathPIC32 = path.join(strProjectPath, 'AssemblyFiles', 'PIC32');
            if (!fs.existsSync(pathPIC32)) {
                fs.mkdirSync(pathPIC32);
            }
            const pathMPLABXIDE550 = path.join(pathPIC32, 'MPLAB_X_IDE_5_50');
            if (!fs.existsSync(pathMPLABXIDE550)) {
                fs.mkdirSync(pathMPLABXIDE550);
            }
            // Additional PIC32 folders
            const pathPIC32Build = path.join(strProjectPath, 'BuildFiles', 'PIC32');
            if (!fs.existsSync(pathPIC32Build)) {
                fs.mkdirSync(pathPIC32Build);
            }
            const pathDebug = path.join(pathPIC32Build, 'StaticDebug');
            if (!fs.existsSync(pathDebug)) {
                fs.mkdirSync(pathDebug);
            }
            const pathRelease = path.join(pathPIC32Build, 'StaticRelease');
            if (!fs.existsSync(pathRelease)) {
                fs.mkdirSync(pathRelease);
            }
            // STM32
            const pathSTM32 = path.join(pathAssemblyFiles, 'STM32');
            if (!fs.existsSync(pathSTM32)) {
                fs.mkdirSync(pathSTM32);
            }
            const pathSTM32CubeIDE170 = path.join(pathSTM32, 'STM32CubeIDE_1_7_0');
            if (!fs.existsSync(pathSTM32CubeIDE170)) {
                fs.mkdirSync(pathSTM32CubeIDE170);
            }
            const pathSTM32Set = path.join(pathSTM32CubeIDE170, '.metadata');
            if (!fs.existsSync(pathSTM32Set)) {
                fs.mkdirSync(pathSTM32Set);
            }
            // STM32 BuildFiles
            const pathSTM32Build = path.join(pathBuildFiles, 'STM32');
            if (!fs.existsSync(pathSTM32Build)) {
                fs.mkdirSync(pathSTM32Build);
            }
            const pathDebugSTM32 = path.join(pathSTM32Build, 'StaticDebug');
            if (!fs.existsSync(pathDebugSTM32)) {
                fs.mkdirSync(pathDebugSTM32);
            }
            const pathReleaseSTM32 = path.join(pathSTM32Build, 'StaticRelease');
            if (!fs.existsSync(pathReleaseSTM32)) {
                fs.mkdirSync(pathReleaseSTM32);
            }
            // Windows
            const pathWindows = path.join(pathAssemblyFiles, 'Windows');
            if (!fs.existsSync(pathWindows)) {
                fs.mkdirSync(pathWindows);
            }
            const pathVisualStudio2010 = path.join(pathWindows, 'VisualStudio_10');
            if (!fs.existsSync(pathVisualStudio2010)) {
                fs.mkdirSync(pathVisualStudio2010);
            }
            if (bUnitTestProject) {
                const pathUnitTestFiles = path.join(strProjectPath, 'UnitTestFiles');
                if (!fs.existsSync(pathUnitTestFiles)) {
                    fs.mkdirSync(pathUnitTestFiles);
                }
                const pathSourceFiles = path.join(pathUnitTestFiles, 'SourceFiles');
                if (!fs.existsSync(pathSourceFiles)) {
                    fs.mkdirSync(pathSourceFiles);
                }
            }
            return;
        }
        catch (e) {
            throw e;
        }
        //}
        if (!fs.existsSync(fullDirectoryPath)) {
            fs.mkdirSync(fullDirectoryPath, { recursive: true });
            vscode.window.showInformationMessage('Directory successfully created.');
        }
        else {
            vscode.window.showInformationMessage('Directory already exists.');
        }
    }
    delete(uri) {
        // Реализация метода delete
    }
    readFile(uri) {
        // Реализация метода readFile
        return new Uint8Array();
    }
    writeFile(uri, content, options) {
        // Реализация метода writeFile
    }
    stat(uri) {
        // Реализация метода stat
        return {
            type: vscode.FileType.File,
            ctime: 0,
            mtime: 0,
            size: 0
        };
    }
    readDirectory(uri) {
        // Реализация метода readDirectory
        return [];
    }
    rename(oldUri, newUri, options) {
        // Реализация метода rename
    }
    watch(uri, options) {
        return new vscode.Disposable(() => {
            // Реализация метода watch
        });
    }
}
const myFileSystemProvider = new MyFileSystemProvider();
function activate(context) {
    console.log('Поздравляем, ваше расширение "EcoCPeerf" теперь активно!');
    const strProjectName = 'Demo'; // Ваше имя проекта
    console.log('Данные успешно записались, имя проекта :', strProjectName);
    const newDirUri = vscode.Uri.parse(`D:\\${strProjectName}`);
    vscode.workspace.fs.createDirectory(newDirUri);
    console.log('Activate createDirectory');
    // Маппинг имен файлов на целевые пути
    const mappings = {
        "root": `SourceFiles\\${strProjectName}${strProjectName}`,
        "IROOT": `SharedFiles\\I${strProjectName}${strProjectName}`,
        "IdROOT": `SharedFiles\\Id${strProjectName}${strProjectName}`,
        "ErrROOT": `SharedFiles\\Err${strProjectName}${strProjectName}`,
        "CROOT.h": `HeaderFiles\\C${strProjectName}.h`,
        "Macproject.pbxproj": `AssemblyFiles\\Mac\\Xcode_12_3\\${strProjectName}.xcodeproj\\project.pbxproj`,
        "Maccontents.xcworkspacedata": `AssemblyFiles\\Mac\\Xcode_12_3\\${strProjectName}.xcodeproj\\project.xcworkspace\\contents.xcworkspacedata`,
        "MacIDEWorkspaceChecks.plist": `AssemblyFiles\\Mac\\Xcode_12_3\\${strProjectName}.xcodeproj\\project.xcworkspace\\xcshareddata\\IDEWorkspaceChecks.plist`,
        "MacWorkspaceSettings.xcsettings": `AssemblyFiles\\Mac\\Xcode_12_3\\${strProjectName}.xcodeproj\\project.xcworkspace\\xcshareddata\\WorkspaceSettings.xcsettings`,
        "MacDynamic.xcscheme": `AssemblyFiles\\Mac\\Xcode_12_3\\${strProjectName}.xcodeproj\\xcshareddata\\xcschemes\\Dynamic.xcscheme`,
        "MacStatic.xcscheme": `AssemblyFiles\\Mac\\Xcode_12_3\\${strProjectName}.xcodeproj\\xcshareddata\\xcschemes\\Static.xcscheme`,
        "MacUnitproject.pbxproj": `AssemblyFiles\\Mac\\Xcode_12_3\\${strProjectName}UnitTest.xcodeproj\\project.pbxproj`,
        "MacUnitcontents.xcworkspacedata": `AssemblyFiles\\Mac\\Xcode_12_3\\${strProjectName}UnitTest.xcodeproj\\project.xcworkspace\\contents.xcworkspacedata`,
        "MacUnitIDEWorkspaceChecks.plist": `AssemblyFiles\\Mac\\Xcode_12_3\\${strProjectName}UnitTest.xcodeproj\\project.xcworkspace\\xcshareddata\\IDEWorkspaceChecks.plist`,
        "MacUnitWorkspaceSettings.xcsettings": `AssemblyFiles\\Mac\\Xcode_12_3\\${strProjectName}UnitTest.xcodeproj\\project.xcworkspace\\xcshareddata\\WorkspaceSettings.xcsettings`,
        "IOSproject.pbxproj": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}.xcodeproj\\project.pbxproj`,
        "IOScontents.xcworkspacedata": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}.xcodeproj\\project.xcworkspace\\contents.xcworkspacedata`,
        "IOSIDEWorkspaceChecks.plist": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}.xcodeproj\\project.xcworkspace\\xcshareddata\\IDEWorkspaceChecks.plist`,
        "IOSWorkspaceSettings.xcsettings": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}.xcodeproj\\project.xcworkspace\\xcshareddata\\WorkspaceSettings.xcsettings`,
        "IOSUnitproject.pbxproj": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}UnitTest.xcodeproj\\project.pbxproj`,
        "IOSUnitcontents.xcworkspacedata": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}UnitTest.xcodeproj\\project.xcworkspace\\contents.xcworkspacedata`,
        "IOSUnitIDEWorkspaceChecks.plist": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}UnitTest.xcodeproj\\project.xcworkspace\\xcshareddata\\IDEWorkspaceChecks.plist`,
        "IOSUnitWorkspaceSettings.xcsettings": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}UnitTest.xcodeproj\\project.xcworkspace\\xcshareddata\\WorkspaceSettings.xcsettings`,
        "IOSUnitInfo.plist": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}UnitTest\\Info.plist`,
        "IOSUnitMain.storyboard": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}UnitTest\\Base.lproj\\Main.storyboard`,
        "peerFont_1251.bmp": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}UnitTest\\Base.lproj\\peerFont_1251.bmp`,
        "IOSUnitContents.json": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}UnitTest\\Assets.xcassets\\Contents.json`,
        "IOSUnitColorContents.json": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}UnitTest\\Assets.xcassets\\ColorContents.json`,
        "IOSUnitIconContents.json": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}UnitTest\\Assets.xcassets\\IconContents.json`,
        "IOSUnitMapContents.json": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}UnitTest\\Assets.xcassets\\MapContents.json`,
        "IOSUnitColorMap.png": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}UnitTest\\Assets.xcassets\\ColorMap.png`,
        "IOSUnitMipContents.json": `AssemblyFiles\\iOS\\Xcode_12_3\\${strProjectName}UnitTest\\Assets.xcassets\\MipContents.json`,
        "IOSUnitAppDelegate.m": `UnitTestFiles\\SourceFiles\\AppDelegate.m`,
        "IOSUnitEcoDemoDialogIOS.m": `UnitTestFiles\\SourceFiles\\EcoDemoDialogIOS.m`,
        "IOSUnitGameViewController.m": `UnitTestFiles\\SourceFiles\\GameViewController.m`,
        "IOSUnitAppDelegate.h": `UnitTestFiles\\HeaderFiles\\AppDelegate.h`,
        "IOSUnitEcoDemoDialog.h": `UnitTestFiles\\HeaderFiles\\EcoDemoDialog.h`,
        "IOSUnitGameViewController.h": `UnitTestFiles\\HeaderFiles\\GameViewController.h`,
        "BCM283xMakefile": `AssemblyFiles\\BCM283x\\gcc_7_5_0\\Makefile`,
        "K210Makefile": `AssemblyFiles\\K210\\gcc_riscv64_8_2_0\\Makefile`,
        "K210MakefileExe": `AssemblyFiles\\K210\\gcc_riscv64_8_2_0\\MakefileExe`,
        "K210entry.S": `AssemblyFiles\\K210\\gcc_riscv64_8_2_0\\entry.S`,
        "K210startup.ld": `AssemblyFiles\\K210\\gcc_riscv64_8_2_0\\startup.ld`,
        "K210upload.bat": `AssemblyFiles\\K210\\gcc_riscv64_8_2_0\\upload.bat`,
        "ROOT.atsln": `AssemblyFiles\\AVR8\\AtmelStudio_7_0\\${strProjectName}.atsln`,
        "ROOT.cproj": `AssemblyFiles\\AVR8\\AtmelStudio_7_0\\${strProjectName}.cproj`,
        "ROOT.componentinfo.xml": `AssemblyFiles\\AVR8\\AtmelStudio_7_0\\${strProjectName}.componentinfo.xml`,
        "ROOTUnitTest.cproj": `AssemblyFiles\\AVR8\\AtmelStudio_7_0\\${strProjectName}UnitTest.cproj`,
        "ROOTUnitTest.componentinfo.xml": `AssemblyFiles\\AVR8\\AtmelStudio_7_0\\${strProjectName}UnitTest.componentinfo.xml`,
        "AVR8upload.bat": `AssemblyFiles\\AVR8\\AtmelStudio_7_0\\upload.bat`,
        "PIC32project.xml": `AssemblyFiles\\PIC32\\MPLAB_X_IDE_5_50\\nbproject\\project.xml`,
        "PIC32configurations.xml": `AssemblyFiles\\PIC32\\MPLAB_X_IDE_5_50\\nbproject\\configurations.xml`,
        "PIC32Makefile": `AssemblyFiles\\PIC32\\MPLAB_X_IDE_5_50\\Makefile`,
        "STM32.cproject": `AssemblyFiles\\STM32\\STM32CubeIDE_1_7_0\\${strProjectName}.cproject`,
        "STM32.project": `AssemblyFiles\\STM32\\STM32CubeIDE_1_7_0\\${strProjectName}.project`,
        "STM32language.settings.xml": `AssemblyFiles\\STM32\\STM32CubeIDE_1_7_0\\${strProjectName}\\.settings\\language.settings.xml`,
        "STM32Unit.cproject": `AssemblyFiles\\STM32\\STM32CubeIDE_1_7_0\\${strProjectName}UnitTest.cproject`,
        "STM32Unit.project": `AssemblyFiles\\STM32\\STM32CubeIDE_1_7_0\\${strProjectName}UnitTest.project`,
        "STM32Unitlanguage.settings.xml": `AssemblyFiles\\STM32\\STM32CubeIDE_1_7_0\\${strProjectName}UnitTest\\.settings\\language.settings.xml`,
        "STM32F407VGTX_FLASH.ld": `AssemblyFiles\\STM32\\STM32CubeIDE_1_7_0\\${strProjectName}UnitTest\\STM32F407VGTX_FLASH.ld`,
        "STM32F407VGTX_RAM.ld": `AssemblyFiles\\STM32\\STM32CubeIDE_1_7_0\\${strProjectName}UnitTest\\STM32F407VGTX_RAM.ld`,
        "STM32ROOT.cfg": `AssemblyFiles\\STM32\\STM32CubeIDE_1_7_0\\${strProjectName}UnitTest\\${strProjectName}ROOT.cfg`,
        "STM32ROOT.launch": `AssemblyFiles\\STM32\\STM32CubeIDE_1_7_0\\${strProjectName}UnitTest\\${strProjectName}ROOT.launch`,
        "startup_stm32f407vgtx.s": `AssemblyFiles\\STM32\\STM32CubeIDE_1_7_0\\${strProjectName}UnitTest\\Startup\\startup_stm32f407vgtx.s`,
        "LinuxMakefile": `AssemblyFiles\\Linux\\gcc_7_4_0\\Makefile`,
        "LinuxMakefileExe": `AssemblyFiles\\Linux\\gcc_7_4_0\\MakefileExe`,
        "Linuxbuild.sh": `AssemblyFiles\\Linux\\gcc_7_4_0\\build.sh`,
        "Android.bat": `AssemblyFiles\\Android\\Android_NDK_12_0\\${strProjectName}.bat`,
        "Android.mk": `AssemblyFiles\\Android\\Android_NDK_12_0\\jni\\Android.mk`,
        "Application.mk": `AssemblyFiles\\Android\\Android_NDK_12_0\\jni\\Application.mk`,
        "AndroidROOTUnitTest.sln": `AssemblyFiles\\Android\\NsightTegra_3_4\\${strProjectName}UnitTest.sln`,
        "AndroidROOTUnitTest.vcxproj": `AssemblyFiles\\Android\\NsightTegra_3_4\\${strProjectName}UnitTest.vcxproj`,
        "AndroidROOTUnitTest.vcxproj.filters": `AssemblyFiles\\Android\\NsightTegra_3_4\\${strProjectName}UnitTest.vcxproj.filters`,
        "UnitTestAndroidManifest.xml": `AssemblyFiles\\Android\\NsightTegra_3_4\\UnitTestAndroidManifest.xml`,
        "Androidstrings.xml": `AssemblyFiles\\Android\\NsightTegra_3_4\\res\\values\\strings.xml`,
        "CROOTFactory.h": `HeaderFiles\\C${strProjectName}Factory.h`,
        "CROOTFactory.c": `SourceFiles\\C${strProjectName}Factory.c`,
        "CROOTConnectionPoint.c": `SourceFiles\\C${strProjectName}ConnectionPoint.c`,
        "CROOTConnectionPoint.h": `HeaderFiles\\C${strProjectName}ConnectionPoint.h`,
        "CROOTEnumConnectionPoints.c": `SourceFiles\\C${strProjectName}`,
        "CROOTEnumConnectionPoints.h": `HeaderFiles\\C${strProjectName}`,
        "CROOTEnumConnections.c": `SourceFiles\\C${strProjectName}`,
        "CROOTEnumConnections.h": `HeaderFiles\\C${strProjectName}`,
        "CROOTSink.c": `SourceFiles\\C${strProjectName}`,
        "CROOTSink.h": `HeaderFiles\\C${strProjectName}`,
        "IEcoConnectionPoint.h": "SharedFiles\\IEcoConnectionPoint.h",
        "IEcoConnectionPointContainer.h": "SharedFiles\\IEcoConnectionPointContainer.h",
        "IEcoEnumConnectionPoints.h": "SharedFiles\\IEcoEnumConnectionPoints.h",
        "IEcoEnumConnections.h": "SharedFiles\\IEcoEnumConnections.h",
        "pathWindows": `AssemblyFiles\\Windows`,
        "pathVisualStudio2010": `AssemblyFiles\\Windows\\VisualStudio_10`,
        "pathUnitTestFiles": `UnitTestFiles`,
        "pathSourceFiles": `UnitTestFiles\\SourceFiles`,
        "pathDesignFiles": `DesignFiles`,
        "pathBuildFiles": `BuildFiles`,
    };
    const templatesFolder = path.join(context.extensionPath, 'templates');
    function createFile(strName) {
        try {
            if (mappings.hasOwnProperty(strName)) {
                const targetPath = mappings[strName];
                const templateFilePath = path.join(templatesFolder, strName);
                // Копирование файла из шаблона и переименование
                const fileUri = vscode.Uri.file(path.join(newDirUri.fsPath, targetPath));
                vscode.workspace.fs.copy(vscode.Uri.file(templateFilePath), fileUri, { overwrite: false });
                console.log('Файл создан:', targetPath);
                return targetPath;
            }
            console.error("Маппинг не найден для:", strName);
            return ""; // Возвращаем пустую строку в случае отсутствия соответствия
        }
        catch (error) {
            console.error("Ошибка при создании файла:", error);
            return ""; // Возвращаем пустую строку в случае ошибки
        }
    }
    let disposable = vscode.commands.registerCommand('catCoding.start', () => {
        const panelHtmlPath = vscode.Uri.file(path.join(context.extensionPath, 'Html', 'AppSeting.html'));
        EcoCPeerfPanel.createOrShow(context.extensionUri, panelHtmlPath);
        // Создание всех файлов из маппинга
        for (const fileName in mappings) {
            if (mappings.hasOwnProperty(fileName)) {
                const filePath = createFile(fileName);
                if (filePath !== '') {
                    console.log('Файл создан:', filePath);
                }
                else {
                    console.error('Не удалось создать файл:', fileName);
                }
            }
        }
        // Создание папок, если они не существуют
        const directoriesToCreate = [
            mappings['pathWindows'],
            mappings['pathVisualStudio2010'],
            mappings['pathUnitTestFiles'],
            mappings['pathSourceFiles'],
            mappings['pathDesignFiles'],
            mappings['pathBuildFiles']
        ];
        directoriesToCreate.forEach(dir => {
            const dirPath = path.join(newDirUri.fsPath, dir);
            if (!fs.existsSync(dirPath)) {
                fs.mkdirSync(dirPath, { recursive: true });
                console.log(`Папка создана: ${dirPath}`);
            }
        });
    });
    context.subscriptions.push(disposable);
}
exports.activate = activate;
function deactivate() { }
exports.deactivate = deactivate;
class EcoCPeerfPanel {
    static createOrShow(extensionUri, panelHtmlPath) {
        const column = vscode.window.activeTextEditor ? vscode.window.activeTextEditor.viewColumn : undefined;
        if (EcoCPeerfPanel.currentPanel) {
            EcoCPeerfPanel.currentPanel._panel.reveal(column);
            return;
        }
        const panel = vscode.window.createWebviewPanel('ecoCPeerfPanel', 'EcoCPeerf', column || vscode.ViewColumn.One, {
            enableScripts: true,
            localResourceRoots: [vscode.Uri.file(path.join(extensionUri.fsPath, 'Html'))]
        });
        EcoCPeerfPanel.currentPanel = new EcoCPeerfPanel(panel, extensionUri, panelHtmlPath);
    }
    constructor(panel, extensionUri, panelHtmlPath) {
        this._disposables = [];
        this._panel = panel;
        this._extensionUri = extensionUri;
        this._panelHtmlPath = panelHtmlPath;
        this._update();
        this._panel.onDidDispose(() => this.dispose(), null, this._disposables);
        this._panel.onDidChangeViewState(e => {
            if (this._panel.visible) {
                this._update();
            }
        }, null, this._disposables);
    }
    dispose() {
        EcoCPeerfPanel.currentPanel = undefined;
        this._panel.dispose();
        while (this._disposables.length) {
            const x = this._disposables.pop();
            if (x) {
                x.dispose();
            }
        }
    }
    _update() {
        this._panel.webview.html = this._getHtmlContent(this._panelHtmlPath);
    }
    _getHtmlContent(htmlPath) {
        const page1Content = fs.readFileSync(path.join(this._extensionUri.fsPath, 'Html', 'page1.html'), 'utf8');
        const page2Content = fs.readFileSync(path.join(this._extensionUri.fsPath, 'Html', 'page2.html'), 'utf8');
        const page3Content = fs.readFileSync(path.join(this._extensionUri.fsPath, 'Html', 'page3.html'), 'utf8');
        return `
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Eco C Application Wizard</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            color: black; /* Черный цвет текста по умолчанию */
        }
        .window-container {
            width: 800px;
            height: 600px;
            resize: both;
            overflow: auto;
            border: 1px solid #ccc;
            border-radius: 5px;
            margin: 20px auto;
            position: relative;
        }
        .container {
            display: flex;
            flex-direction: column;
            height: 100%;
        }
        .header {
            background-color: #0078d4;
            color: white;
            text-align: center;
            padding: 20px;
        }
        .content {
            flex-grow: 1;
            display: flex;
        }
        .left-panel {
            width: 30%;
            background-color: #f0f0f0;
            padding: 20px;
        }
        .right-panel {
            flex-grow: 1;
            padding: 20px;
            background-color: white;
            color: black;
        }
        .link {
            cursor: pointer;
            text-decoration: underline;
            color: black;
        }
        .active {
            color: rgb(25, 0, 255);
        }
        img {
            max-width: 100%;
            height: auto;
        }
        iframe {
            width: 100%;
            height: 100%;
            border: none;
        }
        .bottom-menu {
            display: flex;
            justify-content: flex-end;
            padding: 20px;
            margin-top: 10px;
            background-color: white; /* Белый фон */
        }
        .button {
            margin-left: 10px;
            background-color: #007bff; /* Синий цвет */
            color: #fff; /* Белый текст */
            padding: 8px 16px; /* Уменьшенные отступы внутри кнопки */
            border: none; /* Убираем границу */
            border-radius: 4px; /* Закругляем углы */
            cursor: pointer; /* Изменяем курсор при наведении */
            transition: background-color 0.3s ease, color 0.3s ease; /* Плавное изменение цвета при наведении */
        }
        .button:hover {
            background-color: #fff; /* Белый фон при наведении */
            color: #007bff; /* Синий текст при наведении */
        }
        .button[disabled] {
            opacity: 0.5;
            cursor: not-allowed;
        }
    </style>
</head>
<body>
  <div class="window-container">
      <div class="container">
          <div class="header">
              <h1>Welcome to the Eco C for Windows Application Wizard</h1>
          </div>
          <div class="content">
              <div class="left-panel">
                  <p class="link" onclick="showPage(1)">Overview</p>
                  <p class="link" onclick="showPage(2)">Name and Path</p>
                  <p class="link" onclick="showPage(3)">Application Settings</p>
              </div>
              <div class="right-panel" id="right-panel">
                  <iframe id="pageFrame" src="page1.html"></iframe>
              </div>
          </div>
          <div class="bottom-menu">
            <button class="button" onclick="previousPage()" id="prevButton" disabled>Previous</button>
            <button class="button" onclick="nextPage()" id="nextButton">Next</button>
            <button class="button" onclick="finish()" id="finishButton" disabled>Finish</button>
            <button class="button" onclick="cancel()">Cancel</button>
        </div>        
      </div>
  </div>

    <script>
        var currentPage = 1;
        var totalPages = 3;
        var folderName = "";
        var folderPath = "";

        function showPage(pageNumber) {
            var pageUrl;
            if (pageNumber === 1) {
                pageUrl = "data:text/html;base64,${Buffer.from(page1Content).toString('base64')}";
            } else if (pageNumber === 2) {
                pageUrl = "data:text/html;base64,${Buffer.from(page2Content).toString('base64')}";
            } else if (pageNumber === 3) {
                pageUrl = "data:text/html;base64,${Buffer.from(page3Content).toString('base64')}";
            }
            document.getElementById("pageFrame").src = pageUrl;
            document.getElementById("pageFrame").src = pageUrl;
            currentPage = pageNumber;
            updateButtonState();
        }

        function nextPage(newDirUri) {
            if (currentPage < totalPages) {
                currentPage++;
                showPage(currentPage);

                // Получение данных со страницы 2
                var folderNameElement = document.getElementById("folderName");
                var folderPathElement = document.getElementById("folderPath");

                if (folderNameElement && folderPathElement) {
                    folderName = folderNameElement.value;
                    folderPath = folderPathElement.value;
                    console.log('Data collected:', folderName, folderPath);
                } else {
                    console.error('Error: Could not find folderName or folderPath element.');
                }
            }
        }


        function previousPage() {
            if (currentPage > 1) {
                currentPage--;
                showPage(currentPage);
            }
        }

        function finish() {
            // Проверяем, что данные для папки собраны
            if (folderName && folderPath) {
                // Создаем папку с указанным именем и путем
                createDirectory(folderName, folderPath);
            } else {
                console.error('Error: Folder name or path is missing.');
            }
        }

        function createDirectory(name, path) {
            // Здесь должен быть ваш код для создания папки
            console.log("Creating directory:", name, "at", path);
            alert("Directory created successfully!");
        }


        function cancel() {
            // Действия при отмене
        }

        function updateButtonState() {
            var prevButton = document.getElementById("prevButton");
            var nextButton = document.getElementById("nextButton");
            var finishButton = document.getElementById("finishButton");

            prevButton.disabled = currentPage === 1;
            nextButton.disabled = currentPage === totalPages;
            finishButton.disabled = currentPage !== totalPages;
        }

        window.onload = function() {
            updateButtonState();
            // Установка начальной страницы при загрузке
            showPage(1);
        };
       
    </script>
</body>
</html>

        `;
        const htmlContent = fs.readFileSync(htmlPath.fsPath, 'utf8');
        return htmlContent;
    }
}
//# sourceMappingURL=extension.js.map