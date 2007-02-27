# Microsoft Developer Studio Project File - Name="osgWrapper osgUtil" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=osgWrapper osgUtil - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "wrapper_osgUtil.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "wrapper_osgUtil.mak" CFG="osgWrapper osgUtil - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "osgWrapper osgUtil - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "osgWrapper osgUtil - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "osgWrapper osgUtil - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../../../bin/$(PlatformName)"
# PROP Intermediate_Dir "$(PlatformName)/$(ConfigurationName)"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
F90=df.exe
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "../../../include" /I "../../../../OpenThreads/include" /I "../../../../3rdParty/include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_CRT_SECURE_NO_DEPRECATE" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 opengl32.lib OpenThreadsWin32.lib  /nologo /dll /debug /machine:I386 /nodefaultlib:"LIBC" /opt:ref /opt:icf /out:"$(OutDir)/osgwrapper_osgUtil.dll" /implib:"../../../lib/$(PlatformName)/osgwrapper_osgUtil.lib" /libpath:"../../../lib/$(PlatformName)" /libpath:"../../../../OpenThreads/lib/$(PlatformName)" /libpath:"../../../../3rdParty/lib/$(PlatformName)" /libpath:"../../../../3rdParty/lib"
# SUBTRACT LINK32 /nodefaultlib

!ELSEIF  "$(CFG)" == "osgWrapper osgUtil - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../../../bin/$(PlatformName)"
# PROP Intermediate_Dir "$(PlatformName)/$(ConfigurationName)"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
F90=df.exe
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /vmg /GR /GX /Zi /Od /I "../../../include" /I "../../../../OpenThreads/include" /I "../../../../3rdParty/include" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "WIN32" /D "_DEBUG" /D "_CRT_SECURE_NO_DEPRECATE" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 opengl32.lib OpenThreadsWin32d.lib  /nologo /dll /debug /machine:I386 /nodefaultlib:"LIBC" /out:"$(OutDir)/osgwrapper_osgUtild.dll" /pdbtype:sept /implib:"../../../lib/$(PlatformName)/osgwrapper_osgUtild.lib" /libpath:"../../../lib/$(PlatformName)" /libpath:"../../../../OpenThreads/lib/$(PlatformName)" /libpath:"../../../../3rdParty/lib/$(PlatformName)" /libpath:"../../../../3rdParty/lib"
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ENDIF 

# Begin Target

# Name "osgWrapper osgUtil - Win32 Release"
# Name "osgWrapper osgUtil - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\CubeMapGenerator.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\CullVisitor.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\DelaunayTriangulator.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\DisplayRequirementsVisitor.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\GLObjectsVisitor.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\HalfWayMapGenerator.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\HighlightMapGenerator.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\IntersectVisitor.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\IntersectionVisitor.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\LineSegmentIntersector.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\Optimizer.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\PlaneIntersector.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\PolytopeIntersector.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\PositionalStateContainer.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\ReflectionMapGenerator.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\RenderBin.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\RenderLeaf.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\RenderStage.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\SceneView.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\Simplifier.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\SmoothingVisitor.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\StateGraph.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\Statistics.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\TangentSpaceGenerator.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\Tessellator.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\TransformAttributeFunctor.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\TransformCallback.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\TriStripVisitor.cpp
# End Source File

# Begin Source File
SOURCE=..\..\..\src\osgWrappers\osgUtil\UpdateVisitor.cpp
# End Source File

# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project

