call ndk-build clean
call ndk-build TARGET_LINK=0 NDK_DEBUG=0 CONFIGURATION=StaticRelease
call ndk-build TARGET_LINK=0 NDK_DEBUG=1 CONFIGURATION=StaticDebug
rmdir /s /q libs
rmdir /s /q obj
call ndk-build clean
call ndk-build TARGET_LINK=1 NDK_DEBUG=0 CONFIGURATION=DynamicRelease
call ndk-build TARGET_LINK=1 NDK_DEBUG=1 CONFIGURATION=DynamicDebug
rmdir /s /q libs
rmdir /s /q obj
xcopy /y ..\..\..\BuildFiles\Android\arm64-v8a\StaticRelease\lib[!output GUID_CID_TARGET].a %ECO_FRAMEWORK%\Eco.String1\BuildFiles\Android\arm64-v8a\StaticRelease\
xcopy /y ..\..\..\BuildFiles\Android\armeabi\StaticRelease\lib[!output GUID_CID_TARGET].a %ECO_FRAMEWORK%\Eco.String1\BuildFiles\Android\armeabi\StaticRelease\
xcopy /y ..\..\..\BuildFiles\Android\armeabi-v7a\StaticRelease\lib[!output GUID_CID_TARGET].a %ECO_FRAMEWORK%\Eco.String1\BuildFiles\Android\armeabi-v7a\StaticRelease\
xcopy /y ..\..\..\BuildFiles\Android\mips\StaticRelease\lib[!output GUID_CID_TARGET].a %ECO_FRAMEWORK%\Eco.String1\BuildFiles\Android\mips\StaticRelease\
xcopy /y ..\..\..\BuildFiles\Android\mips64\StaticRelease\lib[!output GUID_CID_TARGET].a %ECO_FRAMEWORK%\Eco.String1\BuildFiles\Android\mips64\StaticRelease\
xcopy /y ..\..\..\BuildFiles\Android\x86\StaticRelease\lib[!output GUID_CID_TARGET].a %ECO_FRAMEWORK%\Eco.String1\BuildFiles\Android\x86\StaticRelease\
xcopy /y ..\..\..\BuildFiles\Android\x86_64\StaticRelease\lib[!output GUID_CID_TARGET].a %ECO_FRAMEWORK%\Eco.String1\BuildFiles\Android\x86_64\StaticRelease\
pause
