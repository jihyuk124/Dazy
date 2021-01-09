function add_dazy()
	project( "Dazy" )

	kind "StaticLib"
	location "Dazy"
	staticruntime "on"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/src/Core",
		"ThirdParty/spdlog/include",
		"ThirdParty/glfw/include",
	}

	links{ "glfw" }

end