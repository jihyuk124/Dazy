third_party_libraries = { }

function add_third_party( name )
	local module_path = path.join( "ThirdParty", name..".lua" )
	local dofunc      = dofile(  module_path )

	group "ThirdParty"
	project( name )

	kind "StaticLib"
	location "build"

	pcall( dofunc )

	table.insert( third_party_libraries, name )
end