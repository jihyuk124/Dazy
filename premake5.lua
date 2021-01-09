require 'premake/ThirdParty'

workspace 'Dazy'
	architecture 'x64'

	configurations
	{
		'Debug',
		'Release'
	}
	
outputdir = '%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}'

targetdir ('out/bin/' .. outputdir .. '/%{prj.name}')
objdir ('out/bin-int' .. outputdir .. '/%{prj.name}')

group 'Dependencies'
	add_third_party('glfw')
	add_third_party('glad')
group ''

IncludeDir = {}
IncludeDir['glfw'] = 'ThirdParty/glfw/include'
IncludeDir['glad'] = 'ThirdParty/glad/include'

project 'Dazy'
	location 'Dazy'
	kind 'StaticLib'
	language 'C++'
	buildoptions '/utf-8'

	files
	{
		'%{prj.name}/src/**.h',
		'%{prj.name}/src/**.cpp'
	}

	includedirs
	{
		'%{prj.name}/src',
		'%{prj.name}/src/Core',
		'ThirdParty/spdlog/include',
		'%{IncludeDir.glfw}',
		'%{IncludeDir.glad}',
	}

	links
	{
		'glfw',
		'glad',
		'opengl32.lib',
	}

	filter 'system:windows'
		cppdialect 'C++17'
		staticruntime 'On'
		systemversion 'latest'

		defines
		{
			"GLFW_INCLUDE_NONE"
		}

	filter 'configurations:Debug'
		defines '_DEBUG'
		symbols 'On'

	filter 'configurations:Release'
		defines '_RELEASE'
		optimize 'On'

project 'Sandbox'
	location 'Sandbox'
	kind 'ConsoleApp'
	language 'C++'
	buildoptions '/utf-8'

	files
	{
		'%{prj.name}/src/**.h',
		'%{prj.name}/src/**.cpp'
	}

	includedirs
	{
		'ThirdParty/spdlog/include',
		'Dazy/src',
		'Dazy/src/Core',
	}

	links
	{
		'Dazy'
	}

	filter 'system:windows'
		cppdialect 'C++17'
		staticruntime 'On'
		systemversion 'latest'

	filter 'configurations:Debug'
		defines '_DEBUG'
		symbols 'On'

	filter 'configurations:Release'
		defines '_RELEASE'
		optimize 'On'