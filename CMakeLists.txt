# CMakeList.txt: проект CMake для explorify; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("explorify")

# Найти pkgconf из vcpkg host tools
find_program(PKG_CONFIG_EXECUTABLE
  NAMES pkgconf
  PATHS "${VCPKG_INSTALLED_DIR}/${VCPKG_HOST_TRIPLET}/tools/pkgconf"
  NO_DEFAULT_PATH
)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM REQUIRED IMPORTED_TARGET gtkmm-4.0)

link_directories(${GTKMM_LIBRARY_DIRS})
link_directories(${GTKMM_INCLUDE_DIRS})

# Добавьте источник в исполняемый файл этого проекта.

add_executable (
	explorify
	explorify.cpp
	src/presentation/views/windows/window.h
	src/presentation/views/windows/window.cpp
 "constants.h" "src/presentation/views/windows/overview_window.cpp" "src/presentation/views/widgets/Sidebar.cpp" "src/presentation/views/widgets/Sidebar.h" "src/presentation/views/widgets/SidebarParams.h")

target_link_libraries(explorify PRIVATE PkgConfig::GTKMM)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET explorify PROPERTY CXX_STANDARD 20)
endif()
