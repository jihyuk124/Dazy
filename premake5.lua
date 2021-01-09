require "premake/Defaults"
require "premake/Dazy"
require "premake/Sandbox"
require "premake/ThirdParty"
require "premake/Utils"

include "premake/premake_customization/solution_items.lua"

workspace "Dazy"
	platforms( get_platforms() )
	configurations { "Debug", "Release" }

	solution_items
	{
        ".editorconfig",
    }

group "Dependencies"
	add_third_party("glfw")
group ""

add_dazy()
add_sandbox()
