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
        add_headerfiles("include/(RealEngine/" .. name .. "/**.inl)")


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
