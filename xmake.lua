add_rules("mode.debug", "mode.release")

set_languages("c++20")
includes("xmake/**.lua")

add_requires("libsdl")
add_defines("SDL_MAIN_HANDLED")

modules = {
    Renderer = {
        --Packages = {"libsdl"},
        PublicPkg = {"libsdl"},
        Defines = {"SDL_MAIN_HANDLED"}
    },
    Core = {
        Deps = {"RealEngineRenderer"},
    }

}

add_includedirs("include")

for name, module in pairs(modules) do

    target("RealEngine" .. name, function()
        set_group("Modules")
        set_kind("shared")

        add_includedirs("src")
        add_defines("RE_COMPILE")

        if module.Deps then
            add_deps(table.unpack(module.Deps))
        end

        if module.Packages then
            add_packages(table.unpack(module.Packages))
        end

        if module.PublicPkg then
            for _, pkg in ipairs(module.PublicPkg) do
                add_packages(pkg, {public = true})
            end
        end

        if module.Defines then
            add_defines(table.unpack(module.Defines))
        end

        add_files("src/RealEngine/" .. name .. "/**.cpp")
        add_headerfiles("include/(RealEngine/" .. name .. "/**.h)")


    end)

end

--target("RealEngine")
--    set_kind("binary")
--
--    add_includedirs("src")
--    add_includedirs("include")
--
--    add_files("src/**.cpp")
--    add_headerfiles("include/**.h")

target("Tests")
    set_kind("binary")

    -- add_includedirs("tests")
    add_files("tests/**.cpp")

    for name, module in pairs(modules) do
        add_deps("RealEngine" .. name)
    end

--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro definition
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

