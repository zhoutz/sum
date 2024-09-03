set_languages("c++20")
set_warnings("all")
set_policy("run.autobuild", true)
set_policy("check.target_package_licenses", false)

add_requires("gmp","gnu-gsl")
add_packages("gmp","gnu-gsl")

target("main")
    set_kind("binary")
    add_files("main.cpp")
    -- set_optimize("aggressive")
    set_optimize("fastest")


target("shuo")
    set_kind("binary")
    add_files("shuo.cpp")
    -- set_optimize("aggressive")
    set_optimize("fastest")
