-- defined at the end of the file
local headerTemplate, sourceTemplate

local projectName = "RealEngine";
local namespace = "Re";

task("create-class")

set_menu({
	-- Settings menu usage
	usage = "xmake create-class [options] name",
	description = "Helper for class creation",
	options =
	{
		-- Set k mode as key-only bool parameter
		{nil, "nocpp", "k", nil, "If set, will not generate .cpp" },
		{nil, "name", "v", nil, "Class name" },
		{"m", "module", "v", nil, "The module for the class"},
	}
})

on_run(function ()
	import("core.base.option")

	local classPath = option.get("name")
	if not classPath then
		os.raise("missing class name")
	end

	local module = option.get("module")

	local className = path.basename(classPath)

	local files;
	if not module then
		files = {
			{ TargetPath = path.join("include", projectName, classPath) .. ".h", Template = headerTemplate },
		}
		if not option.get("nocpp") then
			table.insert(files, { TargetPath = path.join("src", projectName, classPath) .. ".cpp", Template = sourceTemplate })
		end
	else
		files = {
			{ TargetPath = path.join("include", projectName, module, classPath) .. ".h", Template = headerTemplate },
		}
		if not option.get("nocpp") then
			table.insert(files, { TargetPath = path.join("src", projectName, module, classPath) .. ".cpp", Template = sourceTemplate })
		end
	end

	

	local replacements = {
		PROJECT_NAME = projectName,
		CLASS_NAME = className,
		CLASS_PATH = classPath,
		MODULE_NAME = module .. "/",
		NAMESPACE = namespace,
		API = namespace:upper() .. "_" .. module:upper() .. "_API",
	}

	if not module then
		replacements.MODULE_NAME = ""
	end

	for _, file in pairs(files) do
		local content = file.Template:gsub("%%([%u_]+)%%", function (kw)
			local r = replacements[kw]
			if not r then
				os.raise("missing replacement for " .. kw)
			end

			return r
		end)

		io.writefile(file.TargetPath, content)
	end
end)

headerTemplate = [[
#pragma once

#include <%PROJECT_NAME%/%MODULE_NAME%Export.h>

namespace %NAMESPACE%
{
	class %API% %CLASS_NAME%
	{
		public:
			%CLASS_NAME%() = default;
			%CLASS_NAME%(const %CLASS_NAME%&) = delete;
			%CLASS_NAME%(%CLASS_NAME%&&) = delete;
			~%CLASS_NAME%() = default;

			%CLASS_NAME%& operator=(const %CLASS_NAME%&) = delete;
			%CLASS_NAME%& operator=(%CLASS_NAME%&&) = delete;

		private:
	};
}
]]


sourceTemplate = [[
#include <%PROJECT_NAME%/%MODULE_NAME%%CLASS_PATH%.h>

namespace %NAMESPACE%
{
}
]]