"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");
class MyFileSystemProvider {
    async createDirectory(uri) {
        function createFolders(strProjectPath, bUnitTestProject, strProjectName) {
            try {
                const objFSO = new ActiveXObject("Scripting.FileSystemObject");
                // Create main project folder
                let folderProject;
                if (!objFSO.FolderExists(strProjectPath)) {
                    folderProject = objFSO.CreateFolder(strProjectPath);
                }
                // Create subfolders
                const pathAssemblyFiles = `${strProjectPath}\\AssemblyFiles`;
                let folderAssemblyFiles;
                if (!objFSO.FolderExists(pathAssemblyFiles)) {
                    folderAssemblyFiles = objFSO.CreateFolder(pathAssemblyFiles);
                }
                const pathDesignFiles = `${strProjectPath}\\DesignFiles`;
                let folderDesignFiles;
                if (!objFSO.FolderExists(pathDesignFiles)) {
                    folderDesignFiles = objFSO.CreateFolder(pathDesignFiles);
                }
                const pathBuildFiles = `${strProjectPath}\\BuildFiles`;
                let folderBuildFiles;
                if (!objFSO.FolderExists(pathBuildFiles)) {
                    folderBuildFiles = objFSO.CreateFolder(pathBuildFiles);
                }
                const pathHeaderFiles = `${strProjectPath}\\HeaderFiles`;
                let folderHeaderFiles;
                if (!objFSO.FolderExists(pathHeaderFiles)) {
                    folderHeaderFiles = objFSO.CreateFolder(pathHeaderFiles);
                }
                const pathSharedFiles = `${strProjectPath}\\SharedFiles`;
                let folderSharedFiles;
                if (!objFSO.FolderExists(pathSharedFiles)) {
                    folderSharedFiles = objFSO.CreateFolder(pathSharedFiles);
                }
                const pathSourceFiles = `${strProjectPath}\\SourceFiles`;
                let folderSourceFiles;
                if (!objFSO.FolderExists(pathSourceFiles)) {
                    folderSourceFiles = objFSO.CreateFolder(pathSourceFiles);
                }
                // Create subfolders for specific platforms
                const createSubfolderIfNotExists = (basePath, subfolderName) => {
                    const path = `${basePath}\\${subfolderName}`;
                    let folder;
                    if (!objFSO.FolderExists(path)) {
                        folder = objFSO.CreateFolder(path);
                    }
                    return folder;
                };
                // Android
                const folderAndroid = createSubfolderIfNotExists(pathAssemblyFiles, "Android");
                const folderAndroidNDK120 = createSubfolderIfNotExists(folderAndroid, "Android_NDK_12_0");
                const folderAndroidJNI = createSubfolderIfNotExists(folderAndroidNDK120, "jni");
                // AVR8
                const folderAVR8 = createSubfolderIfNotExists(pathAssemblyFiles, "AVR8");
                const folderAtmelStudio70 = createSubfolderIfNotExists(folderAVR8, "AtmelStudio_7_0");
                // BCM283x
                const folderBCM283x = createSubfolderIfNotExists(pathAssemblyFiles, "BCM283x");
                const folderGCC750 = createSubfolderIfNotExists(folderBCM283x, "gcc_7_5_0");
                // iOS
                const folderIOS = createSubfolderIfNotExists(pathAssemblyFiles, "iOS");
                const folderXcode123 = createSubfolderIfNotExists(folderIOS, "Xcode_12_3");
                // Linux
                const folderLinux = createSubfolderIfNotExists(pathAssemblyFiles, "Linux");
                const folderGCC740 = createSubfolderIfNotExists(folderLinux, "gcc_7_4_0");
                // Mac
                const pathMac = `${pathAssemblyFiles}\\Mac`;
                let folderMac;
                if (!objFSO.FolderExists(pathMac)) {
                    folderMac = objFSO.CreateFolder(pathMac);
                }
                const pathXcode123 = `${pathMac}\\Xcode_12_3`;
                let folderXcode123;
                if (!objFSO.FolderExists(pathXcode123)) {
                    folderXcode123 = objFSO.CreateFolder(pathXcode123);
                }
                const pathMacPrj = `${pathXcode123}\\${strProjectName}.xcodeproj`;
                let folderMacPrj;
                if (!objFSO.FolderExists(pathMacPrj)) {
                    folderMacPrj = objFSO.CreateFolder(pathMacPrj);
                }
                const pathMacShared = `${pathMacPrj}\\xcshareddata`;
                let folderMacShared;
                if (!objFSO.FolderExists(pathMacShared)) {
                    folderMacShared = objFSO.CreateFolder(pathMacShared);
                }
                const pathMacSchemes = `${pathMacShared}\\xcschemes`;
                let folderMacSchemes;
                if (!objFSO.FolderExists(pathMacSchemes)) {
                    folderMacSchemes = objFSO.CreateFolder(pathMacSchemes);
                }
                const pathMacWork = `${pathMacPrj}\\project.xcworkspace`;
                let folderMacWork;
                if (!objFSO.FolderExists(pathMacWork)) {
                    folderMacWork = objFSO.CreateFolder(pathMacWork);
                }
                const pathMacSharedWork = `${pathMacWork}\\xcshareddata`;
                let folderMacSharedWork;
                if (!objFSO.FolderExists(pathMacSharedWork)) {
                    folderMacSharedWork = objFSO.CreateFolder(pathMacSharedWork);
                }
                const pathMacPrjUnit = `${pathXcode123}\\${strProjectName}UnitTest.xcodeproj`;
                let folderMacPrjUnit;
                if (!objFSO.FolderExists(pathMacPrjUnit)) {
                    folderMacPrjUnit = objFSO.CreateFolder(pathMacPrjUnit);
                }
                const pathMacShared2 = `${pathMacPrjUnit}\\xcshareddata`;
                let folderMacShared2;
                if (!objFSO.FolderExists(pathMacShared2)) {
                    folderMacShared2 = objFSO.CreateFolder(pathMacShared2);
                }
                const pathMacSchemes2 = `${pathMacShared2}\\xcschemes`;
                let folderMacSchemes2;
                if (!objFSO.FolderExists(pathMacSchemes2)) {
                    folderMacSchemes2 = objFSO.CreateFolder(pathMacSchemes2);
                }
                const pathMacWork2 = `${pathMacPrjUnit}\\project.xcworkspace`;
                let folderMacWork2;
                if (!objFSO.FolderExists(pathMacWork2)) {
                    folderMacWork2 = objFSO.CreateFolder(pathMacWork2);
                }
                const pathMacSharedWork2 = `${pathMacWork2}\\xcshareddata`;
                let folderMacSharedWork2;
                if (!objFSO.FolderExists(pathMacSharedWork2)) {
                    folderMacSharedWork2 = objFSO.CreateFolder(pathMacSharedWork2);
                }
                // K210
                const pathK210 = `${pathAssemblyFiles}\\K210`;
                let folderK210;
                if (!objFSO.FolderExists(pathK210)) {
                    folderK210 = objFSO.CreateFolder(pathK210);
                }
                const pathGCCriscv64 = `${pathK210}\\gcc_riscv64_8_2_0`;
                let folderGCCriscv64;
                if (!objFSO.FolderExists(pathGCCriscv64)) {
                    folderGCCriscv64 = objFSO.CreateFolder(pathGCCriscv64);
                }
                // PIC32
                const pathPIC32 = `${pathAssemblyFiles}\\PIC32`;
                let folderPIC32;
                if (!objFSO.FolderExists(pathPIC32)) {
                    folderPIC32 = objFSO.CreateFolder(pathPIC32);
                }
                const pathMPLABXIDE550 = `${pathPIC32}\\MPLAB_X_IDE_5_50`;
                let folderMPLABXIDE550;
                if (!objFSO.FolderExists(pathMPLABXIDE550)) {
                    folderMPLABXIDE550 = objFSO.CreateFolder(pathMPLABXIDE550);
                }
                let pathBuildFiles = `${strProjectPath}\\BuildFiles`; // Fix redeclaration
                pathPIC32 = `${pathBuildFiles}\\PIC32`;
                if (!objFSO.FolderExists(pathPIC32)) {
                    folderPIC32 = objFSO.CreateFolder(pathPIC32);
                }
                const pathDebug = `${pathPIC32}\\StaticDebug`;
                let folderDebug;
                if (!objFSO.FolderExists(pathDebug)) {
                    folderDebug = objFSO.CreateFolder(pathDebug);
                }
                const pathRelease = `${pathPIC32}\\StaticRelease`;
                let folderRelease;
                if (!objFSO.FolderExists(pathRelease)) {
                    folderRelease = objFSO.CreateFolder(pathRelease);
                }
                // STM32
                const pathSTM32 = `${pathAssemblyFiles}\\STM32`;
                let folderSTM32;
                if (!objFSO.FolderExists(pathSTM32)) {
                    folderSTM32 = objFSO.CreateFolder(pathSTM32);
                }
                const pathSTM32CubeIDE170 = `${pathSTM32}\\STM32CubeIDE_1_7_0`;
                let folderSTM32CubeIDE170;
                if (!objFSO.FolderExists(pathSTM32CubeIDE170)) {
                    folderSTM32CubeIDE170 = objFSO.CreateFolder(pathSTM32CubeIDE170);
                }
                const pathSTM32Set = `${pathSTM32CubeIDE170}\\.metadata`;
                let folderSTM32Set;
                if (!objFSO.FolderExists(pathSTM32Set)) {
                    folderSTM32Set = objFSO.CreateFolder(pathSTM32Set);
                }
                let pathSTM32_2 = `${pathBuildFiles}\\STM32`; // Fix redeclaration
                const pathDebug_2 = `${pathSTM32_2}\\StaticDebug`;
                let folderDebug_2;
                if (!objFSO.FolderExists(pathDebug_2)) {
                    folderDebug_2 = objFSO.CreateFolder(pathDebug_2);
                }
                const pathRelease_2 = `${pathSTM32_2}\\StaticRelease`;
                let folderRelease_2;
                if (!objFSO.FolderExists(pathRelease_2)) {
                    folderRelease_2 = objFSO.CreateFolder(pathRelease_2);
                }
                // Windows
                const pathWindows = `${pathAssemblyFiles}\\Windows`;
                let folderWindows;
                if (!objFSO.FolderExists(pathWindows)) {
                    folderWindows = objFSO.CreateFolder(pathWindows);
                }
                const pathVisualStudio2010 = `${pathWindows}\\VisualStudio_10`;
                let folderVisualStudio2010;
                if (!objFSO.FolderExists(pathVisualStudio2010)) {
                    folderVisualStudio2010 = objFSO.CreateFolder(pathVisualStudio2010);
                }
                if (bUnitTestProject) {
                    const pathUnitTestFiles = `${strProjectPath}\\UnitTestFiles`;
                    let folderUnitTestFiles;
                    if (!objFSO.FolderExists(pathUnitTestFiles)) {
                        folderUnitTestFiles = objFSO.CreateFolder(pathUnitTestFiles);
                    }
                    pathSourceFiles = `${pathUnitTestFiles}\\SourceFiles`; // Fix redeclaration
                    let folderSourceFiles;
                    if (!objFSO.FolderExists(pathSourceFiles)) {
                        folderSourceFiles = objFSO.CreateFolder(pathSourceFiles);
                    }
                }
                return pathVisualStudio2010;
            }
            catch (error) {
                console.error(error);
            }
        }
    }
    async createFile(uri, content) {
        // Здесь реализуется логика создания нового файла
    }
}
const myFileSystemProvider = new MyFileSystemProvider();
const disposable = vscode.workspace.registerFileSystemProvider('myFileSystem', myFileSystemProvider);
const newDirUri = vscode.Uri.parse('myFileSystem:/newFolder/');
myFileSystemProvider.createDirectory(newDirUri);
const newFileUri = vscode.Uri.parse('myFileSystem:/newFolder/newFile.txt');
myFileSystemProvider.createFile(newFileUri);
//# sourceMappingURL=MyFileSystemProvider.js.map