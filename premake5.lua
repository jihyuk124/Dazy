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

-- ThirdParty
	add_third_party('glfw')
	add_third_party('glad')
	add_third_party('glm')
group ''

IncludeDir = {}
IncludeDir['glfw'] = 'ThirdParty/glfw/include'
IncludeDir['glad'] = 'ThirdParty/glad/include'
IncludeDir['entt'] = 'ThirdParty/entt/single_include/entt'
IncludeDir['glm'] = 'ThirdParty/glm/glm'

project 'Dazy'
	location 'Dazy'
	kind 'StaticLib'
	language 'C++'
	buildoptions '/utf-8'

	files
	{
		'%{prj.name}/src/**.h',
		'%{prj.name}/src/**.cpp',
	}

	includedirs
	{
		--'%{prj.name}/src',
		'%{prj.name}/src/Core',
		'ThirdParty/spdlog/include',
		'ThirdParty/spdlog/include/spdlog/fmt',
		'%{IncludeDir.glfw}',
		'%{IncludeDir.glad}',
		'%{IncludeDir.entt}',
		'%{IncludeDir.glm}',
	}

	links(third_party_libraries)

	filter 'system:windows'
		cppdialect 'C++17'
		systemversion 'latest'

		defines
		{
			'GLFW_INCLUDE_NONE'
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
		'%{prj.name}/src/**.cpp',

		'%{wks}/ThirdParty/glm/glm/**.hpp',
		'%{wks}/ThirdParty/glm/glm/**.inl',
	}

	includedirs
	{
		--'%{prj.name}/src',
		'Dazy/src',
		'Dazy/src/Core',
		'ThirdParty/spdlog/include',
		'ThirdParty/spdlog/include/spdlog/fmt',
		'%{IncludeDir.entt}',
		'%{IncludeDir.glm}',
	}

	links
	{
		'Dazy'
	}

	filter 'system:windows'
		cppdialect 'C++17'
		systemversion 'latest'

	filter 'configurations:Debug'
		defines '_DEBUG'
		symbols 'On'

	filter 'configurations:Release'
		defines '_RELEASE'
		optimize 'On'