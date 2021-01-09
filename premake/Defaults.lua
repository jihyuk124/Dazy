cppdialect "C++17"

flags { "MultiProcessorCompile" }
rtti "Off"

objdir "../out/obj"
--targetdir '../out/%{iif(prj.kind == "StaticLib" or prj.kind == "SharedLib","lib","bin")}/%{cfg.platform}/%{cfg.buildcfg}'
targetdir '../out/bin/%{cfg.platform}-%{cfg.buildcfg}'
-- warnings 'Extra'
warnings 'Default'
buildoptions { "/utf-8" }

filter "configurations:Debug"
	optimize "Off"
	symbols "On"
	defines { "_DEBUG" }

filter "configurations:Release"
	optimize "Full"
	symbols "Off"
	defines { "_RELEASE", "NDEBUG" }

filter "system:windows"
	toolset "msc"
	defines { "_CRT_SECURE_NO_WARNINGS" }
	systemversion "latest"
	staticruntime "On"

filter "system:not windows"
	toolset "gcc"

filter "system:linux"
	debugenvs { "LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../%{OUTDIR}" }
	systemversion "latest"
	staticruntime "On"

filter { }
